#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX 100

int n;
int graph[MAX][MAX];
int parent[MAX];
int key[MAX];
int mstSet[MAX];

int minKey()
{
    int min = INT_MAX, min_index;

    for (int v = 0; v < n; v++)
        if (mstSet[v] == 0 && key[v] < min)
            min = key[v], min_index = v;

    return min_index;
}

void printMST()
{
    int totalWeight = 0;
    printf("Cost Adjacency Matrix of the Minimum Spanning Tree:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                printf("0 ");
            else if (parent[i] == j || parent[j] == i)
                printf("%d ", graph[i][j]);
            else
                printf("0 ");
        }
        printf("\n");
    }

    for (int i = 1; i < n; i++)
        totalWeight += graph[i][parent[i]];

    printf("Total Weight of the Spanning Tree: %d\n", totalWeight);
}

void primMST(int s)
{
    for (int i = 0; i < n; i++)
        key[i] = INT_MAX, mstSet[i] = 0;

    key[s] = 0;
    parent[s] = -1;
    for (int count = 0; count < n - 1; count++)
    {
        int u = minKey();

        mstSet[u] = 1;

        for (int v = 0; v < n; v++)
            if (graph[u][v] && mstSet[v] == 0 && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }

    printMST();
}

int main()
{
    FILE *file;
    file = fopen("inUnAdjMat.dat", "r");

    if (file == NULL)
    {
        printf("Error! Could not open file\n");
        exit(1);
    }

    printf("Enter the Number of Vertices: ");
    scanf("%d", &n);

    int s;
    printf("Enter start vertex: ");
    scanf("%d", &s);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            fscanf(file, "%d", &graph[i][j]);

    fclose(file);

    primMST(s - 1);

    return 0;
}
