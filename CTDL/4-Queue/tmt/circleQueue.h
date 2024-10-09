#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
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
    return q.front == q.rear && q.front != -1;
}

int sizeQueue(Queue q)
{
    if (fullQueue(q))
        return MaxSize;
    return (MaxSize - q.front + q.rear) % MaxSize;
}

void printQueue(Queue q)
{
    if (!emptyQueue(q))
    {
        int sz = sizeQueue(q);
        for (int i = 0; i < sz; i++)
            printf("%d ", q.elements[(i + q.front) % MaxSize]);
        printf("\n");
    }
    else
    {
        printf("err print: queue empty\n");
        // exit(EXIT_FAILURE);
    }
}

void enQueue(ElementType x, Queue *q)
{
    if (!fullQueue(*q))
    {
        if (emptyQueue(*q))
        {
            q->front = 0;
            q->rear = 0;
        }
        q->elements[q->rear] = x;
        q->rear = (q->rear + 1) % MaxSize;
    }
    else
    {
        printf("can't enQueue %d: queue full\n", x);
        exit(EXIT_FAILURE);
    }
}

ElementType deQueue(Queue *q)
{
    if (!emptyQueue(*q))
    {
        ElementType rs = q->elements[q->front];
        q->front = (q->front + 1) % MaxSize;
        // printf("%d\n", q->front);
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        return rs;
    }
    printf("err deQueue: queue empty\n");
    exit(EXIT_FAILURE);
}