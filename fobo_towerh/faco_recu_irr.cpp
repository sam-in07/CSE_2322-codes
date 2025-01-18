#include <iostream>
using namespace std;

// Recursive function to calculate factorial
long long factorialRecursive(int n) {
    if (n == 0 || n == 1)
        return 1; // Base case: 0! = 1 and 1! = 1
    return n * factorialRecursive(n - 1); // Recursive call
}

// Non-recursive (iterative) function to calculate factorial
long long factorialIterative(int n) {
    long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i; // Multiply result by i
    }
    return result;
}

int main() {
    int number, choice;

    cout << "Enter a number to calculate its factorial: ";
    cin >> number;

    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
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
            result = factorialRecursive(number);
            cout << "Factorial of " << number << " (using recursion) is: " << result << endl;
            break;
        case 2:
            result = factorialIterative(number);
            cout << "Factorial of " << number << " (using iteration) is: " << result << endl;
            break;
        default:
            cout << "Invalid choice! Please choose 1 or 2." << endl;
    }

    return 0;
}
