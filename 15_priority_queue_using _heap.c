// 15.	Implement Priority Queue using Heap.

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

// Structure to represent a node in the priority queue (heap)
typedef struct {
    int data;
    int priority;
} Node;

// Structure to represent a Priority Queue
typedef struct {
    Node* arr[MAX_SIZE];
    int size;
} PriorityQueue;

// Function to create a new node with the given data and priority
Node* createNode(int data, int priority) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->priority = priority;
    return newNode;
}

// Function to swap two nodes in the priority queue
void swap(Node** a, Node** b) {
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to initialize a priority queue
void initializePriorityQueue(PriorityQueue* pq) {
    pq->size = 0;
}

// Function to return the index of the parent of a node
int parent(int i) {
    return (i - 1) / 2;
}

// Function to return the index of the left child of a node
int leftChild(int i) {
    return 2 * i + 1;
}

// Function to return the index of the right child of a node
int rightChild(int i) {
    return 2 * i + 2;
}

// Function to maintain heap property by fixing the down of a node
void fixDown(PriorityQueue* pq, int i) {
    int largest = i;
    int left = leftChild(i);
    int right = rightChild(i);

    if (left < pq->size && pq->arr[left]->priority > pq->arr[largest]->priority) {
        largest = left;
    }

    if (right < pq->size && pq->arr[right]->priority > pq->arr[largest]->priority) {
        largest = right;
    }

    if (largest != i) {
        swap(&pq->arr[i], &pq->arr[largest]);
        fixDown(pq, largest);
    }
}

// Function to maintain heap property by fixing the up of a node
void fixUp(PriorityQueue* pq, int i) {
    while (i > 0 && pq->arr[parent(i)]->priority < pq->arr[i]->priority) {
        swap(&pq->arr[i], &pq->arr[parent(i)]);
        i = parent(i);
    }
}

// Function to insert an element with given data and priority into the priority queue
void enqueue(PriorityQueue* pq, int data, int priority) {
    if (pq->size == MAX_SIZE) {
        printf("Priority Queue overflow. Cannot enqueue element.\n");
        return;
    }

    Node* newNode = createNode(data, priority);
    pq->arr[pq->size++] = newNode;
    fixUp(pq, pq->size - 1);
}

// Function to remove and return the element with the highest priority from the priority queue
Node* dequeue(PriorityQueue* pq) {
    if (pq->size == 0) {
        printf("Priority Queue underflow. Cannot dequeue element.\n");
        return NULL;
    }

    Node* maxPriorityNode = pq->arr[0];
    pq->arr[0] = pq->arr[--pq->size];
    fixDown(pq, 0);
    return maxPriorityNode;
}

// Function to check if the priority queue is empty
int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int main() {
    PriorityQueue pq;
    initializePriorityQueue(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);

    while (!isEmpty(&pq)) {
        Node* maxPriorityNode = dequeue(&pq);
        printf("Dequeued element %d with priority %d\n", maxPriorityNode->data, maxPriorityNode->priority);
        free(maxPriorityNode);
    }

    return 0;
}
