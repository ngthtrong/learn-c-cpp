#include <stdio.h>
#include <stdlib.h>
#define MaxSize 6
typedef int ElementType;
typedef struct
{
    ElementType elements[MaxSize];
    int front, rear;
} Queue;

void makeNull(Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

int emptyQueue(Queue q)
{
    return q.front == -1;
}

int fullQueue(Queue q)
{
    return q.front == q.rear;
}

int sizeQueue(Queue q)
{
    if (q.front < q.rear)
    {
        return q.rear - q.front;
    }
    else if (fullQueue(q))
    {
        return MaxSize;
    }
    else
    {
        
    }
}

void printQueue(Queue q)
{
}

void enQueue(ElementType x, Queue *q)
{
}

ElementType deQueue(Queue *q)
{
}