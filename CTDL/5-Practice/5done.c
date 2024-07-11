#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef int ElementType;
typedef struct Queue
{
  int Elements[100];
  int Front, Rear;
} Queue;

typedef struct
{
  Queue Q1, Q2;
} Stack;

void makenullStack(Stack *pS)
{
  makenull(&pS->Q1);
  makenull(&pS->Q2);
}
int emptyStack(Stack s)
{
  return isEmpty(s.Q1) && isEmpty(s.Q2);
}
void push(ElementType x, Stack *pS)
{
  if (isEmpty(pS->Q1))
  {
    enQueue(x, &(pS->Q1));
    while (!isEmpty(pS->Q2))
    {
      enQueue(deQueue(&(pS->Q2)), &(pS->Q1));
    }
  }
  else
  {
    enQueue(x, &(pS->Q2));
    while (!isEmpty(pS->Q1))
    {
      enQueue(deQueue(&(pS->Q1)), &(pS->Q2));
    }
  }
}
ElementType top(Stack s)
{
  if (!isEmpty(s.Q1))
    return front(s.Q1);
  else
    return front(s.Q2);
  printf("Loi top");
  return -1;
}
ElementType pop(Stack *pS)
{
  int temp;
  if (!isEmpty(pS->Q1))
  {
    temp = front(pS->Q1);
    deQueue(&(pS->Q1));
  }
  else
  {
    temp = front(pS->Q2);
    deQueue(&(pS->Q2));
  }
  return temp;
}
void printStack(Stack *pS)
{
  if (!isEmpty(pS->Q1))
    print(&(pS->Q1));
  else
    print(&(pS->Q2));
}