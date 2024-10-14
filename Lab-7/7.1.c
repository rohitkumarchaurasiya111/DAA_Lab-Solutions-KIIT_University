#include <stdio.h>
#include <limits.h>

#define MAX 100
#define INF INT_MAX

int minDistance(int dist[], int sptSet[], int V)
{
    int min = INF, min_index;

    for (int v = 0; v < V; v++)
    {
        if (sptSet[v] == 0 && dist[v] <= min)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j)
{
    if (parent[j] == -1)
    {
        return;
    }
    printPath(parent, parent[j]);
    printf("->%d", j + 1);
}

void printSolution(int dist[], int V, int parent[], int src)
{
    printf("Source\tDestination\tCost\tPath\n");
    for (int i = 0; i < V; i++)
    {
        if (i != src)
        {
            printf("%d\t%d\t\t%d\t%d", src + 1, i + 1, dist[i], src + 1);
            printPath(parent, i);
            printf("\n");
        }
        else
        {
            printf("%d\t%d\t\t%d\t-\n", src + 1, i + 1, dist[i]);
        }
    }
}

void dijkstra(int graph[MAX][MAX], int V, int src)
{
    int dist[V];
    int sptSet[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        sptSet[i] = 0;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minDistance(dist, sptSet, V);

        sptSet[u] = 1;

        for (int v = 0; v < V; v++)
        {
            if (!sptSet[v] && graph[u][v] && dist[u] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    printSolution(dist, V, parent, src);
}

int main()
{
    int V;
    int graph[MAX][MAX];

    FILE *file = fopen("inDiAdjMat1.dat", "r");
    if (file == NULL)
    {
        printf("Error! Could not open file.\n");
        return -1;
    }

    printf("Enter the Number of Vertices: ");
    scanf("%d", &V);

    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            fscanf(file, "%d", &graph[i][j]);
        }
    }
    fclose(file);

    int src;
    printf("Enter the Source Vertex: ");
    scanf("%d", &src);

    dijkstra(graph, V, src - 1);

    return 0;
}
