#include <string.h>
#include <stdio.h>
typedef struct List
{
   int Elements[50];
   int Last;
} List;
void intersection(List l1, List l2, List *pl)
{
   makeNullList(pl);
   for (int i = 0; i < l1.Last; i++)
   {
      if (member(l1.Elements[i], l2))
      {
         if (!member(l1.Elements[i], *pl))
         {
            insertSet(l1.Elements[i], pl);
         }
      }
   }
}
void difference(List l1, List l2, List *pl)
{
   makeNullList(pl);
   for (int i = 0; i < l1.Last; i++)
   {
      if (!member(l1.Elements[i], l2))
      {
         if (!member(l1.Elements[i], *pl))
         {
            insertSet(l1.Elements[i], pl);
         }
      }
   }
}
void sort(List *pl)
{
   int flag = 1;
   while (flag)
   {
      flag = 0;
      for (int i = 0; i < pl->Last - 1; i++)
      {
         if (pl->Elements[i] > pl->Elements[i + 1])
         {
            flag = 1;
            int temp = pl->Elements[i + 1];
            pl->Elements[i + 1] = pl->Elements[i];
            pl->Elements[i] = temp;
         }
      }
   }
}
void removeAll(int x, List *pl)
{
   int position = locate(x, *pl);
   while (position != pl->Last + 1)
   {
      deleteList(position, pl);
      position = locate(x, *pl);
   }
}
void makeNullList(List *pl)
{
   pl->Last = 0;
}
void readList(List *pl)
{
   scanf("%d\n", &pl->Last);
   for (int i = 0; i < pl->Last; i++)
   {
      scanf("%d ", &pl->Elements[i]);
   }
}
void deleteList(int p, List *pl)
{
   if (p < 1 || p > pl->Last)
   {
      printf("Vi tri khong hop le\n");
   }
   else
   {
      for (int i = p - 1; i < pl->Last - 1; i++)
      {
         pl->Elements[i] = pl->Elements[i + 1];
      }
      pl->Last--;
   }
}
void copyEvenNumbers(List l1, List *l2)
{
   makeNullList(l2);
   // int temp = 1;
   for (int i = 0; i < l1.Last; i++)
   {
      if (l1.Elements[i] % 2 == 0)
      {
         insertList(l1.Elements[i], l2->Last + 1, l2);
         // insertList(l1.Elements[i], temp, l2);
         // temp++;
      }
   }
}
int member(int x, List l)
{
   for (int i = 0; i < l.Last; i++)
   {
      if (l.Elements[i] == x)
      {
         return 1;
      }
   }
   return 0;
}
int locate(int x, List l)
{
   for (int i = 0; i < l.Last; i++)
   {
      if (l.Elements[i] == x)
      {
         return i + 1;
      }
   }
   return l.Last + 1;
}

void deleteList(int p, List *pl)
{
   if (p >= 1 && p <= pl->Last)
   {
      for (int i = p - 1; i < pl->Last - 1; i++)
      {
         pl->Elements[i] = pl->Elements[i + 1];
      }
      pl->Last--;
   }
}
void printList(List l1)
{
   if (l1.Last)
   {
      for (int i = 0; i < l1.Last; i++)
      {
         printf("%d ", l1.Elements[i]);
      }
      printf("\n");
   }
}
void copyEvenNumbers(List l1, List *l2, int flag)
{
   makeNullList(l2);
   for (int i = 0; i < l1.Last; i++)
   {
      if (l1.Elements[i] % 2 == flag)
      {
         insertList(l1.Elements[i], l2->Last + 1, l2);
      }
   }
}
void readSet(List *l)
{
   makeNullList(l);
   int n;
   scanf("%d", &n);
   for (int i = 0; i < n; i++)
   {
      int temp;
      scanf("%d ", &temp);
      if (!member(temp, *l))
         insertSet(temp, l);
   }
}
void insertSet(int x, List *pl)
{
   pl->Last++;
   pl->Elements[pl->Last - 1] = x;
}
void normalize(List *pl)
{
   int p = 1;
   while (p < pl->Last)
   {
      for (int i = p + 1; i <= pl->Last; i++)
      {
         if (pl->Elements[i - 1] == pl->Elements[p - 1])
         {
            deleteList(i, pl);
            i--;
         }
      }
      p++;
   }
}
void insertList(int x, int p, List *pl)
{
   if (p >= 1 && p <= pl->Last + 1)
   {
      pl->Last++;
      for (int i = pl->Last - 1; i >= p; i--)
      {
         pl->Elements[i] = pl->Elements[i - 1];
      }
      pl->Elements[p - 1] = x;
   }
}
void erase(int x, List *pl)
{
   int position = locate(x, *pl);
   if (position > 0 && position <= pl->Last)
   {
      deleteList(position, pl);
      erase(x, pl);
   }
}
int main()
{
   List L1, temp;
   readList(&L1);
   printList(L1);
   copyEvenNumbers(L1, &temp);
   if (temp.Last)
      printList(temp);
   copyEvenNumbers(L1, &temp);
   if (temp.Last)
      printList(temp);
}