// 6.	Write a program to show Fibonacci series using recursion.

#include <stdio.h>

// Function to generate the nth Fibonacci number recursively
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Function to print Fibonacci series up to n terms
void printFibonacciSeries(int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
}

int main() {
    int n;

    printf("Enter the number of terms in the Fibonacci series: ");
    scanf("%d", &n);

    printf("Fibonacci series up to %d terms: ", n);
    printFibonacciSeries(n);

    return 0;
}
