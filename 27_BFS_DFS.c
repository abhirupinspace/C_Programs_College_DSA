// 27.	Implement BFS and DFS algorithms.

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
    int vertex;
    struct Node *next;
} Node;

typedef struct
{
    int vertices;
    Node **adjacencyList;
    bool *visited;
} Graph;

Node *createNode(int v)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

Graph *createGraph(int vertices)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->vertices = vertices;
    graph->adjacencyList = (Node **)malloc(vertices * sizeof(Node *));
    graph->visited = (bool *)malloc(vertices * sizeof(bool));
    for (int i = 0; i < vertices; i++)
    {
        graph->adjacencyList[i] = NULL;
        graph->visited[i] = false;
    }
    return graph;
}

void addEdge(Graph *graph, int src, int dest)
{
    Node *newNode = createNode(dest);
    newNode->next = graph->adjacencyList[src];
    graph->adjacencyList[src] = newNode;
}

void BFS(Graph *graph, int startVertex)
{
    int queue[graph->vertices], front = -1, rear = -1;
    graph->visited[startVertex] = true;
    queue[++rear] = startVertex;

    while (front != rear)
    {
        int currentVertex = queue[++front];
        printf("%d ", currentVertex);
        Node *temp = graph->adjacencyList[currentVertex];
        while (temp)
        {
            int adjVertex = temp->vertex;
            if (!graph->visited[adjVertex])
            {
                graph->visited[adjVertex] = true;
                queue[++rear] = adjVertex;
            }
            temp = temp->next;
        }
    }
}

void DFS(Graph *graph, int startVertex)
{
    graph->visited[startVertex] = true;
    printf("%d ", startVertex);
    Node *temp = graph->adjacencyList[startVertex];
    while (temp)
    {
        int adjVertex = temp->vertex;
        if (!graph->visited[adjVertex])
        {
            DFS(graph, adjVertex);
        }
        temp = temp->next;
    }
}

int main()
{
    int vertices = 5;
    Graph *graph = createGraph(vertices);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);

    printf("BFS Traversal: ");
    BFS(graph, 0);

    for (int i = 0; i < vertices; i++)
    {
        graph->visited[i] = false;
    }

    printf("\nDFS Traversal: ");
    DFS(graph, 0);

    return 0;
}

/*
output:
BFS Traversal: 0 1 2 3 4
DFS Traversal: 0 1 3 4 2
*/
