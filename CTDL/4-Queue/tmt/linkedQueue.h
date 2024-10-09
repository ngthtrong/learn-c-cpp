#include <stdio.h>
#include <stdlib.h>
#include "1-ListArray/0-tmt/alistlib.h"
#define MaxSize 100
typedef int ElementType;
typedef struct
{
    ElementType element[MaxSize];
    int front, rear;
} Queue;

void shiftLeft(int n, Queue *q)
{
    for (int i = q->front; i <= q->rear; i++)
    {
        q->element[i - n] = q->element[i];
    }
    q->front = 0;
    q->rear -= n;
}
void enQueue(ElementType x, Queue *q)
{
    if (q->rear == MaxSize - 1 && q->front != 0)
        shiftLeft(q->front, q);
    q->element[q->rear] = x;
    q->rear++;
}
