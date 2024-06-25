#include <stdio.h>
struct Node
{
  char KyTu;
  struct Node *Next;
};
typedef struct Node *Cau;
//======================================================//
Cau khoitao()
{
  Cau *sen = (Cau *)malloc(sizeof(struct Node));
  (*sen)->Next = NULL;
  return *sen;   
}

//======================================================//
int main()
{
  printf("Hello World");
}