// write factorial of a number using recursion

#include <stdio.h>

// Function to calculate the factorial of a number recursively
int factorial(int n) {
    // Base case: factorial of 0 is 1
    if (n == 0)
        return 1;
    // Recursive case: factorial of n is n multiplied by factorial of (n-1)
    else
        return n * factorial(n - 1);
}

int main() {
    int n;
    
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Factorial of %d is %d\n", n, factorial(n));

    return 0;
}
