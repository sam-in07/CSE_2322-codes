#include <iostream>
using namespace std;

void TowerOfHanoi(int n, char source, char target, char auxiliary) {
    if (n > 0) {
        
        TowerOfHanoi(n - 1, source, auxiliary, target);
        
        
        cout << "Move disk " << n << " from " << source << " to " << target << endl;
        
        
        TowerOfHanoi(n - 1, auxiliary, target, source);
    }
}

int main() {
    int n ;
    cin >> n ; 
    TowerOfHanoi(n, 'A', 'C', 'B'); 
    return 0;
}
