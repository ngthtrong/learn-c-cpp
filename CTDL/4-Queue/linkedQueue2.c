#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------//
typedef int ElementType;
struct Node
{
  ElementType data;
  struct Node *next;
};
typedef struct
{
  struct Node *front;
  struct Node *rear;
  int size;
} Queue;

void makenull(Queue *pQ)
{
  pQ->front = (struct Node *)malloc(sizeof(struct Node));
  pQ->rear = pQ->front;
  pQ->front->next = NULL;
  pQ->rear->next = NULL;
  pQ->size = 0;
}
int is_empty(Queue q)
{
  return q.size == 0;
}

void en_queue(ElementType x, Queue *q)
{
  q->size++;
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->data = x;
  temp->next = NULL;
  q->rear->next = temp;
  q->rear = temp;
}
ElementType de_queue(Queue *q)
{
  if (q->size == 0)
  {
    printf("queue is empty\n");
    return -1;
  }
  else
  {
    ElementType temp = q->front->next->data;
    struct Node *tempPos = q->front->next;
    if (q->size == 1)
    {
      q->rear = q->front;
      q->front->next = NULL;
      q->size = 0;
    }
    else
    {
      q->front->next = q->front->next->next;
      q->size--;
    }
    free(tempPos);
    return temp;
  }
}
ElementType front(Queue q)
{
  return q.front->next->data;
}
void print(Queue *q)
{
  struct Node * temp = q->front;
  while (temp->next!=NULL)
  {
    printf("%d ",temp->next->data);
    temp=temp->next;
  }
    printf("\n");
  
}