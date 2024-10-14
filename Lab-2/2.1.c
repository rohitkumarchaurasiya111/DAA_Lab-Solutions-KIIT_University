// Write a program in C to convert the first ‘n’ decimal numbers of a disc file to binary using recursion. Store the binary value in a separate disc file.
#include <stdio.h>
#include <Math.h>
void binary_convert(int num);
int binary_converted(int num);

int main()
{
    FILE *ptr;
    ptr = fopen("2.1.txt", "r");
    if (ptr == NULL)
    {
        printf("File cannot be opened");
        return 0;
    }
    int size = 3;
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        fscanf(ptr, "%d", &arr[i]);
    }
    fclose(ptr);
    FILE *ptr2;
    ptr2 = fopen("2.1.result.txt", "a");
    if (ptr2 == NULL)
    {
        printf("File cannot be opened\n");
        return 0;
    }

    for (int i = 0; i < size; i++)
    {
        // binary_convert(arr[i]);
        int result = binary_converted(arr[i]);
        printf("%d  ", result);
        fprintf(ptr2, "The binary of %d is %d\n", arr[i], result);
    }
    fclose(ptr2);
}

void binary_convert(int num)
{
    int i = 0;
    int arr[8];
    int converted = 0;
    int number = num;
    while (num > 0)
    {
        arr[i] = num % 2;
        num = num / 2;
        i++;
    }

    printf("Binary of %d is ", number);
    for (int j = i - 1; j >= 0; j--)
    {
        printf("%d", arr[j]);
    }
    printf("\n");
}

int binary_converted(int num)
{
    if (num < 2)
    {
        return (num % 2 == 0) ? 0 : 1;
    }
    int digit = num % 2;
    int result = digit + 10 * binary_converted(num / 2);
    return result;
}