#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
struct Node
{
  char KyTu;
  struct Node *Next;
};
typedef struct Node *Cau;
//======================================================//
Cau khoitao()
{
  Cau sen = malloc(sizeof(struct Node));
  sen->Next = NULL;
  return sen;
}
int ktRong(Cau D)
{
  if (D->Next == NULL)
    return 1;
  else
    return 0;
}
void chenKyTu(char c, Cau *pd)
{
  Cau temp = *pd;
  Cau p = malloc(sizeof(struct Node));
  while (temp->Next != NULL)
  {
    temp = temp->Next;
  }
  p->KyTu = c;
  p->Next = NULL;
  temp->Next = p;
}
void hienthi(Cau d)
{
  while (d->Next != NULL)
  {
    printf("%c", d->Next->KyTu);
    d = d->Next;
  }
  printf("\n");
}
void chuanhoa(Cau *pd)
{
  Cau temp = *pd;
  while (temp->Next != NULL)
  {
    if (!temp->KyTu || temp->KyTu == ' ')
      temp->Next->KyTu = toupper(temp->Next->KyTu);
    else
      temp->Next->KyTu = tolower(temp->Next->KyTu);
    temp = temp->Next;
  }
}
int demHoa(Cau d)
{
  int count = 0;
  while (d->Next != NULL)
  {
    if (d->Next->KyTu >= 65 && d->Next->KyTu <= 90)
      count++;
    d = d->Next;
  }
  return count;
}
int sotu(Cau d)
{
  int flag = 0, count = 0;
  while (d->Next != NULL)
  {
    d->Next->KyTu = tolower(d->Next->KyTu);
    if (flag)
    {
      if (d->Next->KyTu <= 96 || d->Next->KyTu >= 123)
      {
        flag = 0;
      }
    }
    else
    {
      if (d->Next->KyTu > 96 && d->Next->KyTu < 123)
      {
        count++;
        flag = 1;
      }
    }
    d = d->Next;
  }
  return count;
}
Cau nhapCau()
{
  Cau d = (struct Node *)malloc(sizeof(struct Node));
  Cau temp = d;
  while (1)
  {
    struct Node *tempNode = (struct Node*)malloc(sizeof(struct Node));
    tempNode->Next = NULL;
    scanf("%c", &tempNode->KyTu);
    if (tempNode->KyTu == '\n' || tempNode->KyTu == '\0')
    {
      temp->Next = NULL;
      break;
    }
    temp->Next = tempNode;
    temp = temp->Next;
  }
  return d;
}

//======================================================//
int main()
{
  printf("he");
}