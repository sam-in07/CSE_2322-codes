#include <iostream>
using namespace std;

// Function to implement the Euclidean Algorithm for finding GCD
int gcd(int a, int b) {
    // Continue until b becomes zero
    while (b != 0) {
        // Calculate remainder
        int temp = b;
        b = a % b;  // Update b to the remainder of a divided by b
        a = temp;   // Update a to the previous value of b
    }
    return a;  // When b is 0, a contains the GCD
}

int main() {
    int num1, num2;

    // Input two positive integers
    cout << "Enter two positive integers: ";
    cin >> num1 >> num2;

    // Ensure the numbers are positive
    if (num1 <= 0 || num2 <= 0) {
        cout << "Please enter positive integers only." << endl;
        return 1;
    }

    // Call gcd function and display the result
    int result = gcd(num1, num2);
    cout << "The Greatest Common Divisor (GCD) of " << num1 << " and " << num2 << " is: " << result << endl;

    return 0;
}
