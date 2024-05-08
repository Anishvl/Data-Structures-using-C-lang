#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Function to check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Function to return the precedence of an operator
int getPrecedence(char c) {
    if (c == '+' || c == '-')
        return 1;
    else if (c == '*' || c == '/')
        return 2;
    return 0; // for other characters (operands)
}

// Function to convert infix expression to postfix
void infixToPostfix(char infix[], char postfix[]) {
    char stack[MAX_STACK_SIZE];
    int top = -1; // Initialize the stack top

    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token; // Append operands to the postfix expression
        } else if (token == '(') {
            stack[++top] = token; // Push '(' onto the stack
        } else if (token == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = stack[top--]; // Pop operators and append to postfix until '(' is encountered
            }
            if (top >= 0 && stack[top] == '(') {
                top--; // Pop '(' from the stack
            }
        } else if (isOperator(token)) {
            while (top >= 0 && getPrecedence(stack[top]) >= getPrecedence(token)) {
                postfix[j++] = stack[top--]; // Pop operators with higher or equal precedence
            }
            stack[++top] = token; // Push the current operator onto the stack
        }
    }

    // Pop any remaining operators from the stack and append to postfix
    while (top >= 0) {
        postfix[j++] = stack[top--];
    }

    postfix[j] = '\0'; // Null-terminate the postfix expression
}

int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
