// 3.	Insert an element in an array. Then delete the element from that array.

#include <stdio.h>

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to insert an element into an array
void insertElement(int arr[], int* size, int element, int position) {
    // Shift elements to the right to make space for the new element
    for (int i = *size - 1; i >= position; i--) {
        arr[i + 1] = arr[i];
    }
    // Insert the new element at the specified position
    arr[position] = element;
    // Increment the size of the array
    (*size)++;
}

// Function to delete an element from an array
void deleteElement(int arr[], int* size, int position) {
    // Shift elements to the left to remove the element at the specified position
    for (int i = position; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }
    // Decrement the size of the array
    (*size)--;
}

int main() {
    int arr[100], size = 0, element, position;

    // Input array size from the user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Input array elements from the user
    printf("Enter %d elements for the array: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the original array
    printf("Original array: ");
    printArray(arr, size);

    // Input element and position to insert from the user
    printf("Enter the element to insert: ");
    scanf("%d", &element);
    printf("Enter the position to insert: ");
    scanf("%d", &position);

    // Insert the element into the array
    insertElement(arr, &size, element, position);

    // Print the array after insertion
    printf("Array after insertion: ");
    printArray(arr, size);

    // Input position to delete from the user
    printf("Enter the position to delete: ");
    scanf("%d", &position);

    // Delete the element from the array
    deleteElement(arr, &size, position);

    // Print the array after deletion
    printf("Array after deletion: ");
    printArray(arr, size);

    return 0;
}

