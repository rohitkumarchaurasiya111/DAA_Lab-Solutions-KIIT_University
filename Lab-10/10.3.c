#include <stdio.h>

void increment(int A[], int *n)
{
    int i = 0;
    while (i < *n && A[i] == 1)
    {
        A[i] = 0;
        i++;
    }
    if (i < *n)
        A[i] = 1;
}

void reset(int A[], int n)
{
    for (int i = 0; i < n; i++)
    {
        A[i] = 0;
    }
}

void print_counter(int A[], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main()
{
    int n = 5;
    int A[5] = {0, 0, 0, 1, 0}; // 5-bit counter

    printf("Initial: ");
    print_counter(A, n);

    increment(A, &n);
    printf("After Increment: ");
    print_counter(A, n);

    increment(A, &n);
    printf("After Increment: ");
    print_counter(A, n);

    increment(A, &n);
    printf("After Increment: ");
    print_counter(A, n);

    increment(A, &n);
    printf("After Increment: ");
    print_counter(A, n);

    reset(A, n);
    printf("After Reset: ");
    print_counter(A, n);

    return 0;
}