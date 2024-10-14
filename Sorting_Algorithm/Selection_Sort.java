package Sorting_Algorithm;
//Selection Sort 

// Author - Rohit Kumar Chaurasiya
// Time :- 2024/07/18 10:37pm

//Here, We select the smallest number among the all and send it to the initial position 

public class Selection_Sort {
    public static void main(String args[]) {
        int arr[] = { 9, 0, -8, 3, 99, -11, 8, 9 };
        selection_sorting(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    // Function - perform selection sort
    public static void selection_sorting(int arr[]) {

        for (int i = 0; i < arr.length; i++) {
            int min = Integer.MAX_VALUE;
            int min_position = i;
            for (int j = i; j < arr.length; j++) { //This loop finds the minumum number and it's position in array
                if (arr[j] < min) {
                    min = arr[j];
                    min_position = j;
                }
            }
            // Swap the minimum value to initial place
            arr[min_position] = arr[i];
            arr[i] = min;
        }
    }
}
// Time Complexity - O(n^2) & Space Complexity - O(1)