// Binary Search using Recursion
#include <stdio.h>
int binary_search_recursion(int arr[], int key, int start, int end)
{
    if (end < start)
    {
        return -1;
    }

    int mid = end - (end - start) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }
    else if (key < arr[mid])
    {
        end = mid - 1;
    }
    else
    {
        start = mid + 1;
    }
    return binary_search_recursion(arr, key, start, end);
}
int main()
{
    int n;
    printf("Enter the size of array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the content of array: ");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("The content of array is: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\nEnter the key to search in arrya: ");
    int key;
    scanf("%d",&key);
    int index = binary_search_recursion(arr, key, 0, n - 1);
    if (index == -1)
    {
        printf("Number %d is not present", key);
    }
    else
    {
        printf("Number %d is in index %d", key, index);
    }
}
