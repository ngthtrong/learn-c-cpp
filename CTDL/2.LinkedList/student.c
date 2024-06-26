#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
   char ID[10];
   char Name[50];
   float R1, R2, R3;
} Student;
struct Node
{
   Student Element;
   struct Node *Next;
};
typedef struct Node *List;
List getList()
{
   List L = (List)malloc(sizeof(struct Node));
   L->Next = NULL;
   return L;
}
//======================================================//
void printList(List L)
{
   int count = 0;
   while (L->Next != NULL)
   {
      printf("%2d - %10s - %50s - %.3f - %.3f - %.3f - %.3f\n", count, L->Next->Element.ID, L->Next->Element.Name, L->Next->Element.R1, L->Next->Element.R2, L->Next->Element.R3, (L->Next->Element.R1 + L->Next->Element.R2 + L->Next->Element.R3) / 3);
      L = L->Next;
   }
}
int append(Student s, List *pl)
{
   List tempList = *pl;
   struct Node *p = (*pl)->Next;
   int flag = 0;
   while (p != NULL)
   {
      if (strcmp(p->Element.ID, s.ID) == 0)
      {
         flag = 1;
         break;
      }
      p = p->Next;
   }
   if (flag)
      return 0;
   else
   {
      while ((tempList)->Next != NULL)
         tempList = (tempList)->Next;
      (tempList)->Next = (struct Node *)malloc(sizeof(struct Node));
      (tempList)->Next->Element = s;
      (tempList)->Next->Next = NULL;
      return 1;
   }
   return 0;
}

//======================================================//
int main()
{
   printf("Hello, World!\n");

}