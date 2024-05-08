#include <stdio.h>
#include <stdlib.h>
#define maxsize 100

struct stack {
    int arr[maxsize];
    int top;
};

struct stack* createstack() {
    struct stack* stack = malloc(sizeof(struct stack));
    stack->top = -1;
    return stack;
}

int isempty(struct stack* stack) {
    return stack->top == -1;
}

int isfull(struct stack* stack) {
    return stack->top == maxsize - 1;
}

void push(struct stack* stack, int data) {
    if (isfull(stack)) {
        printf("The stack is full, cannot push %d\n", data);
        return;
    }
    stack->arr[++stack->top] = data;
}

int peek(struct stack* stack) {
    if (isempty(stack)) {
        printf("The stack is empty, cannot peek\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void printstack(struct stack* stack) {
    if (isempty(stack)) {
        printf("The stack is empty\n");
        return;
    }
    printf("Stack (top to bottom):\n");
    for (int i = stack->top; i >= 0; i--) {
        printf("|  %2d  |\n", stack->arr[i]);
    }
    printf("--------\n");
}

int main() {
    struct stack* stack = createstack();
    int a;
  
    printf("Enter the number of elements to push into the stack: ");
    scanf("%d", &a);
    
    int arr[a]; 
    int i = 0;
    
    printf("\nEnter the numbers:\n");
    while (i < a) {
        scanf("%d", &arr[i]);
        push(stack, arr[i]);
        i++;
    }

    printstack(stack);

    free(stack);

    return 0;
}
