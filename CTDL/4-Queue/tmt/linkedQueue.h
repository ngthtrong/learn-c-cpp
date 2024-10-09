#include <stdio.h>
#include <stdlib.h>
#define MaxSize 5
typedef int ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node;
typedef struct Queue
{
    Node *front;
    Node *rear;
} Queue;

void makeNull(Queue *q)
{
    Node *header = (Node *)malloc(sizeof(Node));
    header->next = NULL;
    q->front = header;
    q->rear = header;
}
int emptyQueue(Queue q)
{
    return q.front->next == NULL;
}
int fullQueue(Queue q)
{
    return 1;
}
void printQueue(Queue q)
{
    Node *temp = q.front;
    while (temp->next)
    {
        printf("%d ", temp->next->data);
        temp = temp->next;
    }
    printf("\n");
}
void enQueue(ElementType x, Queue *q)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    q->rear->next = temp;
    q->rear = temp;
}
ElementType deQueue(Queue *q)
{
    if (!emptyQueue(*q))
    {
        Node *temp = q->front->next;
        ElementType rs = temp->data;
        q->front->next = q->front->next->next;
        free(temp);
        return rs;
    }
    printf("err deQueue: queue is empty");
    exit(EXIT_FAILURE);
}
