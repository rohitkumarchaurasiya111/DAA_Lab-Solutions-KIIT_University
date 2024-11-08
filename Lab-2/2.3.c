// Write a program in C to find GCD of two numbers using recursion. Read all pair of numbers from a file and store the result in a separate file.

#include <stdio.h>

// Function to calculate GCD using recursion (Euclidean algorithm)
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    FILE *ptr1, *ptr2;
    int num[100]; // Array to store numbers, adjust size if necessary
    int i = 0;

    // Open the input file for reading
    ptr1 = fopen("2.3.txt", "r");
    if (ptr1 == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    // Read all numbers from the file into the array
    while (fscanf(ptr1, "%d", &num[i]) != EOF)
    {
        i++;
    }
    fclose(ptr1); // Close the input file

    // Open the output file for appending the results
    ptr2 = fopen("2.3.result.txt", "a");
    if (ptr2 == NULL)
    {
        printf("Error opening result file.\n");
        return 1;
    }

    // Calculate GCD for every pair of numbers
    for (int j = 0; j < i - 1; j += 2)
    {
        int result = gcd(num[j], num[j + 1]);
        fprintf(ptr2, "The GCD of %d and %d is %d\n", num[j], num[j + 1], result);
    }

    fclose(ptr2); // Close the output file

    printf("GCD calculations completed and saved to 2.3.result.txt\n");

    return 0;
}
