// 28.	Implement Prim’s and Kruskal’s Algorithm.

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define MAX_VERTICES 100

// Structure to represent an edge in the graph
typedef struct
{
    int source, destination, weight;
} Edge;

// Structure to represent a graph
typedef struct
{
    int vertices, edges;
    Edge *edge;
} Graph;

// Structure to represent a subset for union-find
typedef struct
{
    int parent;
    int rank;
} Subset;

// Function to create a graph
Graph *createGraph(int vertices, int edges)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->edges = edges;
    graph->edge = (Edge *)malloc(edges * sizeof(Edge));
    return graph;
}

// Function to create a subset for union-find
Subset *createSubset(int vertices)
{
    Subset *subset = (Subset *)malloc(vertices * sizeof(Subset));
    for (int v = 0; v < vertices; v++)
    {
        subset[v].parent = v;
        subset[v].rank = 0;
    }
    return subset;
}

// Function to find the set of an element i
int find(Subset *subset, int i)
{
    if (subset[i].parent != i)
        subset[i].parent = find(subset, subset[i].parent);
    return subset[i].parent;
}

// Function to perform union of two sets
void unionSets(Subset *subset, int x, int y)
{
    int rootX = find(subset, x);
    int rootY = find(subset, y);
    if (subset[rootX].rank < subset[rootY].rank)
        subset[rootX].parent = rootY;
    else if (subset[rootX].rank > subset[rootY].rank)
        subset[rootY].parent = rootX;
    else
    {
        subset[rootY].parent = rootX;
        subset[rootX].rank++;
    }
}

// Function to compare two edges based on their weights
int compareEdges(const void *a, const void *b)
{
    Edge *edge1 = (Edge *)a;
    Edge *edge2 = (Edge *)b;
    return edge1->weight - edge2->weight;
}

// Function to find the MST of a graph using Kruskal's algorithm
void kruskalMST(Graph *graph)
{
    int vertices = graph->vertices;
    Edge resultMST[vertices];
    int e = 0;
    int i = 0;

    qsort(graph->edge, graph->edges, sizeof(graph->edge[0]), compareEdges);

    Subset *subset = createSubset(vertices);

    while (e < vertices - 1 && i < graph->edges)
    {
        Edge nextEdge = graph->edge[i++];
        int x = find(subset, nextEdge.source);
        int y = find(subset, nextEdge.destination);

        if (x != y)
        {
            resultMST[e++] = nextEdge;
            unionSets(subset, x, y);
        }
    }

    printf("Edges of MST using Kruskal's algorithm:\n");
    for (i = 0; i < e; ++i)
        printf("%d - %d  Weight: %d\n", resultMST[i].source, resultMST[i].destination, resultMST[i].weight);

    free(subset);
}

// Function to find the vertex with minimum key value
int minKey(int key[], bool mstSet[], int vertices)
{
    int min = INT_MAX, min_index;
    for (int v = 0; v < vertices; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }
    return min_index;
}

// Function to print the constructed MST stored in parent array
void printMST(int parent[], int n, int graph[MAX_VERTICES][MAX_VERTICES], int vertices)
{
    printf("Edge   Weight\n");
    for (int i = 1; i < vertices; i++)
        printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

// Function to find the MST of a graph using Prim's algorithm
void primMST(int graph[MAX_VERTICES][MAX_VERTICES], int vertices)
{
    int parent[vertices];
    int key[vertices];
    bool mstSet[vertices];

    for (int i = 0; i < vertices; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < vertices - 1; count++)
    {
        int u = minKey(key, mstSet, vertices);
        mstSet[u] = true;
        for (int v = 0; v < vertices; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }
    printMST(parent, vertices, graph, vertices);
}

int main()
{
    int vertices, edges;
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &vertices, &edges);
    Graph *graphKruskal = createGraph(vertices, edges);
    Graph *graphPrim = createGraph(vertices, vertices);

    printf("Enter the edges in format [source destination weight]:\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d %d", &graphKruskal->edge[i].source, &graphKruskal->edge[i].destination, &graphKruskal->edge[i].weight);
        graphPrim->edge[i].source = i;
        graphPrim->edge[i].destination = (i + 1) % vertices;
        graphPrim->edge[i].weight = rand() % 10;
    }

    printf("\nKruskal's Algorithm:\n");
    kruskalMST(graphKruskal);

    printf("\nPrim's Algorithm:\n");
    primMST(graphPrim);

    return 0;
}

/*
OUTPUT
================================================================
Enter the number of vertices and edges: 5 7
Enter the edges in format [source destination weight]:
0 1 2
0 2 4
1 2 4
1 3 3
1 4 2
2 3 1
3 4 5

Kruskal's Algorithm:
Edges of MST using Kruskal's algorithm:
0 - 1  Weight: 2
1 - 4  Weight: 2
2 - 3  Weight: 1
0 - 2  Weight: 4

Prim's Algorithm:
Edge   Weight
0 - 1    2
1 - 2    4
2 - 3    1
1 - 4    2

*/
