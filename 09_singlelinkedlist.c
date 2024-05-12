// 9.Write a program to create a single link list, insert an element, then delete that element.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the linked list
typedef struct Node {
    int data;
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
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node with the given data at the beginning of the linked list
Node* insertAtBeginning(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to delete the first occurrence of a node with the given data from the linked list
Node* deleteNode(Node* head, int data) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    Node* current = head;
    Node* previous = NULL;

    // Find the node to delete and keep track of its previous node
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    // If the node with the given data is not found
    if (current == NULL) {
        printf("Element %d not found in the list.\n", data);
        return head;
    }

    // If the node to delete is the first node
    if (previous == NULL) {
        head = head->next;
        free(current);
    } else {
        previous->next = current->next;
        free(current);
    }

    printf("Element %d deleted from the list.\n", data);
    return head;
}

// Function to print the elements of the linked list
void printList(Node* head) {
    printf("Linked list: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    // Insert elements into the linked list
    head = insertAtBeginning(head, 30);
    head = insertAtBeginning(head, 20);
    head = insertAtBeginning(head, 10);

    // Print the original linked list
    printList(head);

    // Delete an element from the linked list
    head = deleteNode(head, 20);

    // Print the linked list after deletion
    printList(head);

    return 0;
}
