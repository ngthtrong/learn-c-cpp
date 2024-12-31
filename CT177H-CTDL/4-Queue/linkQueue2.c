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
void makenull(Queue *q)
{
  struct Node *header = (struct Node *)malloc(sizeof(struct Node));
  header->next = NULL;
  q->size = 0;
  q->front = header;
  q->rear = header;
}
int is_empty(Queue q)
{
  if (q.front->next == NULL)
    return 1;
  else
    return 0;
}

void en_queue(int x, Queue *q)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->next = NULL;
  temp->data = x;
  if (q->front->next == NULL)
  {
    q->front->next = temp;
  }
  else
  {
    q->rear->next = temp;
  }
  q->rear = temp;
  q->size++;
}

ElementType de_queue(Queue *q)
{
  int tempData = q->front->next->data;
  if (q->front->next == q->rear)
  {
    q->front->next = NULL;
    freee(q->rear);
    q->rear = q->front;
  }
  else
  {
    struct Node *temp = q->front->next;
    q->front->next = q->front->next->next;
    free(temp);
  }
  q->size--;
  return tempData;
}

ElementType front(Queue q)
{
  if (q.size)
    return q.front->next->data;
  return -1;
}
void print(Queue *q)
{
  Queue temp = (*q);
  while (temp.front->next != NULL)
  {
    printf("%d ", temp.front->next->data);
    temp.front = temp.front->next;
  }
  printf("\n");
}