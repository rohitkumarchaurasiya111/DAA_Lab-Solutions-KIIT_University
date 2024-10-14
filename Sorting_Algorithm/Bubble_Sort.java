package Sorting_Algorithm;

//Bubble Sort Algorithm
//Author - Rohit Kumar Chaurasiy
//Date - 2024/07/18 10:22 pm 
//Sorting using the Bubble Sort - The largest element goes to the end by swapping with it's adjacent elements as similar to the largest bubble in boining water goes upward first
public class Bubble_Sort {
    public static void main(String args[]) {
        int arr[] = { 9, 0, -8, 3, 99, -11, 8, 9 };
        bubble_sorting(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    // This function implements the bubble sort algorithm
    public static void bubble_sorting(int arr[]) {

        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) { // Does the swapping so that largest element goes to the last
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }

            }
        }
    }
}
// Time Complexity - O(n^2) & Space Complexity - O(1)