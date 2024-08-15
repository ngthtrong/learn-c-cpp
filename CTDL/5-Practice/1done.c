#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// #include "PIQueue.c"
//====================//
#define MaxLength 200
typedef int ElementType;
typedef struct
{
  ElementType Elements[MaxLength];
  int Front, Rear;
} Queue;
//==========Queue==========//
void makenullQueue(Queue *pQ)
{
  pQ->Front = -1;
  pQ->Rear = -1;
}

int emptyQueue(Queue q)
{
  return q.Front == -1 && q.Rear == -1;
}

void deQueue(Queue *q)
{
  if (q->Front == -1)
    printf("Hang rong: delete\n");
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

ElementType front(Queue q)
{
  if (emptyQueue(q))
    printf("Hang rong! front %d\n", q.Front);
  else
    return q.Elements[q.Front];
  return -2;
}

//====================//

//====================//
int main()
{
  int numOfCustomer,
      maxCashier,
      timeTransaction,
      timeCustomer,
      targetWait;
  scanf("%d", &numOfCustomer);
  scanf("%d", &maxCashier);
  scanf("%d", &timeTransaction);
  scanf("%d", &timeCustomer);
  scanf("%d", &targetWait);
  float avgWait;
  int numberOfCashier;
  for (numberOfCashier = 1; numberOfCashier <= maxCashier; numberOfCashier++) // loop with each number of cashier
  {
    Queue customerList;
    makenullQueue(&customerList);
    for (int i = 1; i <= numOfCustomer; i++) // init customer list with time come to cashier queue
    {
      int temp = i * timeCustomer;
      enQueue(temp, &customerList);
    }
    Queue cashierList[numberOfCashier];
    avgWait = 0;
    for (int j = 0; j < numberOfCashier; j++) // init cashier
    {
      makenullQueue(&(cashierList[j]));
    }
    while (!emptyQueue(customerList)) // add customer to cashier
    {
      for (int j = 0; j < numberOfCashier; j++)
      {
        
        enQueue(front(customerList), &(cashierList[j]));
        deQueue(&customerList);
        if (emptyQueue(customerList))
          break;
      }
    }
    for (int j = 0; j < numberOfCashier; j++)
    {
      int timeCustomComeCashier = front(cashierList[j]);
      while (!emptyQueue(cashierList[j]))
      {
        int timeWait = timeCustomComeCashier - front(cashierList[j]);
        deQueue(&(cashierList[j]));
        timeCustomComeCashier += timeTransaction;
        avgWait += timeWait + timeTransaction;
      }
    }
    int temp = avgWait / numOfCustomer;
    printf("So quay: %d; Thoi gian trung binh ma khach phai bo ra: %d.0\n", numberOfCashier, temp);
    if (temp <= targetWait)
    {
      printf("=> Sieu thi se mo %d quay\n", numberOfCashier);
      return 0;
    }
  }
  printf("Voi %d quay hien co, khach phai cho it nhat %.1f giay moi hoan thanh viec thanh toan!!!.\n", maxCashier, avgWait / numOfCustomer);
}