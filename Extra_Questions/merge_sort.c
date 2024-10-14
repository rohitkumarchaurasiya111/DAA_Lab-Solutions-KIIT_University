#include <stdio.h>
void merge(int arr[], int si, int mid, int ei);

void sort(int arr[], int si, int ei)
{
    if (si >= ei)
    {
        return;
    }
    int mid = (si + ei) / 2;
    sort(arr, si, mid);
    sort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
}

void merge(int arr[], int si, int mid, int ei)
{
    int temp[ei - si + 1];
    int k = 0;
    int i = si;
    int j = mid + 1;
    while (i <= mid && j <= ei)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= ei)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int k1 = 0; k1 < k; k1++)
    {
        arr[si] = temp[k1];
        si++;
    }
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