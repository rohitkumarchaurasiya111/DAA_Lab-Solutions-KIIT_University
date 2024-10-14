// Write a program to find out the second smallest and second largest element stored in an array of n integers.
// Input: Size of the array is ‘n’ and read ‘n’ number of elements from a disc file.
// Output: Second smallest, Second largest

#include <stdio.h>
#include <limits.h>
void operations(int arr[], int n);
int main()
{
    FILE *ptr;
    ptr = fopen("1.1.txt", "r");
    if (ptr == NULL)
    {
        printf("File cannot be opened\n");
        return 1;
    }
    int size;
    fscanf(ptr, "%d", &size);
    printf("The size of Array is: %d\n", size);
    int arr[size];

    for (int i = 0; i < size; i++)
    {
        fscanf(ptr, "%d", &arr[i]);
    }

    printf("Array Elements are: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    operations(arr, size);
}

void operations(int arr[], int n)
{
    int max = INT_MIN;
    int min = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }

        if (min > arr[i])
        {
            min = arr[i];
        }
    }
    printf("Largest Element is: %d\n", max);
    printf("Smallest Element is: %d\n", min);

    int second_max = INT_MIN;
    int second_min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if (second_max < arr[i] && arr[i] != max)
        {
            second_max = arr[i];
        }
        if (second_min > arr[i] && arr[i] != min)
        {
            second_min = arr[i];
        }
    }

    printf("Second Largest Element is: %d\n", second_max);
    printf("Second Smallest Element is: %d\n", second_min);
}