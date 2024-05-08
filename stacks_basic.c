#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct stack {
    struct node *top;
};

struct stack *createstack() {
    struct stack *stack = malloc(sizeof(struct stack));
    stack->top = NULL;
    return stack;
}

void push(struct stack *stack, int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = stack->top;
    stack->top = newnode;
}

void printstack(struct stack *stack) {
    struct node *current = stack->top;
    printf("stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct stack *stack = createstack();
    push(stack, 20);
    printstack(stack);
    return 0;
}
