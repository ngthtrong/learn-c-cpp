#include <stdio.h>
#define B 50
typedef int ElementType;
struct Node
{
  ElementType Data;
  struct Node *Next;
};
typedef struct Node *Position;
typedef Position Dictionary[B];