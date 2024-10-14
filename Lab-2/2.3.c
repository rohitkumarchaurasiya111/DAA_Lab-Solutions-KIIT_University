// Write a program in C to find GCD of two numbers using recursion. Read all pair of numbers from a file and store the result in a separate file.

#include <stdio.h>

int gcd(int a, int b)
{
    if (a <= b)
    {
        for (int i = a; i > 0; i--)
        {
            if (b % i == 0 && a % i == 0)
            {
                return i;
            }
        }
    }
    else
    {
        gcd(b, a);
    }
    return 1;
}

int main()
{
    FILE *ptr1;
    ptr1 = fopen("2.3.txt", "r");
    int i = 8;
    // fscanf(ptr1, "%d", &i);
    int num[i];

    for (int j = 0; j < i; j++)
    {
        fscanf(ptr1, "%d", &num[i]);
    }
    for(int j=0;j<i;j++){
        printf("%d ",num[i]);
    }

    FILE *ptr2;
    ptr2 = fopen("2.3.result.txt", "a");
    for (int j = 0; j < i / 2; j = j + 2)
    {
        int result = gcd(num[i], num[i + 1]);
        fprintf(ptr2, "The GCD of %d and %d is %d\n", num[i], num[i + 1], result);
    }

}