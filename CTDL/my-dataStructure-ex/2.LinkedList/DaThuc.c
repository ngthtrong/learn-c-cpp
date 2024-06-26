#include <stdio.h>

typedef struct
{
  double he_so;
  int bac;
} DonThuc;
struct Node
{
  DonThuc e;
  struct Node *Next;
};
typedef struct Node *Position;
typedef Position DaThuc;
//======================================================//
DaThuc khoitao()
{
  DaThuc temp = (struct Node *)malloc(sizeof(struct Node));
  temp->Next = NULL;
  return temp;
}
void inDaThuc(DaThuc d)
{
  while (d->Next != NULL)
  {
    if (d->Next->Next == NULL)
      printf("%.3fX^%d", d->Next->e.he_so, d->Next->e.bac);
    else
      printf("%.3fX^%d + ", d->Next->e.he_so, d->Next->e.bac);
    d = d->Next;
  }
  printf("\n");
}
DaThuc nhanDaThuc(DaThuc d1, DaThuc d2)
{
  DaThuc temp = (struct Node *)malloc(sizeof(struct Node));
  temp->Next=NULL;
  




  return temp;
}

//======================================================//
int main()
{
  printf("hello");
}