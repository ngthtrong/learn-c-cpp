#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
//==========define==========//
#define MaxLength 200
typedef char ElementType;
//==========STACK==========//
typedef struct
{
  ElementType Elements[MaxLength];
  int Top_idx;
} Stack;

void push(ElementType x, Stack *pS)
{
  if (pS->Top_idx == 0)
    printf("Loi stack day");
  else
  {
    pS->Top_idx--;
    pS->Elements[pS->Top_idx] = x;
  }
}

ElementType pop(Stack *pS)
{
  if (pS->Top_idx == MaxLength)
    printf("Loi stack empty");
  else
  {
    ElementType temp = pS->Elements[pS->Top_idx];
    pS->Elements[pS->Top_idx] = '\0';
    pS->Top_idx++;
    return temp;
  }
  return 'e';
}

// int topStack(Stack s)
// {
//   return s.Elements[s.Top_idx - 1];
// }
//=========QUEUE===========//
typedef struct
{
  ElementType Elements[MaxLength];
  int Front, Rear;
} Queue;
ElementType deQueue(Queue *q)
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
  if (q->Front == 0 && q->Rear == MaxLength-1)
    printf("Hang day.");
  else
  {
    if (q->Rear == -1 && q->Front == -1)
    {
      q->Front = 0;
      q->Rear = 0;
    }
    else if (q->Rear == MaxLength-1)
    {
      for (int i = 0; i + q->Front <= MaxLength-1; i++)
      {
        q->Elements[i] = q->Elements[q->Front + i];
      }
      q->Rear = MaxLength-1 - q->Front + 1;
      q->Front = 0;
    }
    else
      q->Rear++;
    q->Elements[q->Rear] = x;
  }
}
//====================//

//====================//
int main()
{
  char str[200];
  fgets(str, 200, stdin);
  if (str[strlen(str) - 1] == '\n')
    str[strlen(str) - 1] = '\0';
  Queue q;
  q.Front = -1;
  q.Rear = -1;
  Stack s;
  s.Top_idx = MaxLength;
  int counter = 0;
  for (int i = 0; i < strlen(str); i++)
  {
    char temp = tolower(str[i]);
    if (temp >= 97 && temp <= 122)
    {
      counter++;
      push(temp, &s);
      enQueue(temp, &q);
    }
  }
  printf("\"%s\" ", str);
  for (int i = 0; i < counter; i++)
  {

    if (deQueue(&q) != pop(&s))
    {
      printf("doc xuoi khac doc nguoc\n");
      return -1;
    }
  }
  printf("doc xuoi va doc nguoc nhu nhau\n");
}