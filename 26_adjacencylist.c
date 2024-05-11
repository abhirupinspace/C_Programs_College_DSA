26.	Implement adjacency list representation of a Graph

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the adjacency list
typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

// Structure to represent a graph
typedef struct
{
    int vertices;
    Node **adjacencyList;
} Graph;

// Function to create a new node
Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize the graph
Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (Node **)malloc(vertices * sizeof(Node *));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjacencyList[i] = NULL;
    }
    return graph;
}

// Function to add an edge to the graph
void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;

    // Uncomment the following code for undirected graph
    // newNode = createNode(src);
    // newNode->next = graph->adjacencyList[dest];
    // graph->adjacencyList[dest] = newNode;
}

// Function to display the adjacency list representation of the graph
void displayGraph(Graph *graph)
{
    printf("Adjacency List Representation:\n");
    for (int i = 0; i < graph->vertices; i++)
    {
        printf("Vertex %d -> ", i);
        Node *temp = graph->adjacencyList[i];
        while (temp)
        {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int vertices = 5;
    Graph *graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);
    displayGraph(graph);
    return 0;
}

/*
Adjacency List Representation:
Vertex 0 -> 4 1
Vertex 1 -> 4 3 2
Vertex 2 -> 3
Vertex 3 -> 4
Vertex 4 -> */
