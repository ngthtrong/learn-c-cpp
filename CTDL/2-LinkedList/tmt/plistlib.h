#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef int Position;

typedef struct Node
{
  ElementType data;
  struct Node *next;
} Node;

typedef Node *List;
typedef Node *PNode;

/*
Initialize an empty list
*/
void makeNull(List *L)
{
  *L = (Node *)malloc(sizeof(Node));
  (*L)->next = NULL;
}

/*
return Number of elements
*/
int len(List L)
{
  PNode p = L;
  int count = 0;
  while (p->next != NULL)
  {
    count++;
    p = p->next;
  }
  return count;
}

/*
Check whether the list is empty?
*/
int empty(List L)
{
  return L->next == NULL;
}

/*
Check whether the list is full?
*/
int fullList(List L)
{
  return 1;
}

/*
Traverse the list to print out all elements
*/
void print(List L)
{
  PNode p = L;
  while (p->next != NULL)
  {
    printf("%d ", p->next->data);
    p = p->next;
  }
  printf("\n");
}

/*
Return the pointer referring to the ith element
*/
PNode getPosition(Position p, List L)
{
  PNode temp = L;
  for (int i = 1; i < p; i++)
  {
    if (temp == NULL)
    {
      printf("err getPostion: position null\n");
      exit(EXIT_FAILURE);
    }
    temp = temp->next;
  }
  return temp;
}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L)
{
  PNode temp = getPosition(p, L);
  if (temp->next != NULL)
    return temp->next->data;
  printf("err getAt: position doesn't exist\n");
  exit(EXIT_FAILURE);
}
/*
Return the pointer referring to the first element of L
*/
PNode first(List L)
{
  if (!empty(L))
    return L;
  printf("err first: empty list\n");
  exit(EXIT_FAILURE);
}

/*
Return the pointer referring to the last element of L
*/
PNode end(List L)
{
  PNode p = L;
  while (p->next != NULL)
    p = p->next;
  return p;
}

/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x, List *L)
{
  PNode temp = getPosition(p, *L);
  if (temp->next != NULL)
    temp->next->data = x;
  else
  {
    printf("err setAt: position doesn't exist\n");
    exit(EXIT_FAILURE);
  }
}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L)
{
  PNode tempNode = (*L);
  for (int i = 1; i < p; i++)
    tempNode = tempNode->next;

  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = x;
  temp->next = tempNode->next;
  tempNode->next = temp;
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L)
{
  PNode tempNode = getPosition(p, *L);
  if (tempNode->next != NULL)
  {
    ElementType x = tempNode->next->data;
    PNode tempNode = tempNode->next;
    tempNode->next = tempNode->next->next;
    free(tempNode);
    return x;
  }
  printf("err popAt: end of list\n");
  exit(EXIT_FAILURE);
}

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L)
{
  PNode temp = (Node *)malloc(sizeof(Node));
  temp->data = x;
  temp->next = (*L)->next;
  (*L)->next = temp;
}

/*
Remove and return the first element
*/
ElementType popFirst(List *L)
{
  if (!empty(*L))
  {
    PNode fs = (*L);
    ElementType x = fs->next->data;
    (*L)->next = (*L)->next->next;
    free(fs->next);
    return x;
  }
  printf("err popFirst: empty list\n");
  exit(EXIT_FAILURE);
}
/*
Append a new element to the list
*/
void append(ElementType x, List *L)
{
  Node *temp = (Node *)malloc(sizeof(Node));
  temp->data = x;
  temp->next = NULL;
  PNode endNode = end(*L);
  endNode->next = temp;
}

/*
Remove and return the last element
*/
ElementType popLast(List *L)
{
  PNode endNode = end(*L);
  ElementType x = endNode->data;
  PNode p = *L;
  while (p->next != endNode)
    p = p->next;
  p->next = NULL;
  free(endNode);
  return x;
}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L)
{
  if (!empty(L))
  {
    PNode p = L;
    Position i = 0;
    while (p->next->data != x)
    {
      if (p->next == NULL)
      {
        printf("err locate: not found x\n");
        exit(EXIT_FAILURE);
      }
      p = p->next;
      i++;
    }
    return i;
  }
  printf("err locate: empty list\n");
  exit(EXIT_FAILURE);
}

/*
Return the pointer referring to the next position of i in L
*/
PNode next(Position p, List L)
{
  PNode tempNode = getPosition(p, L);
  if (tempNode->next == NULL)
  {
    printf("err next: end of list\n");
    exit(EXIT_FAILURE);
  }
  return tempNode->next;
}

/*
Return the pointer referring to the previous position of p in L
*/
PNode previous(Position p, List L)
{
  PNode tempNode = getPosition(p, L);
  if (tempNode == first(L))
  {
    printf("err previous: first of list\n");
    exit(EXIT_FAILURE);
  }
  // PNode temp = L;
  // while (temp->next != tempNode)
  // {
  //     if (temp->next == NULL)
  //     {
  //         printf("err previous: position doesn't exist\n");
  //         exit(EXIT_FAILURE);
  //     }
  //     temp = temp->next;
  // }
  return getPosition(p - 1, L);
}
