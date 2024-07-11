#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------//
#define MaxLength 10
typedef int ElementType;
typedef struct
{
  ElementType Elements[MaxLength];
  int Front, Rear;
} Queue;
void makenullQueue(Queue *pQ)
{
  pQ->Front = -1;
  pQ->Rear = -1;
}

void deQueue(Queue *q)
{
  if (q->Front == -1 && q->Rear == -1)
    printf("Loi: Hang rong!");
  else
  {
    q->Elements[q->Front] = '\0';
    if (q->Front != q->Rear)
    {
      if (q->Front == 9)
        q->Front = 0;
      else
        q->Front += 1;
    }
    else
    {
      q->Front = -1;
      q->Rear = -1;
    }
  }
}
void enQueue(int x, Queue *q)
{
  if ((q->Rear - q->Front + 1) % 10 == 0)
    printf("Hang day.");
  else
  {
    if (q->Rear == -1 && q->Front == -1)
    {
      q->Front = 0;
      q->Rear = 0;
    }
    else if (q->Rear == 9)
      q->Rear = 0;
    else
      q->Rear++;
    q->Elements[q->Rear] = x;
  }
}

int main()
{
  char str[300];
  fgets(str, 300, stdin);
  if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
  Queue q;
  makenullQueue(&q);
  char key[10];
  fgets(key, 10, stdin);
  if (key[strlen(key) - 1] == '\n')
    key[strlen(key) - 1] = '\0';

  for (int i = 0; i < strlen(key); i++)
  {
    int n = key[i] - 48;
    enQueue(n, &q);
  }


  for (int i = 0; i < strlen(str); i++)
  {

    str[i] -= q.Elements[q.Front];
    enQueue(q.Elements[q.Front], &q);
    deQueue(&q);
  }
  printf("%s", str);
}