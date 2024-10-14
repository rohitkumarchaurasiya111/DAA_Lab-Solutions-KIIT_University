package Sorting_Algorithm;

//Quick Sort Algorithm 

//Author - Rohit Kumar Chaurasiya
//Time - 2024/07/19 7:51pm

//Here, We First choose the pivot element (mostly the last element is choosed) and now we keep all the numbers smaller to pivot element in left side of pivot and the numbers bigger than pivot to the right side 
//Then, We apply quick sorting to left side - quick_sort(start, pivot-1)
//And, Right side - quick_sort(pivot+1, end)

//The Function which keeps the element smaller to left and bigger to right
// It takes a pointer let i = start - 1 and a loop iterates throught the array, if arr[j] < pivot then i++ and swap the variable. This function returns i++ (pivot element index) at the end.

public class Quick_Sort {

    public static void main(String[] args) {
        int arr[] = { 9, 0, -8, 3, 99, -11, 8, 9 };
        quick_sorting(arr, 0, arr.length - 1);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    //Function - it divides the array on the basis of pivot element index 
    public static void quick_sorting(int arr[], int start, int end) {
        if (start >= end) {
            return;
        }
        int pivot_index = end;
        pivot_index = sorting(arr, start, pivot_index, end);
        quick_sorting(arr, start, pivot_index - 1);
        quick_sorting(arr, pivot_index + 1, end);

    }

    //It keeps all the no. less than pivot at left of pivot
    public static int sorting(int arr[], int start, int pivot_index, int end) {
        int i = start - 1;
        for (int j = start; j <= end; j++) {
            if (arr[j] <= arr[pivot_index]) {
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        return i;
    }
}
//Time Complexity - O(n.Logn) on average case and on worst case it is O(n^2)  
//Space Complexity - O(1)