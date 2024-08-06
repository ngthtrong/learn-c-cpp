#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct Queue
{
  int Elements[100];
  int Front, Rear;
} Queue;
//--------------------//
void deQueue(Queue *q)
{
  if (q->Front == -1)
    printf("%d ", -1);
  else
  {
    printf("%d ", q->Elements[q->Front]);
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
  if (q->Front == 0 && q->Rear == 9)
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
      q->Rear = 9 - q->Front + 1;
      q->Front = 0;
    }
    else
      q->Rear++;
    q->Elements[q->Rear] = x;
  }
}
void makeNull(Queue *q)
{
  q->Front = -1;
  q->Rear = -1;
}

void countQueue(Queue q)
{
  if (q.Front == -1)
    printf("%d\n", 0);
  else
    printf("%d\n", q.Rear - q.Front + 1);
}

//--------------------//
int main()
{
  int n;
  scanf("%d\n", &n);
  Queue q;
  makeNull(&q);
  int data[n];
  for (int i = 0; i < n; i++)
  {
    char tempChar;
    scanf("%c", &tempChar);
    int tempNum;
    if (tempChar == 'E')
    {
      int temp;
      scanf(" %d\n", &temp);
      tempNum=temp;
    }
    else if (tempChar == 'D')
    {
      scanf("\n");
      tempNum = -1;
    }
    data[i] = tempNum;
  }

  for (int i = 0; i < n; i++)
  {
    if (data[i] != -1)
      enQueue(data[i], &q);
    else
      deQueue(&q);
    countQueue(q);
  }
}
