#include <iostream>
using namespace std;

// Recursive function to solve Tower of Hanoi
void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 1) {
        // Base case: Move the single disk directly from source to destination
        cout << "Move disk 1 from " << source << " to " << destination << endl;
        return;
    }

    // Step 1: Move n-1 disks from source to auxiliary rod using destination as an auxiliary
    towerOfHanoi(n - 1, source, auxiliary, destination);

    // Step 2: Move the nth disk from source to destination
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;

    // Step 3: Move the n-1 disks from auxiliary to destination rod using source as an auxiliary
    towerOfHanoi(n - 1, auxiliary, destination, source);
}

int main() {
    int n;

    cout << "Enter the number of disks: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of disks must be greater than zero!" << endl;
        return 1;
    }

    cout << "Sequence of moves to solve the Tower of Hanoi for " << n << " disks:\n";
    towerOfHanoi(n, 'A', 'C', 'B'); // A = Source, C = Destination, B = Auxiliary

    return 0;
}
