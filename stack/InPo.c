#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

//Function to get precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;  // Lowest precedence
    } else if (op == '*' || op == '/') {
        return 2;  // Medium precedence
    } else if (op == '^') {
        return 3;  // Highest precedence
    }
    return 0;
}

// Function to perform the conversion from Infix to Postfix
string infixToPostfix(const string& infix) {
    stack<char> s;  // Stack to hold operators and parentheses
    string postfix = "";  // Resulting postfix expression

    for (char ch : infix) {
        if (isspace(ch)) {
            continue; // Skip spaces
        }

        if (isalnum(ch)) {
            // If it's an operand (a number or variable), add it directly to the postfix expression
            postfix += ch;
        }
        else if (ch == '(') {
            // If it's an opening parenthesis, push it onto the stack
            s.push(ch);
        }
        else if (ch == ')') {
            // If it's a closing parenthesis, pop from the stack until '(' is found
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // Pop the '('
        }
        else { // If the character is an operator
            // Pop operators from the stack with higher or equal precedence
            while (!s.empty() && precedence(s.top()) >= precedence(ch)) {
                postfix += s.top();  // Pop the operator to the postfix expression
                s.pop();
            }
            // Push the current operator onto the stack
            s.push(ch);
        }
    }

    // Pop all the remaining operators from the stack and append them to the postfix expression
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    return postfix;
}

int main() {
    string infixExpression;

    // Input Infix expression
    cout << "Enter an Infix expression: ";
    getline(cin, infixExpression);

    // Convert to Postfix
    string postfixExpression = infixToPostfix(infixExpression);

    // Output the Postfix expression
    cout << "The Postfix expression is: " << postfixExpression << endl;

    return 0;
}
