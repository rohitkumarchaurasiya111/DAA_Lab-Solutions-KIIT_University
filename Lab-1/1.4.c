// //Write a function to ROTATE_RIGHT(p1, p2 ) right an array for first p2 elements by 1 position using EXCHANGE(p, q) function that swaps/exchanges the numbers p & q. Parameter p1 be the starting address of the array and p2 be the number of elements to be rotated.

// Input:
// Enter an array A of size N (9): 11 22 33 44 55 66 77 88 99
// Call the function ROTATE_RIGHT(A, 5)
// Output:
// Before ROTATE: 	11 22 33 44 55 66 77 88 99
// After   ROTATE: 	55 11 22 33 44 66 77 88 99
#include <stdio.h>
void ROTATE_RIGHT(int arr[], int p);
void EXCHANGE(int p, int q, int arr[]);
int main()
{
    int arr[] = {11, 22, 33, 44, 55, 66, 77, 88, 99};
    int size = 9;
    printf("\nBefore Rotation: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    ROTATE_RIGHT(arr, 0);

    printf("\nAfter Rotation: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
}

void ROTATE_RIGHT(int arr[], int p)
{
    if (p<0)
    {
        return;
    }
    
    int temp = arr[p];
    for (int i = p; i > 0; i--)
    {
        EXCHANGE(i, i - 1, arr);
    }
    arr[0] = temp;
}

void EXCHANGE(int p, int q, int arr[])
{
    arr[p] = arr[q];
}