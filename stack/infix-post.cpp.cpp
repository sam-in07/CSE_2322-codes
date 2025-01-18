#include <iostream>
#include <cstring>
using namespace std;

#define MAX 50
char post[MAX], in[MAX], stack[MAX];
int top = -1, toper = -1;

// Function to add character to postfix expression
void insertPostfix(char x) {
    post[++top] = x;
}

// Function to add operator to stack
void insertStack(char x) {
    stack[++toper] = x;
}

// Function to pop operator from stack and add to postfix expression
void popStack(char x) {
    post[++top] = stack[toper--];
    stack[toper + 1] = x;
}

// Function to check operator precedence
int checkPrec(char x) {
    if (x == '+' || x == '-') return 1;
    if (x == '*' || x == '/') return 2;
    if (x == '^') return 3;
    return 0; // for '('
}

// Function to pop all operators from stack until '(' is found
void popAll() {
    while (stack[toper] != '(') {
        post[++top] = stack[toper--];
    }
    toper--; // Pop '(' from stack
}

int main() {
    cout << "Enter infix expression: ";
    cin.getline(in, MAX);

    insertStack('('); // Add '(' to the stack
    strcat(in, ")"); // Add ')' to the end of the expression

    cout << "\nCharacter\tStack\tPostfix\n";
    
    for (int i = 0; in[i] != '\0'; i++) {
        if (isalnum(in[i])) {
            insertPostfix(in[i]); // If it's an operand, add to postfix
        }
        else if (in[i] == '(') {
            insertStack(in[i]); // If it's '(', push to stack
        }
        else if (in[i] == ')') {
            popAll(); // Pop all operators from the stack until '('
        }
        else {
            // If it's an operator, check precedence and pop from stack if necessary
            while (checkPrec(in[i]) <= checkPrec(stack[toper])) {
                popStack(in[i]);
            }
            insertStack(in[i]); // Push the current operator to the stack
        }
        
        // Print the current step
        cout << in[i] << "\t\t" << stack << "\t" << post << endl;
    }

    cout << "\nFinal Postfix Notation: " << post << endl;
    return 0;
}
