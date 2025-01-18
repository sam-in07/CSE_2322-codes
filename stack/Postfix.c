#include <iostream>
#include <stack>
#include <cctype>  // for isdigit function
#include <sstream> // for stringstream

using namespace std;

// Function to perform arithmetic operations
int applyOperator(int operand1, int operand2, char oper) {
    switch(oper) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': return operand1 / operand2;
        default: return 0;
    }
}

// Function to evaluate Postfix expression
int evaluatePostfix(const string& expression) {
    stack<int> stack;

    // Traverse the postfix expression
    for (char ch : expression) {
        if (isspace(ch)) continue; // Skip spaces

        if (isdigit(ch)) {
            // Convert char digit to integer and push onto stack
            stack.push(ch - '0');
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            // Pop two operands from stack
            int operand2 = stack.top(); stack.pop();
            int operand1 = stack.top(); stack.pop();

            // Apply operator and push the result back onto stack
            int result = applyOperator(operand1, operand2, ch);
            stack.push(result);
        }
    }

    // The final result will be the only value left in the stack
    return stack.top();
}

int main() {
    string postfixExpression;

    // Input Postfix expression
    cout << "Enter a Postfix expression: ";
    getline(cin, postfixExpression);

    // Evaluate the Postfix expression
    int result = evaluatePostfix(postfixExpression);

    // Output the result
    cout << "The result of the Postfix expression is: " << result << endl;

    return 0;
}


/*


Enter a Postfix expression: 23*45*+
The result of the Postfix expression is: 23

*/
