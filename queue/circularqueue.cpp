#include <iostream>
using namespace std;

#define SIZE 5 // Define the maximum size of the circular queue

class CircularQueue {
private:
    int queue[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    // Insert an element into the circular queue
    void enqueue() {
        if ((front == 0 && rear == SIZE - 1) || (rear == (front - 1) % (SIZE - 1))) {
            cout << "Queue is Full! Cannot enqueue." << endl;
            return;
        }

        int value;
        cout << "Enter value to enqueue: ";
        cin >> value;

        if (front == -1) { // First element
            front = rear = 0;
        } else if (rear == SIZE - 1 && front != 0) { // Wrap around
            rear = 0;
        } else { // Normal case
            rear++;
        }

        queue[rear] = value;
        cout << "Enqueued " << value << endl;
    }

    // Delete an element from the circular queue
    void dequeue() {
        if (front == -1) {
            cout << "Queue is Empty! Cannot dequeue." << endl;
            return;
        }

        cout << "Dequeued " << queue[front] << endl;

        if (front == rear) { // Queue becomes empty
            front = rear = -1;
        } else if (front == SIZE - 1) { // Wrap around
            front = 0;
        } else { // Normal case
            front++;
        }
    }

    // Display the elements of the circular queue
    void display() {
        if (front == -1) {
            cout << "Queue is Empty!" << endl;
            return;
        }

        cout << "Queue elements: ";
        if (rear >= front) {
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        } else {
            for (int i = front; i < SIZE; i++) {
                cout << queue[i] << " ";
            }
            for (int i = 0; i <= rear; i++) {
                cout << queue[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice;

    while (true) {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cq.enqueue();
            break;
        case 2:
            cq.dequeue();
            break;
        case 3:
            cq.display();
            break;
        case 4:
            cout << "Exiting program!" << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
        }
    }
    return 0;
}
