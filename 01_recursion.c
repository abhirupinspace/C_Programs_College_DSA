// 1.	Reverse an array using swapping.\

#include <stdio.h>

// Function to reverse an array using swapping
void reverseArray(int arr[], int start, int end) {
    while (start < end) {
        // Swap elements at start and end indices
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        // Move start index forward and end index backward
        start++;
        end--;
    }
}

// Function to print an array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, size);

    reverseArray(arr, 0, size - 1);

    printf("Reversed array: ");
    printArray(arr, size);

    return 0;
}
