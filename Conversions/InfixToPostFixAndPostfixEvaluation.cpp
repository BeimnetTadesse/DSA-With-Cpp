#include <iostream>
using namespace std;

 
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}
 
int applyOp(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
    }
    return 0;
}

// Convert infix to postfix
void infixToPostfix(char exp[], char postfix[]) {
    char stack[100];
    int top = -1, pIndex = 0;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

   
        if ((ch >= '0' && ch <= '9')) {
            postfix[pIndex++] = ch;
        }
       
        else if (ch == '(') {
            stack[++top] = ch;
        }
       
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[pIndex++] = stack[top--];
            }
            top--;   
        }
 
        else {
            while (top != -1 && precedence(stack[top]) >= precedence(ch)) {
                postfix[pIndex++] = stack[top--];
            }
            stack[++top] = ch;
        }
    }
 
    while (top != -1) {
        postfix[pIndex++] = stack[top--];
    }
    postfix[pIndex] = '\0';
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {
    int stack[100], top = -1;

    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];
 
        if (ch >= '0' && ch <= '9') {
            stack[++top] = ch - '0';
        }
   
        else {
            int b = stack[top--];
            int a = stack[top--];
            stack[++top] = applyOp(a, b, ch);
        }
    }
    return stack[top];
}

 
int main() {
    char infix[100], postfix[100];
    
    cout << "Enter an infix expression: ";
    cin >> infix;

  
    infixToPostfix(infix, postfix);
    cout << "Postfix Expression: " << postfix << endl;

 
    int result = evaluatePostfix(postfix);
    cout << "Evaluation Result: " << result << endl;

    return 0;
}