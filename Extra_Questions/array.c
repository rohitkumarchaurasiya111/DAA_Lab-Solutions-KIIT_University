#include <stdio.h>
int main()
{
    printf("Enter the size of array: ");
    int n;
    scanf("%d", &n);
    int arr[n];

    // Taking array elements
    printf("Enter array elements: ");
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i]; // Sum of array elements
    }
    printf("Sum of Array Elements are: %d", sum);
    printf("\n");

    // Printing array elements
    printf("Array elements are: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // // Printing array in reverse
    // printf("Array Elements in reverse are: ");
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     printf("%d ", arr[i]);
    // }
    // printf("\n");

    //Reversing the array
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[n-i-1] = arr[i];
    }
    printf("Reversed array is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ",temp[i]);
    }
    
    
}