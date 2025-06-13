#include <stdio.h>
#include <stdlib.h>

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
// void chuanHoa(DaThuc *d)
// {
//   DaThuc temp = *d, select = *d;
//   while (temp->Next != NULL || temp->Next->Next != NULL)
//   {
//     if (select->Next->e.bac == temp->Next->e.bac)
//     {
//       select->Next->e.he_so += temp->Next->e.he_so;
//       temp->Next = temp->Next->Next;
//     }
//     temp = temp->Next;
//   }
//   if (select->Next != NULL)
//     chuanHoa(&select->Next);
// }
void chenDonThuc(DonThuc s, DaThuc *pl)
{
  if ((*pl)->Next == NULL)
  {
    Position tempNode = malloc(sizeof(struct Node));
    tempNode->e = s;
    tempNode->Next = NULL;
    (*pl)->Next = tempNode;
    return;
  }
  DaThuc tempPosition = *pl;
  while (tempPosition->Next!=NULL)
  {
    if (s.bac == tempPosition->Next->e.bac)
    {
      tempPosition->Next->e.he_so += s.he_so;
      break;
    }
    else if (s.bac > tempPosition->Next->e.bac)
    {
      Position tempNode = malloc(sizeof(struct Node));
      tempNode->e = s;
      tempNode->Next = tempPosition->Next;
      tempPosition->Next = tempNode;
      return;
    }
    else if (tempPosition->Next->Next == NULL)
    {
      Position tempNode = malloc(sizeof(struct Node));
      tempNode->e = s;
      tempNode->Next = NULL;
      tempPosition->Next->Next = tempNode;
      return;
    }
    tempPosition = tempPosition->Next;
  }
}
DaThuc nhanDaThuc(DaThuc d1, DaThuc d2)
{
  DaThuc tempDaThuc = khoitao();
  while (d1->Next != NULL)
  {
    DaThuc d2temp = d2;
    while (d2temp->Next != NULL)
    {
      DonThuc tempDonThuc = {d1->Next->e.he_so * d2temp->Next->e.he_so, d1->Next->e.bac + d2temp->Next->e.bac};
      chenDonThuc(tempDonThuc, &tempDaThuc);
      d2temp = d2temp->Next;
    }
    d1 = d1->Next;
  }
  return tempDaThuc;
}
DaThuc congDaThuc(DaThuc d1, DaThuc d2)
{
  DaThuc tempDaThuc = khoitao();
  while (d1->Next != NULL)
  {
    chenDonThuc(d1->Next->e, &tempDaThuc);
    d1 = d1->Next;
  }
  while (d2->Next != NULL)
  {
    chenDonThuc(d2->Next->e, &tempDaThuc);
    d2 = d2->Next;
  }
  return tempDaThuc;
}

//======================================================//
int main()
{
  DaThuc d = khoitao();
  struct Node *p = d;
  DonThuc s1 = {6.2, 4};
  DonThuc s2 = {4.2, 0};
  DonThuc s3 = {2, 4};
  DonThuc s4 = {1, 9};
  chenDonThuc(s1, &d);
  chenDonThuc(s2, &d);
  chenDonThuc(s3, &d);
  chenDonThuc(s4, &d);

  while (p->Next != NULL)
  {
    DonThuc e = p->Next->e;
    printf("%.3fX^%d ", e.he_so, e.bac);
    p = p->Next;
  }
}