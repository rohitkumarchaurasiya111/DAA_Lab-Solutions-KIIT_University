#include <stdio.h>
// Merge Sort

// Author - Rohit Kumar Chaurasiya
//  Time - 2024/07/18 11:30pm

// Here, We find break the array in two parts from middle and continue on breaking recursively until the smallest array is obtained
// Then, We MergeSort the left and right part
// Then, We marge both left and right part in temp array with size (left.length + right.length) using two pointers i and j which compares between both part and merge them into sorted order.

// 1. Find mid-point
// 2. Break the array into smallest possible size using midpoint - break(left) , break(right)
// 3. Merge the parts in shorted order

// Function :- Breaks the array in shortest part and then send to merge function

void merge_arr(int arr[], int start, int mid, int end);
void merge_sorting_algorithm(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = start + (end - start) / 2;
    merge_sorting_algorithm(arr, start, mid);
    merge_sorting_algorithm(arr, mid + 1, end);

    merge_arr(arr, start, mid, end);
}

// Function :- Merge the arrays using two pointer i and j and a temporary array
void merge_arr(int arr[], int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    // These two pointers i and j helps to iterate throught the arrays and merge the arrays in shorted order

    int temp_arr[end - start + 1]; // Temp array of size (end-start + 1)
    int temp_arr_length = end - start + 1;
    int k = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp_arr[k] = arr[i];
            i++;
        }
        else
        {
            temp_arr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp_arr[k] = arr[i];
        k++;
        i++;
    }

    while (j <= end)
    {
        temp_arr[k] = arr[j];
        k++;
        j++;
    }

    for (int k2 = 0; k2 < temp_arr_length; k2++)
    {
        arr[start++] = temp_arr[k2];
    }
}
int main()
{
    {
        int arr[] = {9, 0, -8, 3, 99, -11, 8, 9};
        int arr_length = 8;
        merge_sorting_algorithm(arr, 0, arr_length - 1);
        for (int i = 0; i < arr_length; i++)
        {
            printf("%d ",arr[i] );
        }
    }
}

// Time Complexity - O(n.logn) & Space Complexity - O(n)
