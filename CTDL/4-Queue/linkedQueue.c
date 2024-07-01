#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------//
#define MaxLength 10
typedef int ElementType;
struct Node
{
  ElementType Element;
  struct Node *Next;
};
typedef struct Node *Position;
typedef struct
{
  Position Front, Rear;
} Queue;

void makenullQueue(Queue *pQ)
{
  Position Header;
  Header = (struct Node *)malloc(sizeof(struct Node));
  Header->Next = NULL;
  pQ->Front = Header;
  pQ->Rear = Header;
}
void deQueue(Queue *q)
{
  if (q->Front->Next == NULL)
    printf("Loi: Hang rong!");
  else
  {
    if (q->Front->Next == q->Rear)
      makenullQueue(q);
    else
    {
      Position temp = q->Front->Next;
      q->Front->Next = q->Front->Next->Next;
      free(temp);
    }
  }
}
void enQueue(int x, Queue *q)
{
  Position temp = (struct Node *)malloc(sizeof(struct Node));
  temp->Element = x;
  temp->Next = NULL;
  if (q->Front->Next == NULL)
  {
    q->Front->Next = temp;
    q->Rear = temp;
  }
  else
  {
    q->Rear->Next = temp;
    q->Rear = temp;
  }
}

//=============================//
int main()
{
  printf("Hello world");
}