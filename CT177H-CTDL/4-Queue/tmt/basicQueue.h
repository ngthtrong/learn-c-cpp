#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50
typedef int ElementType;
typedef struct
{
    ElementType elements[MaxSize];
    int front, rear;
} Queue;

void makeNull(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}
int emptyQueue(Queue q)
{
    return (q.front == q.rear);
}
int fullQueue(Queue q)
{
    return (q.front == 0 && q.rear == MaxSize);
}
int sizeQueue(Queue q)
{
    return q.rear - q.front;
}
void printQueue(Queue q)
{
    if (!emptyQueue(q))
    {
        int size = sizeQueue(q);
        for (int i = 0; i < size; i++)
            printf("%d ", q.elements[q.front + i]);
        printf("\n");
    }
    else
    {
        printf("print: stack empty\n");
        exit(EXIT_FAILURE);
    }
}
void shiftLeft(int n, Queue *q)
{
    for (int i = 0; i < q->rear - q->front; i++)
        q->elements[i] = q->elements[i + n];
    q->front = 0;
    q->rear -= n;
}
void  enQueue(ElementType x, Queue *q)
{
    if (q->front != 0 && q->rear == MaxSize)
        shiftLeft(q->front, q);
    q->elements[q->rear++] = x;
}
ElementType deQueue(Queue *q)
{
    if (!emptyQueue(*q))
    {
        ElementType rs = q->elements[q->front];
        if (q->front == q->rear - 1)
            makeNull(q);
        else
            q->front++;
        return rs;
    }
    printf("deQueue: stack empty\n");
    exit(EXIT_FAILURE);
}
