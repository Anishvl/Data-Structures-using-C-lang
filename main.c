#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100


char stack[MAX_STACK_SIZE];
int top = -1; 


void push(char item) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Stack overflow\n");
        exit(1); 
    }
    stack[++top] = item;
}


char pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        exit(1); 
    }
    return stack[top--];
}


int priority(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '*' || operator == '/')
        return 2;
    return 0;
}


void infixToPostfix(char infix[], char postfix[]) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char token = infix[i];

        if (isalnum(token)) {
            postfix[j++] = token; 
        } else if (token == '(') {
            push(token); 
        } else if (token == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop(); 
            }
            if (top >= 0 && stack[top] == '(') {
                pop(); 
            }
        } else if (priority(token) > 0) {
            while (top >= 0 && priority(stack[top]) >= priority(token)) {
                postfix[j++] = pop(); 
            }
            push(token); 
        }
    }

   
    while (top >= 0) {
        postfix[j++] = pop();
    }

    postfix[j] = '\0';
}

int main() {
    char infix[100], postfix[100];

    printf("Enter an infix expression: ");
    scanf("%s", infix);

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

    return 0;
}
