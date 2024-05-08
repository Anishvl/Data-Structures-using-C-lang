#include<stdio.h>
#include<stdlib.h>
#define max_size 100

struct stack {
    int arr[max_size];
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

int isfull(struct stack *stack) {
    return stack->top == max_size - 1;
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
        printf("The stack is empty\n");
        return -1;
    }
    return stack->arr[stack->top];
}

void printstack(struct stack* stack) {
    if (isempty(stack)) {
        printf("The stack is empty\n");
        return;
    }
  printf("Top element: %d\n", peek(stack));
    printf("Stack elements: ");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->arr[i]);
    }
    printf("\n");
}

int main() {
    struct stack* stack = createstack();
    push(stack, 10);
    push(stack, 20);
    
    printstack(stack); 
    free(stack); 
    return 0;
}
