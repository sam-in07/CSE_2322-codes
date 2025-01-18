#include <iostream>
#include <vector>
#include <algorithm> // For sort
using namespace std;

class PriorityQueue {
private:
    vector<int> pq; // Vector to store the priority queue

public:
    // Insert an element into the priority queue
    void insert(int value) {
        pq.push_back(value);            // Add the value to the end
        sort(pq.rbegin(), pq.rend());   // Sort in descending order (highest priority first)
        cout << "Inserted " << value << " into the priority queue.\n";
    }

    // Delete the highest-priority element
    void remove() {
        if (pq.empty()) {
            cout << "Priority queue is empty! Cannot remove any element.\n";
            return;
        }

        int highestPriority = pq.front(); // The highest-priority element is at the front
        pq.erase(pq.begin());             // Remove the front element
        cout << "Removed " << highestPriority << " from the priority queue.\n";
    }

    // Display the elements of the priority queue
    void display() {
        if (pq.empty()) {
            cout << "Priority queue is empty!\n";
            return;
        }

        cout << "Priority queue elements (highest priority first): ";
        for (int value : pq) {
            cout << value << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int choice, value;

    while (true) {
        cout << "\nPriority Queue Operations:\n";
        cout << "1. Insert\n2. Remove\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter value to insert: ";
            cin >> value;
            pq.insert(value);
            break;
        case 2:
            pq.remove();
            break;
        case 3:
            pq.display();
            break;
        case 4:
            cout << "Exiting program!\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}
