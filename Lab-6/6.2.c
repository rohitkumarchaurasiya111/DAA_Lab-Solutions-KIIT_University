#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int u, v, w;
} Edge;

typedef struct
{
    int parent, rank;
} Subset;

int compare(const void *a, const void *b)
{
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int find(Subset subsets[], int i)
{
    if (subsets[i].parent != i)
    {
        subsets[i].parent = find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}

void union_sets(Subset subsets[], int x, int y)
{
    int xroot = find(subsets, x);
    int yroot = find(subsets, y);

    if (subsets[xroot].rank < subsets[yroot].rank)
    {
        subsets[xroot].parent = yroot;
    }
    else if (subsets[xroot].rank > subsets[yroot].rank)
    {
        subsets[yroot].parent = xroot;
    }
    else
    {
        subsets[yroot].parent = xroot;
        subsets[xroot].rank++;
    }
}

void kruskal(Edge edges[], int n, int m)
{
    qsort(edges, m, sizeof(Edge), compare);

    Subset *subsets = (Subset *)malloc(n * sizeof(Subset));
    for (int i = 0; i < n; i++)
    {
        subsets[i].parent = i;
        subsets[i].rank = 0;
    }

    Edge *result = (Edge *)malloc(n * sizeof(Edge));
    int e = 0;
    int i = 0;
    int total_weight = 0;

    while (e < n - 1 && i < m)
    {
        Edge next_edge = edges[i++];
        int x = find(subsets, next_edge.u - 1);
        int y = find(subsets, next_edge.v - 1);

        if (x != y)
        {
            result[e++] = next_edge;
            total_weight += next_edge.w;
            union_sets(subsets, x, y);
        }
    }

    printf("Edge Cost\n");
    for (int j = 0; j < e; j++)
    {
        printf("%d--%d %d\n", result[j].u, result[j].v, result[j].w);
    }
    printf("Total Weight of the Spanning Tree: %d\n", total_weight);

    free(subsets);
    free(result);
}

int main()
{
    int n, m;

    printf("Enter number of nodes and edges: ");
    scanf("%d %d", &n, &m);

    Edge *edges = (Edge *)malloc(m * sizeof(Edge));

    printf("Enter edges (u v w):\n");
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].w);
    }

    kruskal(edges, n, m);

    free(edges);
    return 0;
}
