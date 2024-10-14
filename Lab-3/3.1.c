// Write a menu driven program to sort list of array elements using Merge Sort technique and calculate the execution time only to sort the elements.  Count the number of comparisons.

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void arrange(int arr[], int s, int mi, int e);

void mergeSort(int arr[], int start, int end)
{
    if (end <= start)
    {
        return;
    }

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    arrange(arr, start, mid, end);
}

void arrange(int arr[], int s, int mi, int e)
{
    int sort[e - s + 1];
    int i = s;
    int j = mi + 1;
    int k = 0;
    while (i <= mi && j <= e)
    {
        if (arr[i] < arr[j])
        {
            sort[k] = arr[i];
            i++;
        }
        else
        {
            sort[k] = arr[j];
            j++;
        }
        k++;
    }
    while (i <= mi)
    {
        sort[k] = arr[i];
        k++;
        i++;
    }
    while (j <= e)
    {
        sort[k] = arr[j];
        k++;
        j++;
    }
    for (int l = 0; l < k; l++)
    {
        arr[s] = sort[l];
        s++;
    }
}

int main()
{

    int choice;
start:

    printf("\n MAIN MENU (MERGE SORT)\n 1. Ascending Data\n 2. Descending Data\n 3. Random Data\n 4. ERROR (EXIT)\n");
    printf("Enter Choice: ");
    scanf("%d", &choice);

    FILE *ptr;
    switch (choice)
    {
    case 1:
        ptr = fopen("inAsc.txt", "r");
        break;
    case 2:
        ptr = fopen("inDesc.txt", "r");
        break;
    case 3:
        ptr = fopen("random.txt", "r");
        break;
    case 4:
        printf("\nExiting!\n");
        exit(1);
        break;
    default:
        break;
    }
    if (ptr == NULL)
    {
        printf("File cannot be opened");
    }
    else
    {
        int size;
        fscanf(ptr, "%d", &size);
        int arr[size + 1];
        printf("\nGiven Data is: ");
        for (int i = 0; i < size; i++)
        {
            fscanf(ptr, "%d", &arr[i]);
            printf("%d ", arr[i]);
        }

        clock_t start, end;
        double cpu_time_used;

        start = clock();
        mergeSort(arr, 0, size);
        end = clock();

        // Calculate the time used
        cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC * 1000000000;
        printf("\nExecution Time: %.0f nanoseconds\n", cpu_time_used);

        printf("Result is: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", arr[i]);
        }
    }
    fclose(ptr);
    goto start;
}