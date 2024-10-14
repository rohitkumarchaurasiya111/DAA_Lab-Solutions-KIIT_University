// WAP to create a file called emp.txt and store information about a person

#include <stdio.h>
int main()
{
    FILE *ptr;
    char name[20];
    int age;
    int salary;

    ptr = fopen("Emp.txt", "w");
    if (ptr == NULL)
    {
        printf("File Unable to open");
    }
    else
    {
        printf("Enter Name of a person: ");
        scanf(" %s", &name);
        fputs(name, ptr);
        printf("Enter Age: ");
        scanf("%d", &age);
        fprintf(ptr, "Age is: %d\n", age);
        printf("Enter Salary: ");
        scanf("%d", &salary);
        fprintf(ptr, "Salary is: %d\n", salary);
    }
}