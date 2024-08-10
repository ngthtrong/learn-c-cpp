
#include <stdio.h>
#include <stdlib.h>

typedef double ElementType;

typedef struct CellTag
{
  ElementType element;
  struct CellTag *next;
} Cell;

typedef Cell *Position;
typedef Position List;

Position locate(ElementType x, List *p)
{
  Position temp = (*p);
  while (temp != NULL)
  {
    if (x == temp->element)
      return temp;
    temp = temp->next;
  }
  return temp;
}