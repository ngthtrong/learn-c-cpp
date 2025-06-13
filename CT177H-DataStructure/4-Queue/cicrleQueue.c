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
      if (q->Front == 16)
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

void move(int n, Queue q)
{
  for (int i = q.Front; i <= q.Rear; i++)
  {
    q.Elements[i - n] = q.Elements[i];
  }
  q.Front = 0;
  q.Rear -= n;
}

//=============================//
int main()
{
  printf("Hello world");
}