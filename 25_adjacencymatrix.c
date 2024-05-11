// 25. Implement adjacency matrix representation of a Graph.

#include <stdio.h>
#include <stdbool.h>

#define MAX_VERTICES 10

// Structure to represent a graph
typedef struct
{
    int vertices;
    bool adjMatrix[MAX_VERTICES][MAX_VERTICES];
} Graph;

// Function to initialize the graph
void initGraph(Graph *g, int vertices)
{
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            g->adjMatrix[i][j] = false;
        }
    }
}

// Function to add an edge to the graph
void addEdge(Graph *g, int source, int destination)
{
    if (source >= 0 && source < g->vertices && destination >= 0 && destination < g->vertices)
    {
        g->adjMatrix[source][destination] = true;
        // For undirected graph uncomment the following line
        // g->adjMatrix[destination][source] = true;
    }
    else
    {
        printf("Invalid vertex!\n");
    }
}

// Function to display the adjacency matrix representation of the graph
void displayGraph(Graph *g)
{
    printf("Adjacency Matrix Representation:\n");
    for (int i = 0; i < g->vertices; i++)
    {
        for (int j = 0; j < g->vertices; j++)
        {
            printf("%d ", g->adjMatrix[i][j] ? 1 : 0);
        }
        printf("\n");
    }
}

int main()
{
    Graph g;
    int vertices, edges, source, destination;

    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &vertices);

    initGraph(&g, vertices);

    printf("Enter the number of edges in the graph: ");
    scanf("%d", &edges);

    printf("Enter the edges (source destination):\n");
    for (int i = 0; i < edges; i++)
    {
        scanf("%d %d", &source, &destination);
        addEdge(&g, source, destination);
    }

    displayGraph(&g);

    return 0;
}

/*
Enter the number of vertices in the graph: 4
Enter the number of edges in the graph: 4
Enter the edges (source destination):
0 1
1 2
2 3
3 0
Adjacency Matrix Representation:
0 1 0 0
0 0 1 0
0 0 0 1
1 0 0 0
*/
