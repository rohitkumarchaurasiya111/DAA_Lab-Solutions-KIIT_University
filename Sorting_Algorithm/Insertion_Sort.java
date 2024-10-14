package Sorting_Algorithm;
//Insertion Sort

//Author - Rohit Kumar Chaurasiya
//Time - 2024/07/18 10:54pm

//Here,We insert the number in sorted number list such that after insertion also it is sorted

public class Insertion_Sort {
    public static void main(String[] args) {
        int arr[] = { 9, 0, -8, 3, 99, -11, 8, 9 };
        insertion_sorting(arr);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i] + " ");
        }
    }

    // Functin - Performs the Insertion Sort
    public static void insertion_sorting(int arr[]) {

        for (int i = 1; i < arr.length; i++) {
            int num_to_insert = arr[i];

            // for (int j = i - 1; j >= 0; j--) {
            // if (arr[j] > num_to_insert) {
            // arr[j + 1] = arr[j];
            // arr[j] = num_to_insert;
            // }
            // }

            int j = i - 1;
            while (j >= 0 && num_to_insert < arr[j]) { //This loop finds the position where the num_to_insert should be placed
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = num_to_insert;
        }
    }
}
