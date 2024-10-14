#include <stdio.h>
int main()
{
    printf("Enter size of Array 1: ");
    int n1;
    scanf("%d", &n1);
    int arr1[n1];

    printf("Enter array1: ");
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &arr1[i]);
    }

    printf("Enter size of Array 2: ");
    int n2;
    scanf("%d", &n2);
    int arr2[n2];

    printf("Enter array2: ");
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &arr2[i]);
    }

    int arr[n1 + n2];
    int i = 0;
    for (; i < n1; i++)
    {
        arr[i] = arr1[i];
    }
    for (int j = 0; j < n2; j++)
    {
        arr[i++] = arr2[j];
    }
    printf("\nConcatenated Array is: ");
    for (int i = 0; i < n1 + n2; i++)
    {
        printf("%d ", arr[i]);
    }
}