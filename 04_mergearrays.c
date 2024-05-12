// 4.	Write a program to merge two arrays.

#include <stdio.h>

// Function to merge two arrays
void mergeArrays(int arr1[], int size1, int arr2[], int size2, int result[]) {
    int i = 0, j = 0, k = 0;

    // Merge elements from both arrays into the result array
    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    // Copy remaining elements of arr1, if any
    while (i < size1) {
        result[k++] = arr1[i++];
    }

    // Copy remaining elements of arr2, if any
    while (j < size2) {
        result[k++] = arr2[j++];
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
    int arr1[100], arr2[100], result[200];
    int size1, size2;

    // Input size and elements of the first array from the user
    printf("Enter the size of the first array: ");
    scanf("%d", &size1);
    printf("Enter %d elements for the first array: ", size1);
    for (int i = 0; i < size1; i++) {
        scanf("%d", &arr1[i]);
    }

    // Input size and elements of the second array from the user
    printf("Enter the size of the second array: ");
    scanf("%d", &size2);
    printf("Enter %d elements for the second array: ", size2);
    for (int i = 0; i < size2; i++) {
        scanf("%d", &arr2[i]);
    }

    // Merge the two arrays
    mergeArrays(arr1, size1, arr2, size2, result);

    // Print the merged array
    printf("Merged array: ");
    printArray(result, size1 + size2);

    return 0;
}
