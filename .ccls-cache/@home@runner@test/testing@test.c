#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char symbol) {
    if (top >= MAX - 1) {
        printf("stack overflow\n");
        exit(1);
    }
    stack[++top] = symbol;
}

char pop() {
    if (top == -1) {
        printf("\nThe stack is underflow\n");
        exit(1);
    }
    return stack[top--];
}

int priority(char operator) {
    if (operator == '+' || operator == '-')
        return 1;
    else if (operator == '/' || operator == '*')
        return 2;
    return 0;
}

void postfixconverter(char infix[], char postfix[]) {
    int i, j = 0;
    for (i = 0; infix[i] != '\0'; i++) {
        char symbol = infix[i];
        if (isalnum(symbol)) {
            postfix[j++] = symbol;
        } else if (symbol == '(') {
            push(symbol);
        } else if (symbol == ')') {
            while (top >= 0 && stack[top] != '(') {
                postfix[j++] = pop();
            }
            if (top >= 0 && stack[top] == '(') {
                pop();
            }
        } else if (priority(symbol) > 0) {
            while (top >= 0 && priority(stack[top]) >= priority(symbol)) {
                postfix[j++] = pop();
            }
            push(symbol);
        }
    }
    
    while (top >= 0) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0'; 
}

int main() {
    char a[100], b[100];
    printf("Enter the equation here: ");
    scanf("%s", a);
    printf("\nThe given equation: %s\n", a);
    postfixconverter(a, b);
    printf("Postfix expression: %s\n", b);
    return 0;
}
