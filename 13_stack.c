// 13.	Write a program to demonstrate a stack implementation with push, pop, isFull, isEmpty, and top functions.


#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure to represent a stack
typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

// Function to initialize a stack
void initializeStack(Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is full
bool isFull(Stack* stack) {
    return stack->top == MAX_SIZE - 1;
}

// Function to check if the stack is empty
bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(Stack* stack, int element) {
    if (isFull(stack)) {
        printf("Stack overflow. Cannot push element onto the stack.\n");
    } else {
        stack->arr[++stack->top] = element;
        printf("Pushed element %d onto the stack.\n", element);
    }
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow. Cannot pop element from an empty stack.\n");
        return -1;
    } else {
        int element = stack->arr[stack->top--];
        printf("Popped element %d from the stack.\n", element);
        return element;
    }
}

// Function to return the top element of the stack without removing it
int top(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. No top element.\n");
        return -1;
    } else {
        return stack->arr[stack->top];
    }
}

int main() {
    Stack stack;
    initializeStack(&stack);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("Top element of the stack: %d\n", top(&stack));

    pop(&stack);
    pop(&stack);
    pop(&stack);
    pop(&stack); // Trying to pop from an empty stack

    return 0;
}
