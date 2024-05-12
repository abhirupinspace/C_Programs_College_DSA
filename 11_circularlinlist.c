// 11.	Write a program to create a circular link list, insert an element, then delete that element.

#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the circular linked list
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

// Function to insert a new node with the given data at the beginning of the circular linked list
Node* insertAtBeginning(Node* last, int data) {
    Node* newNode = createNode(data);
    if (last == NULL) {
        newNode->next = newNode;
        return newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        return last;
    }
}

// Function to delete the first occurrence of a node with the given data from the circular linked list
Node* deleteNode(Node* last, int data) {
    if (last == NULL) {
        printf("List is empty.\n");
        return NULL;
    }

    Node* current = last->next;
    Node* previous = last;

    // Find the node to delete
    do {
        if (current->data == data) {
            // If the node to delete is the only node in the list
            if (current == last && current->next == last) {
                free(current);
                return NULL;
            }
            // If the node to delete is the first node in the list
            else if (current == last->next) {
                last->next = current->next;
                free(current);
                return last;
            }
            // If the node to delete is in the middle or end of the list
            else {
                previous->next = current->next;
                free(current);
                return last;
            }
        }
        previous = current;
        current = current->next;
    } while (current != last->next);

    printf("Element %d not found in the list.\n", data);
    return last;
}

// Function to print the elements of the circular linked list
void printList(Node* last) {
    if (last == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* temp = last->next;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != last->next);
    printf("\n");
}

int main() {
    Node* last = NULL;

    // Insert elements into the circular linked list
    last = insertAtBeginning(last, 30);
    last = insertAtBeginning(last, 20);
    last = insertAtBeginning(last, 10);

    // Print the original circular linked list
    printf("Original circular linked list: ");
    printList(last);

    // Delete an element from the circular linked list
    last = deleteNode(last, 20);

    // Print the circular linked list after deletion
    printf("Circular linked list after deletion: ");
    printList(last);

    return 0;
}
