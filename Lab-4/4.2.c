/* Write a program to perform binary search in an array */
#include <stdio.h>
#include <stdlib.h>
int search(int numbers[], int k, int n)
{
    int start = 0;
    int end = n - 1;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (k == numbers[mid])
        {
            return mid;
        }
        else if (k < numbers[mid])
        {
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return -1;
}
void main()
{
    int n;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("The elements of the array are:");
    for (int i = 0; i < n; i++)
    {
        printf("%d  ", arr[i]);
    }
    printf("\n");
    int key;
    printf("Enter the element you want to search:");
    scanf("%d", &key);
    int b = search(arr, key, n);
    if (b != -1)
    {
        printf("The element was found at index:%d", b);
    }
    else
    {
        printf("The element was not found.");
    }
}