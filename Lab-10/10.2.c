#include <stdio.h>

void increment_fitstring(char fitstring[], int n)
{
    int i = 0;
    while (i < n && fitstring[i] == '1')
    {
        fitstring[i] = '0';
        i++;
    }
    if (i < n)
        fitstring[i] = '1';
}

void decrement_fitstring(char fitstring[], int n)
{
    int i = 0;
    while (i < n && fitstring[i] == '0')
    {
        fitstring[i] = '1';
        i++;
    }
    if (i < n)
        fitstring[i] = '0';
}

int main()
{
    char fitstring[] = "101110"; // F6 + F4 + F3 + F2 = 14
    int n = 6;

    printf("Initial fitstring: %s\n", fitstring);
    increment_fitstring(fitstring, n);
    printf("After increment: %s\n", fitstring);

    decrement_fitstring(fitstring, n);
    printf("After decrement: %s\n", fitstring);

    return 0;
}