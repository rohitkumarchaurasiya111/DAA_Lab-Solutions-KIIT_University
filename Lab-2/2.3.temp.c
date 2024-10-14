#include <stdio.h>
int gcd(int n1, int n2, int a)
{
    if (a == 1)
    {
        return 1;
    }
    if (n1 % a == 0 && n2 % a == 0)
    {
        return a;
    }
    return gcd(n1, n2, a - 1);
}
void main()
{
    FILE *file;
    int n;
    file = fopen("2.3.txt", "r");
    if (file == NULL)
    {
        printf("Error:Could not open file.\n");
        return;
    }
    fscanf(file, "%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    fclose(file);
    file = fopen("2.3.result.txt", "w");
    fprintf(file, " ");
    fclose(file);
    file = fopen("2.3.result.txt", "a");
    if (file == NULL)
    {
        printf("Error:Could not open file.\n");
        return;
    }
    for (int i = 0; i < n; i = i + 2)
    {
        if (arr[i] > arr[i + 1])
        {
            int n = gcd((int)arr[i], (int)arr[i + 1], arr[i + 1]);
        }
        else
        {
            int n = gcd((int)arr[i], (int)arr[i + 1], arr[i]);
        }
        fprintf(file, "The gcd of %d and %d is '%d'.\n", arr[i], arr[i + 1], n);
        printf("%d\n", n);
    }
    printf("\n");
}