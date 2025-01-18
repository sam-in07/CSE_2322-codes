// #include <bits/stdc++.h> 
// using namespace std; 


// int ackermann(int m ,  int n ) {
// if(m==0) {
//     return n+1 ;
// }
// else if (m > 0 && n == 0) {
// return ackermann(m - 1, 1);
// } 
// else {
//         return ackermann(m - 1, ackermann(m, n - 1));
// }
// }
// int  main() {
// int n , m ;
// cin >> m >> n ;

// cout << "Ackermann(" << m << ", " << n << ") = " << ackermann(m, n) << endl ;
    

// }


#include <iostream>
using namespace std;

// Define the Ackermann function
int Ackermann(int m, int n) {
    // Print the current step
    cout << "Ackermann(" << m << ", " << n << ") -> ";

    // Base case 1: if m == 0
    if (m == 0) {
        cout << (n + 1) << endl;
        return n + 1;
    } 
    
    // Base case 2: if m > 0 and n == 0
    else if (m > 0 && n == 0) {
        int result = Ackermann(m - 1, 1);
        cout << result << endl;
        return result;
    } 
    
    // Recursive case: if m > 0 and n > 0
    else if (m > 0 && n > 0) {
        int innerResult = Ackermann(m, n - 1); // Calculate Ackermann(m, n-1)
        int result = Ackermann(m - 1, innerResult); // Then calculate Ackermann(m-1, innerResult)
        cout << result << endl;
        return result;
    }

    return -1; // Invalid case (shouldn't reach here with valid inputs)
}

int main() {
    int m, n;

    cout << "Enter values for m and n: ";
    cin >> m >> n;

    // Calculate and output the result
    cout << "\nCalculating Ackermann(" << m << ", " << n << ")..." << endl;
    int result = Ackermann(m, n);

    cout << "\nFinal result: Ackermann(" << m << ", " << n << ") = " << result << endl;

    return 0;
}
