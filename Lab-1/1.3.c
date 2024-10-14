// Write a program to read ‘n’ integers from a disc file that must contain some duplicate values and store them into an array. Perform the following operations on the array.
//  a)Find out the total number of duplicate elements.
//  b)Find out the most repeating element in the array.

// Input:
// Enter how many numbers you want to read from file: 15

// Output:
// The content of the array: 10 40 35 47 68 22 40 10 98 10 50 35 68 40 10
// Total number of duplicate values = 4
// The most repeating element in the array = 10

#include <stdio.h>
void operation(int arr[], int size);
int main()
{
    int size;
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &size);
    int arr[size];
    FILE *ptr;
    ptr = fopen("1.3.txt", "r");
    if (ptr == NULL)
    {
        printf("File cannot be Opened\n");
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        fscanf(ptr, "%d", &arr[i]);
    }
    printf("The content of array is: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    operation(arr, size);
}

void operation(int arr[], int size)
{
    int count[size];
    for (int i = 0; i < size; i++)
    {
        int counts = 0;
        for (int j = i; j < size; j++)
        {
            if (arr[i] == arr[j])
            {
                counts++;
            }
        }
        count[i] = counts;
    }

    int duplicates = 0;
    int max_dup = 0;
    for (int i = 0; i < size; i++)
    {
        if (count[i] == 2)
        {
            duplicates++;
        }
        if (count[i] > max_dup)
        {
            max_dup = i;
        }
    }
    int max_dup_arr;
    printf("\nTotal number of duplicate values: %d\n", duplicates);
    printf("The most repeating element in the array: %d\n", arr[max_dup]);
}