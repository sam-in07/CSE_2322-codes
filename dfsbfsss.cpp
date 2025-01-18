#include <iostream>
#include <vector>
using namespace std;

vector<int> q(20), stack(20), vis(20), a[20];  // Adjacency matrix and auxiliary arrays
int front = -1, rear = -1, top = -1;

void add(int item);
int deleteQueue();
void push(int item);
int pop();
void bfs(int s, int n);
void dfs(int s, int n);

int main() {
    int n, s, ch;
    char c, dummy;

    // Input the number of vertices
    cout << "ENTER THE NUMBER OF VERTICES: ";
    cin >> n;

    // Input the adjacency matrix
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << "ENTER 1 IF " << i << " HAS AN EDGE WITH " << j << " ELSE 0: ";
            cin >> a[i].push_back(0);  // Initialize the adjacency list for the vertex
            cin >> a[i][j];
        }
    }

    // Output the adjacency matrix
    cout << "THE ADJACENCY MATRIX IS:" << endl;
     
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << " " << a[i][j];
        }
        cout << endl;
    }

    // Menu for BFS and DFS
    do {
        // Reset the visited array
        for (int i = 1; i <= n; i++) {
            vis[i] = 1;  // Mark all vertices as unvisited
        }

        cout << "\nMENU" << endl;
        cout << "1. B.F.S" << endl;
        cout << "2. D.F.S" << endl;
        cout << "ENTER YOUR CHOICE: ";
        cin >> ch;

        cout << "ENTER THE SOURCE VERTEX: ";
        cin >> s;

        switch (ch) {
            case 1:
                bfs(s, n);
                break;
            case 2:
                dfs(s, n);
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

        cout << "DO YOU WANT TO CONTINUE (Y/N)? ";
        cin >> c;
    } while (c == 'y' || c == 'Y');

    return 0;
}

void bfs(int s, int n) {
    int p, i;

    add(s);
    vis[s] = 2;

    p = deleteQueue();

    if (p != 0) {
        cout << " " << p;
    }

    while (p != 0) {
        for (i = 1; i <= n; i++) {
            if (a[p][i] != 0 && vis[i] == 1) {
                add(i);
                vis[i] = 2;
            }
        }
        p = deleteQueue();
        if (p != 0) {
            cout << " " << p;
        }
    }

    for (i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            bfs(i, n);
        }
    }
}

void add(int item) {
    if (rear == 19) {
        cout << "QUEUE FULL" << endl;
    } else {
        if (rear == -1) {
            q[++rear] = item;
            front++;
        } else {
            q[++rear] = item;
        }
    }
}

int deleteQueue() {
    if (front > rear || front == -1) {
        return 0;
    } else {
        return q[front++];
    }
}

void dfs(int s, int n) {
    int i, k;
    push(s);
    vis[s] = 2;
    k = pop();

    if (k != 0) {
        cout << " " << k;
    }

    while (k != 0) {
        for (i = 1; i <= n; i++) {
            if (a[k][i] != 0 && vis[i] == 1) {
                push(i);
                vis[i] = 2;
            }
        }
        k = pop();
        if (k != 0) {
            cout << " " << k;
        }
    }

    for (i = 1; i <= n; i++) {
        if (vis[i] == 1) {
            dfs(i, n);
        }
    }
}

void push(int item) {
    if (top == 19) {
        cout << "Stack overflow" << endl;
    } else {
        stack[++top] = item;
    }
}

int pop() {
    if (top == -1) {
        return 0;
    } else {
        return stack[top--];
    }
}
