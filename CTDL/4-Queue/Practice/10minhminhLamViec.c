
#include <string.h>
#include <stdio.h>

#define MaxLength 50
typedef int ElementType;
typedef struct
{
  ElementType Elements[50];
  int Front, Rear;
} Queue;
//====================================//

void makeNullQueue(Queue *pQ)
{
  pQ->Front = -1;
  pQ->Rear = -1;
}
void readQueue(Queue *pQ, int n)
{
  pQ->Front = 0;
  pQ->Rear = n - 1;
  for (int i = 0; i < n; i++)
  {
    scanf("%d ", &pQ->Elements[i]);
  }
}

void deQueue(Queue *q, int n)
{
  if (q->Front == -1 && q->Rear == -1)
    printf("Loi: Hang rong!");
  else
  {
    q->Elements[q->Front] = '\0';
    if (q->Front != q->Rear)
    {
      if (q->Front == n - 1)
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
void enQueue(int x, Queue *q, int n)
{
  if ((q->Rear - q->Front + 1) % n == 0)
    printf("Hang day.");
  else
  {
    if (q->Rear == -1 && q->Front == -1)
    {
      q->Front = 0;
      q->Rear = 0;
    }
    else if (q->Rear == n - 1)
      q->Rear = 0;
    else
      q->Rear++;
    q->Elements[q->Rear] = x;
  }
}

//====================================//
int main()
{
  int n, counter = 0;
  scanf("%d", &n);
  Queue q;
  makeNullQueue(&q);
  readQueue(&q, n);
  int toiUu[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%d ", &toiUu[i]);
  }
  int index = 0;
  while (q.Front != -1)
  {
    if (q.Elements[q.Front] == toiUu[index])
    {
      deQueue(&q, n);
      index++;
    }
    else
    {
      int temp = q.Elements[q.Front];
      deQueue(&q, n);
      enQueue(temp,&q,n);
    }
    counter++;
  }
  printf("%d",counter);
}