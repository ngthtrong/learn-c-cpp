#include <stdio.h>
#include <stdlib.h> // Add this line to include the necessary header file

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
typedef struct Node* List;

List getList(){
   List L=(List)malloc(sizeof(struct Node));
   L->Next=NULL;
   return L;
}

void showPassedList(List L)
{
   List passList = getList();
   passList->Next = NULL;
   while (L->Next != NULL)
   {
      if((L->Next->Element.R1+L->Next->Element.R2+L->Next->Element.R3)/3>=4)
      append(L->Next->Element,passList);     
      L = L->Next;
   }
   printList(passList);
}
int append(Student s, List *pl){
   
}

int main()
{
   List L = getList();
   if (L->Next == NULL)
      printf("Created a list!!!");
   else
      printf("Exception!!!");
}