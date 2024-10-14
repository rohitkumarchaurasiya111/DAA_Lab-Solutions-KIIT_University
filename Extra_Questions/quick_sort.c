#include <stdio.h>
int partition(int arr[], int si, int ei)
{
    int pivot = arr[ei];
    int i = si - 1;
    for (int j = si; j < ei; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
    }
    i++;
    int temp = pivot;
    arr[ei] = arr[i];
    arr[i] = pivot;
    return i;
}
void sort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int pivot = partition(arr, si, ei);
    sort(arr, si, pivot - 1);
    sort(arr, pivot + 1, ei);
}
int main()
{
    int arr[] = {5, 2, -1, 0, 9, 100, 66, 3, 2};
    int n = 9;
    sort(arr, 0, n - 1);
    printf("Array after sorting is: ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}