/*Aim of the program: Write a menu driven program to sort a list of elements in ascending order using Quick Sort technique. Each choice for the input data has its own disc file.  A separate output file can be used for sorted elements. After sorting display the content of the output file along with number of comparisons. Based on the partitioning position for each recursive call, conclude the input scenario is either best-case partitioning or worst-case partitioning. 
Note# 
●The worst-case behavior for quicksort occurs when the partitioning routine produces one subproblem with n-1 elements and one with 0 elements. The best-case behaviour occurred in most even possible split, PARTITION produces two subproblems, each of size no more than n/2.
●Number of elements in each input file should vary from 300 to 500 entries. 
●For ascending order: Read data from a file “inAsce.dat” having content 10 20 30 40….., Store the result in “outQuickAsce.dat”.
●For descending order: Read data from a file “inDesc.dat” having content 90 80 70 60…., Store the result in “outQuickDesc.dat”.
●For random data: Read data from a file “inRand.dat” having content 55 66 33 11 44 …, Store the result in “outQuickRand.dat”
Sample Input from file:
MAIN MENU (QUICK SORT)
1. Ascending Data
2. Descending Data
3. Random Data
4. ERROR (EXIT)

Output:
Enter option: 1
Before Sorting: Content of the input file
After Sorting: Content of the output file
Number of Comparisons: Actual
Scenario: Best or Worst-case*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparisons = 0;
int worst_case = 0;

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);
    int partitionSize = high - low + 1;

    for (int j = low; j < high; j++) {
        comparisons++;
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);

    int pivotPosition = i + 1;
    int leftSize = pivotPosition - low;
    int rightSize = high - pivotPosition;

    if (leftSize == 0 || rightSize == 0) {
        worst_case = 1;
    } else if (leftSize <= partitionSize / 2 && rightSize <= partitionSize / 2) {
        worst_case = 0;
    }

    return pivotPosition;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void readFile(const char *filename, int arr[], int *size) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    *size = 0;
    while (fscanf(file, "%d", &arr[(*size)++]) != EOF);

    (*size)--;  
    fclose(file);
}

void writeFile(const char *filename, int arr[], int size) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("Unable to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < size; i++) {
        fprintf(file, "%d ", arr[i]);
    }

    fclose(file);
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int choice;
    char inputFile[20], outputFile[20];
    int arr[500];
    int size;

    while (1) {
        printf("MAIN MENU (QUICK SORT)\n");
        printf("1. Ascending Data\n");
        printf("2. Descending Data\n");
        printf("3. Random Data\n");
        printf("4. ERROR (EXIT)\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                strcpy(inputFile, "inAsc.txt");
                strcpy(outputFile, "outQuickAsce.dat");
                break;
            case 2:
                strcpy(inputFile, "inDesc.txt");
                strcpy(outputFile, "2.outQuickDesc.dat");
                break;
            case 3:
                strcpy(inputFile, "random.txt");
                strcpy(outputFile, "2.outQuickRand.dat");
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid option!\n");
                continue;
        }

        readFile(inputFile, arr, &size);

        printf("Before Sorting: ");
        printArray(arr, size);

        comparisons = 0;
        worst_case = 0;

        quickSort(arr, 0, size - 1);

        printf("After Sorting: ");
        printArray(arr, size);

        writeFile(outputFile, arr, size);

        printf("Number of Comparisons: %d\n", comparisons);

        if (worst_case) {
            printf("Scenario: Worst-case partitioning\n");
        } else {
            printf("Scenario: Best-case partitioning\n");
        }
    }

    return 0;
}