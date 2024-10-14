// Define a struct person as follows: 
// struct person
// {
// 	int id;
// 	char *name;
// 	int age;
// 	int height;
// 	int weight;
// }; 
// Write a menu driven program to read the data of ‘n’ students from a file and store them in a dynamically allocated array of struct person. Implement the min-heap or max-heap and its operations based on the menu options. 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct person {
    int id;
    char *name;
    int age;
    int height;
    int weight;
};


void swap(struct person *a, struct person *b) {
    struct person temp = *a;
    *a = *b;
    *b = temp;
}


void heapify_min_age(struct person arr[], int n, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].age < arr[smallest].age)
        smallest = left;

    if (right < n && arr[right].age < arr[smallest].age)
        smallest = right;

    if (smallest != i) {
        swap(&arr[i], &arr[smallest]);
        heapify_min_age(arr, n, smallest);
    }
}


void heapify_max_weight(struct person arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].weight > arr[largest].weight)
        largest = left;

    if (right < n && arr[right].weight > arr[largest].weight)
        largest = right;

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify_max_weight(arr, n, largest);
    }
}


void build_min_heap_age(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_min_age(arr, n, i);
    }
}


void build_max_heap_weight(struct person arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify_max_weight(arr, n, i);
    }
}


int read_data(struct person **arr) {
    FILE *file = fopen("students.txt", "r");
    if (file == NULL) {
        printf("Error: Cannot open file.\n");
        return -1;
    }

    int n;
    fscanf(file, "%d", &n);
    *arr = (struct person *)malloc(n * sizeof(struct person));

    for (int i = 0; i < n; i++) {
        (*arr)[i].name = (char *)malloc(50 * sizeof(char));
        fscanf(file, "%d %s %d %d %d", &(*arr)[i].id, (*arr)[i].name, &(*arr)[i].age, &(*arr)[i].height, &(*arr)[i].weight);
    }

    fclose(file);
    return n;
}


void display_weight_of_youngest(struct person arr[], int n) {
    build_min_heap_age(arr, n);
    printf("Weight of the youngest person: %.2f kg\n", arr[0].weight * 0.453592);  // Convert pounds to kg
}


void insert_min_heap(struct person **arr, int *n, struct person new_person) {
    *arr = (struct person *)realloc(*arr, (*n + 1) * sizeof(struct person));
    (*arr)[*n] = new_person;
    (*n)++;

    for (int i = *n / 2 - 1; i >= 0; i--) {
        heapify_min_age(*arr, *n, i);
    }
}


void delete_oldest_person(struct person **arr, int *n) {
    if (*n == 0) {
        printf("Heap is empty.\n");
        return;
    }

    (*arr)[0] = (*arr)[*n - 1];
    (*n)--;
    *arr = (struct person *)realloc(*arr, (*n) * sizeof(struct person));

    heapify_min_age(*arr, *n, 0);
}

int main() {
    struct person *students = NULL;
    int n = 0, choice;
    struct person new_person;

    do {
        printf("\nMAIN MENU (HEAP)\n");
        printf("1. Read Data\n");
        printf("2. Create a Min-heap based on age\n");
        printf("3. Create a Max-heap based on weight\n");
        printf("4. Display weight of the youngest person\n");
        printf("5. Insert a new person into the Min-heap\n");
        printf("6. Delete the oldest person\n");
        printf("7. Exit\n");
        printf("Enter option: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                n = read_data(&students);
                if (n != -1) {
                    printf("Data read successfully. Total students: %d\n", n);
                }
                break;
            case 2:
                build_min_heap_age(students, n);
                printf("Min-heap created based on age.\n");
                break;
            case 3:
                build_max_heap_weight(students, n);
                printf("Max-heap created based on weight.\n");
                break;
            case 4:
                display_weight_of_youngest(students, n);
                break;
            case 5:
                new_person.name = (char *)malloc(50 * sizeof(char));
                printf("Enter ID: ");
                scanf("%d", &new_person.id);
                printf("Enter Name: ");
                scanf("%s", new_person.name);
                printf("Enter Age: ");
                scanf("%d", &new_person.age);
                printf("Enter Height: ");
                scanf("%d", &new_person.height);
                printf("Enter Weight: ");
                scanf("%d", &new_person.weight);
                insert_min_heap(&students, &n, new_person);
                printf("New person inserted into Min-heap.\n");
                break;
            case 6:
                delete_oldest_person(&students, &n);
                printf("Oldest person deleted from Min-heap.\n");
                break;
            case 7:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid option! Please try again.\n");
                break;
        }
    } while (choice != 7);

    
    for (int i = 0; i < n; i++) {
        free(students[i].name);
    }
    free(students);

    return 0;
}
