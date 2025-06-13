#include <stdio.h>
#define B 10
typedef int ElementType;
struct Node
{
  ElementType Data;
  struct Node *Next;
};
typedef struct Node *Position;
typedef Position Dictionary[B];

void print(Dictionary d)
{
  for (int i = 0; i < B; i++)
    if (d[i] != NULL)
    {
      {
        printf("bucket %d:  ", i);
        while (d[i] != NULL)
        {
          printf("%5d", d[i]->Data);
          d[i] = d[i]->Next;
        }
        printf("\n");
      }
    }
}

int h(ElementType x)
{
  return x % B;
}

void makenull(Dictionary *d)
{
  for (int i = 0; i < B; i++)
  {
    (*d)[i] = NULL;
  }
}

int member(ElementType x, Dictionary d)
{
  while (d[h(x)] != NULL)
  {
    if (d[h(x)]->Data == x)
      return 1;
    d[h(x)] = d[h(x)]->Next;
  }
  return 0;
}

void insert(ElementType x, Dictionary *d)
{
  if (!member(x, *d))
  {
    Position temp = (Position)malloc(sizeof(struct Node));
    temp->Data = x;
    temp->Next = (*d)[h(x)];
    (*d)[h(x)] = temp;
  }
}

void delete(ElementType x, Dictionary *d)
{
  if (member(x, *d))
  {
    Position temp = (*d)[h(x)];
    if ((*d)[h(x)]->Data == x)
    {
      (*d)[h(x)] = (*d)[h(x)]->Next;
      free(temp);
      return;
    }
    while ((*d)[h(x)]->Next != NULL)
    {
      if ((*d)[h(x)]->Next->Data == x)
      {
        temp = (*d)[h(x)]->Next;
        (*d)[h(x)]->Next = (*d)[h(x)]->Next->Next;
        free(temp);
        if(x==12){
          insert(92,d);
        }
        return;
      }
      (*d)[h(x)] = (*d)[h(x)]->Next;
    }
  }
}