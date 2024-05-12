// 14.	Write a program to implement a queue with enqueue, dequeue, front, rear, isFull, isEmpty, and size functions.

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a queue
typedef struct {
    int arr[MAX_SIZE];
    int front;
    int rear;
    int size;
} Queue;

// Function to initialize a queue
void initializeQueue(Queue* queue) {
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
}

// Function to check if the queue is full
bool isFull(Queue* queue) {
    return queue->size == MAX_SIZE;
}

// Function to check if the queue is empty
bool isEmpty(Queue* queue) {
    return queue->size == 0;
}

// Function to enqueue an element into the queue
void enqueue(Queue* queue, int element) {
    if (isFull(queue)) {
        printf("Queue overflow. Cannot enqueue element into the queue.\n");
    } else {
        if (isEmpty(queue)) {
            queue->front = 0; // Initialize front when the queue is empty
        }
        queue->rear = (queue->rear + 1) % MAX_SIZE;
        queue->arr[queue->rear] = element;
        queue->size++;
        printf("Enqueued element %d into the queue.\n", element);
    }
}

// Function to dequeue an element from the queue
int dequeue(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue underflow. Cannot dequeue element from an empty queue.\n");
        return -1;
    } else {
        int element = queue->arr[queue->front];
        queue->front = (queue->front + 1) % MAX_SIZE;
        queue->size--;
        if (isEmpty(queue)) {
            // Reset front and rear when the last element is dequeued
            queue->front = -1;
            queue->rear = -1;
        }
        printf("Dequeued element %d from the queue.\n", element);
        return element;
    }
}

// Function to return the front element of the queue without removing it
int front(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No front element.\n");
        return -1;
    } else {
        return queue->arr[queue->front];
    }
}

// Function to return the rear element of the queue without removing it
int rear(Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. No rear element.\n");
        return -1;
    } else {
        return queue->arr[queue->rear];
    }
}

// Function to return the size of the queue
int size(Queue* queue) {
    return queue->size;
}

int main() {
    Queue queue;
    initializeQueue(&queue);

    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);

    printf("Front element of the queue: %d\n", front(&queue));
    printf("Rear element of the queue: %d\n", rear(&queue));
    printf("Size of the queue: %d\n", size(&queue));

    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue); // Trying to dequeue from an empty queue

    return 0;
}
