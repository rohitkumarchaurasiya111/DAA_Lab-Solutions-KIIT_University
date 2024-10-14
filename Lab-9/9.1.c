#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

void printPath(int path[MAX][MAX], int u, int v)
{
    if (path[u][v] == -1)
    {
        printf("No path exists between %d and %d\n", u + 1, v + 1);
        return;
    }
    if (u != v)
        printf("%d", u + 1);
    while (u != v)
    {
        u = path[u][v];
        printf("-->%d", u + 1);
    }
    printf("\n");
}

void floydWarshall(int graph[MAX][MAX], int n)
{
    int dist[MAX][MAX], path[MAX][MAX];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (graph[i][j] != 0)
                dist[i][j] = graph[i][j];
            else
                dist[i][j] = (i == j) ? 0 : INF;

            if (graph[i][j] != 0 && i != j)
                path[i][j] = j;
            else
                path[i][j] = -1;
        }
    }

    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dist[i][k] != INF && dist[k][j] != INF && dist[i][k] + dist[k][j] < dist[i][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }

    printf("Shortest Path Weight Matrix:\n");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                printf("INF\t");
            else
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    int u, v;
    printf("Enter the source and destination vertex: ");
    scanf("%d %d", &u, &v);
    u--;
    v--;

    printf("Shortest Path from vertex %d to vertex %d: ", u + 1, v + 1);
    printPath(path, u, v);

    if (dist[u][v] == INF)
        printf("No path exists between %d and %d\n", u + 1, v + 1);
    else
        printf("Path weight: %d\n", dist[u][v]);
}

int main()
{
    int n;
    int graph[MAX][MAX];

    FILE *file = fopen("inDiAdjMat2.dat", "r");
    if (file == NULL)
    {
        printf("Error! Could not open file.\n");
        return -1;
    }

    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);

    floydWarshall(graph, n);

    return 0;
}
