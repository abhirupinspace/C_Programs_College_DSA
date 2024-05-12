// 10.	Write a program to create a double link list, insert an element, then delete that element.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the doubly linked list
typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

// Function to create a new node with the given data
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node with the given data at the beginning of the doubly linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head != NULL) {
        head->prev = newNode;
    }
    newNode->next = head;
    return newNode;
}

// Function to delete the first occurrence of a node with the given data from the doubly linked list
Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    Node* current = head;

    // Find the node to delete
    while (current != NULL && current->data != data) {
        current = current->next;
    }

    // If the node with the given data is not found
    if (current == NULL) {
        printf("Element %d not found in the list.\n", data);
        return head;
    }

    // If the node to delete is the first node
    if (current->prev == NULL) {
        head = current->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(current);
    } else {
        current->prev->next = current->next;
        if (current->next != NULL) {
            current->next->prev = current->prev;
        }
        free(current);
    }

    printf("Element %d deleted from the list.\n", data);
    return head;
}

// Function to print the elements of the doubly linked list
void printList(Node* head) {
    printf("Doubly linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert elements into the doubly linked list
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    // Print the original doubly linked list
    printList(head);

    // Delete an element from the doubly linked list
    head = deleteNode(head, 20);

    // Print the doubly linked list after deletion
    printList(head);

    return 0;
}
