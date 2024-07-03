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
void deQueue(Queue *q)
{
  if (q->Front == -1)
    printf("Loi: Hang rong!");
  else
  {
    q->Elements[q->Front] = '\0';
    if (q->Front == q->Rear)
    {
      q->Front = -1;
      q->Rear = -1;
    }
    else
    {
      q->Front++;
    }
  }
}
void enQueue(int x, Queue *q)
{
  if (q->Front == 0 &&q->Rear == 9)
    printf("Hang day.");
  else
  {
    if (q->Rear == -1 && q->Front == -1)
    {
      q->Front = 0;
      q->Rear = 0;
    }
    else if (q->Rear == 9)
    {
      for (int i = 0; i + q->Front <= 9; i++)
      {
        q->Elements[i] = q->Elements[q->Front + i];
      }
      q->Rear = 9 - q->Front+1;
      q->Front = 0;
    }
    else
      q->Rear++;
    q->Elements[q->Rear] = x;
  }
}

//=============================//
int main()
{
  printf("Hello world");
}