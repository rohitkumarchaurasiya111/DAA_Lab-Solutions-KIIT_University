/* Write a program in c to find the minimum and maximum element of an array*/
#include <stdio.h>
void main()
{
    int n;
    printf("Enter the size of an array:");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    printf("The minimum element is %d.\n", min);
    printf("The maximum element is %d.\n", max);
}