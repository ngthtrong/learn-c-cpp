#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
  int Element;
  struct Node *Next;
};
typedef struct Node *Position;
typedef Position List;
//=========================not test yet=============================//

void swapPosition(Position *p1, Position *p2)
{
  Position temp = *p1;
  (*p1)->Next->Element = (*p2)->Next->Element;
  (*p1)->Next = (*p2)->Next;
  (*p2)->Next->Element = temp->Next->Element;
  (*p2)->Next = temp->Next;
}
//======================================================//
void addFirst(int x, List *pl)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->Element = x;
  temp->Next = (*pl)->Next;
  (*pl)->Next = temp;
}
void deleteList(Position p, List *pl)
{
  List tempList = *pl;
  while (tempList->Next != NULL)
  {
    if (tempList->Next == p->Next)
    {
      tempList->Next = tempList->Next->Next;
      return;
    }
    tempList = tempList->Next;
  }
}

void sort(List *pl)
{
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  while ((*pl)->Next != NULL)
  {
    Position select = (*pl), up = (*pl);
    while (up->Next != NULL)
    {
      if (select->Next->Element < up->Next->Element)
      {
        select = up;
      }
      up = up->Next;
    }
    addFirst(select->Next->Element, &temp);
    deleteList(select, pl);
  }
  (*pl) = temp;
}

void printOddNumbers(List l)
{
  int flag = 0;
  while (l->Next != NULL)
  {
    if (l->Next->Element % 2 != 0)
    {
      flag = 1;
      printf("%d ", l->Next->Element);
    }
    l = l->Next;
  }
  flag ? printf("\n") : printf("DS rong\n");
}
void getEvenNumbers(List l, List *rs)
{
  while (l->Next != NULL)
  {
    if (l->Next->Element % 2 == 0)
    {
      append(l->Next->Element, rs);
    }
    l = l->Next;
  }
}
void printEvenNumbers(List l)
{
  int flag = 0;
  while (l->Next != NULL)
  {
    if (l->Next->Element % 2 == 0)
    {
      flag = 1;
      printf("%d ", l->Next->Element);
    }
    l = l->Next;
  }
  flag ? printf("\n") : printf("DS rong\n");
}
void readList(List *pl)
{
  makenullList(pl);
  List list = *pl;
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++)
  {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d ", &temp->Element);
    temp->Next = NULL;
    list->Next = temp;
    list = list->Next;
  }
}
List readSet()
{
  List l;
  makenullList(&l);
  int n;
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++)
  {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    scanf("%d ", &temp->Element);
    int isMember = member(temp->Element, l);
    if (!isMember)
      addFirst(temp->Element, &l);
  }
  return l;
}
void insertList(int x, Position p, List *pl)
{
  List list = *pl;
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->Element = x;
  while (list->Next != NULL)
  {
    if (list->Next == p->Next)
    {
      temp->Next = list->Next;
      list->Next = temp;
      return;
    }
    list = list->Next;
  }
  list->Next = temp;
  temp->Next = NULL;
}
void append(int x, List *pl)
{
  List list = *pl;
  while (list->Next != NULL)
  {
    list = list->Next;
  }
  struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
  temp->Element = x;
  temp->Next = NULL;
  list->Next = temp;
}
float getAvg(List l)
{
  if (l->Next == NULL)
    return -10000.0f;
  float agv = 0;
  int count = 0;
  l = l->Next;
  while (l != NULL)
  {
    agv += l->Element;
    count++;
    l = l->Next;
  }
  return (agv / count);
}
void removeAll(int x, List *pl)
{
  List tempList = *pl;
  while (tempList->Next != NULL)
  {
    Position temp = locate(x, tempList);
    if (temp->Next)
    {
      deleteList(temp, pl);
      continue;
    }
    tempList = tempList->Next;
  }
}
void erase(int x, List *pl)
{
  List tempList = *pl;
  Position temp = locate(x, tempList);
  if (temp->Next)
  {
    deleteList(temp, pl);
  }
  else
  {
    printf("Not found %d\n", x);
  }
}
List unionSet(List l1, List l2)
{
  while (l2->Next != NULL)
  {
    int isMember = member(l2->Next->Element, l1);
    if (!isMember)
    {
      append(l2->Next->Element, &l1);
    }
    l2 = l2->Next;
  }
  return l1;
}
List difference(List l1, List l2)
{
  List l;
  makenullList(&l);
  while (l1->Next != NULL)
  {
    int isMember = member(l1->Next->Element, l2);
    if (!isMember)
    {
      append(l1->Next->Element, &l);
    }
    l1 = l1->Next;
  }
  return l;
}
void printList(List l)
{
  if (l->Next == NULL)
  {
    printf("DS rong\n");
    return;
  }
  while (l->Next != NULL)
  {
    printf("%d ", l->Next->Element);
  }
  printf("\n");
}
//===============================Copilot=======================//
void makenullList(List *pl)
{
  *pl = (struct Node *)malloc(sizeof(struct Node));
  (*pl)->Next = NULL;
}
int emptyList(List l)
{
  return l->Next == NULL;
}
Position first(List l)
{
  return l;
}
Position endList(List l)
{
  while (l->Next != NULL)
  {
    l = l->Next;
  }
  return l;
}
Position next(Position p, List l)
{
  return p->Next;
}
int retrieve(Position p, List l)
{
  return p->Element;
}
int member(int x, List l)
{
  while (l->Next != NULL)
  {
    if (l->Next->Element == x)
    {
      return 1;
    }
    l = l->Next;
  }
  return 0;
}
Position locate(int x, List l)
{
  while (l->Next != NULL)
  {
    if (l->Next->Element == x)
    {
      return l;
    }
    l = l->Next;
  }
  return NULL;
}
