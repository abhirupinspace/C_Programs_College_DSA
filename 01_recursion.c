// 1.	Reverse an array using swapping.\

#include <iostream>
using namespace std;

void reverseArray(int arr[], int n) {
    int start = 0;
    int end = n - 1;
    while (start < end) {
        // Swap the elements
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        
        // Move the pointers
        start++;
        end--;
    }
}

int main() {
    int n;

    // Input the size of the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n];

    // Input the elements of the array
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Reverse the array
    reverseArray(arr, n);

    // Output the reversed array
    cout << "Reversed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}

