// 16.	Write a program to show linear searching. Write a program to show binary searching.

#include <stdio.h>

// Function for linear search
int linearSearch(int arr[], int n, int key)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
            return i; // If key is found, return the index
    }
    return -1; // If key is not found, return -1
}

// Function for binary search (works only on sorted arrays)
int binarySearch(int arr[], int low, int high, int key)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
            return mid; // If key is found, return the index
        else if (arr[mid] < key)
            low = mid + 1; // If key is greater than mid, search in the right half
        else
            high = mid - 1; // If key is smaller than mid, search in the left half
    }
    return -1; // If key is not found, return -1
}

int main()
{
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 10;

    // Linear search
    int linearResult = linearSearch(arr, n, key);
    if (linearResult != -1)
        printf("Linear Search: Element %d found at index %d\n", key, linearResult);
    else
        printf("Linear Search: Element %d not found\n", key);

    // Binary search (works only on sorted arrays)
    int binaryResult = binarySearch(arr, 0, n - 1, key);
    if (binaryResult != -1)
        printf("Binary Search: Element %d found at index %d\n", key, binaryResult);
    else
        printf("Binary Search: Element %d not found\n", key);

    return 0;
}
