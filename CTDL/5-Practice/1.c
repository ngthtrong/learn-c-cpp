#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//====================//
#define MaxLength 200
typedef int ElementType;
typedef struct
{
  ElementType Elements[MaxLength];
  int Front, Rear;
} Queue;
typedef struct
{
  Queue Cashier;
  int Time;
} Cashier;
ElementType
deQueue(Queue *q)
{
  if (q->Front == -1)
    printf("Loi: Hang rong!");
  else
  {
    ElementType temp = q->Elements[q->Front];
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
    return temp;
  }
  return 'e';
}
void enQueue(ElementType x, Queue *q)
{
  if (q->Front == 0 && q->Rear == MaxLength - 1)
    printf("Hang day.");
  else
  {
    if (q->Rear == -1 && q->Front == -1)
    {
      q->Front = 0;
      q->Rear = 0;
    }
    else if (q->Rear == MaxLength - 1)
    {
      for (int i = 0; i + q->Front <= MaxLength - 1; i++)
      {
        q->Elements[i] = q->Elements[q->Front + i];
      }
      q->Rear = MaxLength - 1 - q->Front + 1;
      q->Front = 0;
    }
    else
      q->Rear++;
    q->Elements[q->Rear] = x;
  }
}
void makeNullQueue(Queue *pQ)
{
  pQ->Front = -1;
  pQ->Rear = -1;
}
int emptyQueue(Queue q)
{
  return q.Front == -1;
}
ElementType front(Queue q)
{
  if (emptyQueue(q))
    printf("Hang rong!");
  else
    return q.Elements[q.Front];
  return -1;
}
//====================//

//====================//
int main()
{
  int avgWait, numOfCustomer, maxCashier, timeTransaction, timeCustomer, targetWait;
  scanf("%d", &numOfCustomer);
  scanf("%d", &maxCashier);
  scanf("%d", &timeTransaction);
  scanf("%d", &timeCustomer);
  scanf("%d", &targetWait);
}