// Given an array arr[] of size N, find the prefix sum of the array. A prefix sum array is another array prefixSum[] of the same size, such that the value of prefixSum[i] is arr[0] + arr[1] + arr[2] . . . arr[i].

// Input Array: 	3 	4 	5 	1	 2
// Output Array: 	3 	7 	12 	13 	15

#include <stdio.h>
void operation(int arr[], int result[], int n);
int main()
{
    printf("Enter size of Arr: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    printf("Enter Array Elements: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int result[n];
    operation(arr, result, n);
    printf("The Result is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", result[i]);
    }
}

void operation(int arr[], int result[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j <= i; j++)
        {
            sum += arr[j];
        }
        result[i] = sum;
    }
}