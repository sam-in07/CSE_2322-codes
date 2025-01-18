#include <iostream>
#include <cstdlib>  // For exit()

#define SIZE 4  // Define stack size

class Stack {
private:
    int top;
    int inp_array[SIZE];  // Array to store stack elements

public:
    Stack() {
        top = -1;  // Initialize stack as empty
    }

    void push() {
        int x;
        if (top == SIZE - 1) {
            std::cout << "\nOverflow!! Stack is full.\n";
        } else {
            std::cout << "\nEnter the element to be added onto the stack: ";
            std::cin >> x;
            inp_array[++top] = x;
        }
    }

    void pop() {
        if (top == -1) {
            std::cout << "\nUnderflow!! Stack is empty.\n";
        } else {
            std::cout << "\nPopped element: " << inp_array[top--] << std::endl;
        }
    }

    void show() {
        if (top == -1) {
            std::cout << "\nUnderflow!! Stack is empty.\n";
        } else {
            std::cout << "\nElements present in the stack: \n";
            for (int i = top; i >= 0; --i) {
                std::cout << inp_array[i] << std::endl;
            }
        }
    }
};

int main() {
    Stack stack;  // Create an instance of the Stack class
    int choice;

    while (true) {
        std::cout << "\nPerform operations on the stack:";
        std::cout << "\n1. Push the element";
        std::cout << "\n2. Pop the element";
        std::cout << "\n3. Show the stack";
        std::cout << "\n4. End\n";

        std::cout << "\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                stack.push();
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.show();
                break;
            case 4:
                exit(0);  // Exit the program
            default:
                std::cout << "\nInvalid choice!! Please try again.\n";
        }
    }

    return 0;
}  
