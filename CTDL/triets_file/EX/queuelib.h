#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct CircularQueue {
    int items[MAX_SIZE];
    int front, rear;
} CircularQueue;

// Initialize an empty queue
void makeNull(CircularQueue *Q) {
    Q->front = -1;
    Q->rear = -1;
}

// Check if the queue is empty
int isEmpty(CircularQueue Q) {
    return Q.front == -1;
}

// Check if the queue is full
int isFull(CircularQueue Q) {
    return (Q.rear + 1) % MAX_SIZE == Q.front;
}

// Add an item to the end of the queue
void enQueue(int x, CircularQueue *Q) {
    if (isFull(*Q)) {
        printf("Queue is full\n");
    } else {
        if (isEmpty(*Q)) {
            Q->front = 0;
            Q->rear = 0;
        } else {
            Q->rear = (Q->rear + 1) % MAX_SIZE;
        }
        Q->items[Q->rear] = x;
    }
}

// Return the first item of the queue and remove it
int deQueue(CircularQueue *Q) {
    int item;
    if (isEmpty(*Q)) {
        printf("Queue is empty\n");
        return -1;
    } else {
        item = Q->items[Q->front];
        if (Q->front == Q->rear) {
            makeNull(Q);
        } else {
            Q->front = (Q->front + 1) % MAX_SIZE;
        }
        return item;
    }
}

