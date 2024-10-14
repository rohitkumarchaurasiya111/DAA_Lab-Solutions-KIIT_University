#include <stdio.h>
#include <limits.h>

void printOptimalParens(int s[][100], int i, int j)
{
    if (i == j)
        printf("A%d", i + 1);
    else
    {
        printf("(");
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[100];                   
    int m[100][100], s[100][100];

    printf("Enter dimensions (row and column) for the matrices:\n");
    for (int i = 0; i < n; i++)
    {
        int row, col;
        printf("Enter row and column size of A%d: ", i + 1);
        scanf("%d %d", &row, &col);

        if (i == 0)
        {
            p[i] = row; 
        }
        p[i + 1] = col; 
    }

    for (int i = 0; i < n; i++)
    {
        m[i][i] = 0;
    }

    for (int L = 2; L <= n; L++)
    { 
        for (int i = 0; i < n - L + 1; i++)
        {
            int j = i + L - 1;
            m[i][j] = INT_MAX; 
            for (int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nM Table:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i > j)
                printf("0\t");
            else
                printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    printf("\nS Table:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
                printf("0\t");
            else
                printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    printf("\nOptimal parenthesization: ");
    printOptimalParens(s, 0, n - 1);
    printf("\n");

    printf("The optimal ordering of the given matrices requires %d scalar multiplications.\n", m[0][n - 1]);

    return 0;
}
