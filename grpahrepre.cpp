#include<iostream>
using namespace std;

int a[20][20]; // Adjacency matrix

int main() {
    int n, i, j;
    
    // Input the number of vertices
    cout << "ENTER THE NUMBER OF VERTICES: ";
    cin >> n;

    // Input the adjacency matrix
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << "ENTER 1 IF " << i << " HAS A EDGE WITH " << j << " ELSE 0: ";
            cin >> a[i][j];
        }
    }

    // Output the adjacency matrix
    cout << "THE ADJACENCY MATRIX IS:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            cout << " " << a[i][j];
        }
        cout << "\n";
    }

    return 0;
}
