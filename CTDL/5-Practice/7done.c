#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 200
typedef char ElementType;
typedef struct
{
  ElementType Elements[MaxLength];
  int Top_idx;
} Stack;
typedef struct
{
  Stack s1, s2;
} Queue;
void makenull(Stack *);
int isEmpty(Stack);
void push(ElementType, Stack *pS);
ElementType pop(Stack *);
ElementType top(Stack);

void makenullQueue(Queue *pQ)
{
  makenull(&(pQ->s1));
  makenull(&(pQ->s2));
}
int emptyQueue(Queue q)
{
  return isEmpty(q.s1) && isEmpty(q.s2);
}
void enQueue(ElementType x, Queue *pQ)
{
  while (!isEmpty(pQ->s1))
    push(pop(&(pQ->s1)), &(pQ->s2));
  push(x, &(pQ->s1));
  while (!isEmpty(pQ->s2))
    push(pop(&(pQ->s2)), &(pQ->s1));
}
ElementType front(Queue q)
{
  if (!isEmpty(q.s1))
    return top(q.s1);
  return -1;
}
ElementType deQueue(Queue *pQ)
{
  if (!isEmpty(pQ->s1))
    return pop(&(pQ->s1));
  return -1;
}
void printQueue(Queue *pQ)
{

  while (!isEmpty(pQ->s1))
  {
    printf("%d ", top(pQ->s1));
    push(pop(&(pQ->s1)), &(pQ->s2));
  }
  while (!isEmpty(pQ->s2))
    push(pop(&(pQ->s2)), &(pQ->s1));
}