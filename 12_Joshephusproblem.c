// 12.	Write a program to show Josephus’ problem.

#include <stdio.h>

// Function to find the survivor in Josephus problem
int josephus(int n, int k) {
    if (n == 1)
        return 0;
    else
        return (josephus(n - 1, k) + k) % n;
}

int main() {
    int n, k;

    printf("Enter the number of people (n): ");
    scanf("%d", &n);
    printf("Enter the counting interval (k): ");
    scanf("%d", &k);

    int survivor = josephus(n, k) + 1; // Adding 1 to convert 0-based indexing to 1-based indexing

    printf("The survivor in Josephus problem with %d people and counting interval %d is at position %d.\n", n, k, survivor);

    return 0;
}
