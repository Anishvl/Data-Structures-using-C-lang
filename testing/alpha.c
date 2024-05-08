#include <stdio.h>
#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1;
int rear = -1;

void enqueue(int item) {
    if (rear == MAX_SIZE - 1) {
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear++;
    queue[rear] = item;
}

int dequeue() {
    int item;
    if (front == -1) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    item = queue[front];
    front++;
    if (front > rear) {
        front = rear = -1;
    }
    return item;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    printf("Dequeued item: %d\n", dequeue());
    printf("Dequeued item: %d\n", dequeue());

    return 0;
}