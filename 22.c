#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int queue[MAX_SIZE];
int front = -1, rear = -1;


int isEmpty() {
    return (front == -1 && rear == -1);
}


int isFull() {
    return (rear == MAX_SIZE - 1);
}


void enqueue(int value) {
    if (isFull()) {
        printf("Queue is full\n");
        return;
    } else if (isEmpty()) {
        front = rear = 0;
    } else {
        rear++;
    }
    queue[rear] = value;
}


int dequeue() {
    int deletedElement;
    if (isEmpty()) {
        printf("Queue is empty\n");
        exit(1);
    } else if (front == rear) {
        deletedElement = queue[front];
        front = rear = -1;
    } else {
        deletedElement = queue[front];
        front++;
    }
    return deletedElement;
}

void displayQueue() {
    if (isEmpty()) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    
    enqueue(10);
    enqueue(20);
    enqueue(30);

    
    printf("Before deletion: ");
    displayQueue();

    
    int deletedElement = dequeue();
    printf("Deleted element: %d\n", deletedElement);

    
    printf("After deletion: ");
    displayQueue();

    return 0;
}
