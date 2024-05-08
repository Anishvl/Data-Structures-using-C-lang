#include <stdio.h>
#include <stdlib.h>

#define max 100
int queue[max];
int front = -1;
int rear = -1;

int enqueue(int item) {
    if (rear == max - 1) {
        printf("The queue is full, cannot append\n");
        return 1;
    }
    if (rear == -1) {
        rear = 0;
        front = 0;  
    } else {
        rear++;
    }
    queue[rear] = item;
    return 0;
}

int dequeue() {
    int item;
    if (front == -1) {
        printf("The queue is empty, cannot dequeue\n");
        return -1;
    }
    item = queue[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front++;
    }
    return item;
}

int main() {
    int nums[] = {2, 1, 3, 4, 5};
    int size = sizeof(nums) / sizeof(nums[0]);
    for (int i = 0; i < size; i++) {
        enqueue(nums[i]);
    }
    for (int i = 0; i < size; i++) {
        printf("%d\n", dequeue());
    }
    return 0;
}
