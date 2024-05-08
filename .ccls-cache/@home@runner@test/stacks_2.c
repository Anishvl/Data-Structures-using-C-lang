#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct stack {
    struct node *top;
};

struct stack* createstack() {
    struct stack* stack = malloc(sizeof(struct stack));
    stack->top = NULL;
    return stack;
}

void push(struct stack* stack, int data) {
    struct node* newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = stack->top;
    stack->top = newnode;
}

int pop(struct stack* stack) {
    if (stack->top == NULL) {
        printf("The stack is empty\n");
        return -1;
    }
    struct node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

void printstack(struct stack* stack) {
    struct node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    int a;
    printf("Enter how many elements you want: ");
    scanf("%d", &a);

    printf("Enter the elements:\n");
    int arr[a];
    int i = 0;

    while (i < a) {
        scanf("%d", &arr[i]);
        i++;
    }

    struct stack* stack = createstack();

    i = 0;
    while (i < a) {
        push(stack, arr[i]);
        i++;
    }

    printf("Original stack: ");
    printstack(stack);

    int b;
    printf("Enter the element to pop: ");
    scanf("%d", &b);

    if (b == stack->top->data) {
        pop(stack);
        printf("Element %d popped.\n", b);
    } else {
        printf("Element %d is not at the top of the stack.\n", b);
    }

    printf("Updated stack: ");
    printstack(stack);

    return 0;
}
