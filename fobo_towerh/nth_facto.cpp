#include <iostream>
using namespace std;

// Recursive function to find the nth Fibonacci number
long long fibonacciRecursive(int n) {
    if (n == 0)
        return 0; // Base case: F(0) = 0
    if (n == 1)
        return 1; // Base case: F(1) = 1
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2); // Recursive call
}

// Non-recursive (iterative) function to find the nth Fibonacci number
long long fibonacciIterative(int n) {
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    long long prev1 = 0, prev2 = 1, current;
    for (int i = 2; i <= n; i++) {
        current = prev1 + prev2; // Calculate next term
        prev1 = prev2;           // Update previous terms
        prev2 = current;
    }
    return current;
}

int main() {
    int n, choice;

    cout << "Enter the term (n) of the Fibonacci sequence to find: ";
    cin >> n;

    if (n < 0) {
        cout << "Invalid input! Fibonacci is not defined for negative indices." << endl;
        return 1;
    }

    cout << "\nChoose the method:\n";
    cout << "1. Recursive\n";
    cout << "2. Non-Recursive\n";
    cout << "Enter your choice: ";
    cin >> choice;

    long long result;
    switch (choice) {
        case 1:
            result = fibonacciRecursive(n);
            cout << "The " << n << "th Fibonacci number (using recursion) is: " << result << endl;
            break;
        case 2:
            result = fibonacciIterative(n);
            cout << "The " << n << "th Fibonacci number (using iteration) is: " << result << endl;
            break;
        default:
            cout << "Invalid choice! Please choose 1 or 2." << endl;
    }

    return 0;
}
