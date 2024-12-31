#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PListLib.c"
//======================================================//
void readList(List *pl)
{
    makenullList(pl);
    List list = *pl;
    int n;
    scanf("%d\n", &n);
    for (int i = 0; i < n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        scanf("%d ", &temp->Element);
        temp->Next = NULL;
        list->Next = temp;
        list = list->Next;
    }
}
void printList(List l)
{
    if (l->Next == NULL)
    {
        return;
    }
    while (l->Next != NULL)
    {
        printf("%d ", l->Next->Element);
        l = l->Next;
    }
    printf("\n");
}
//======================================================//
int main()
{
    List l;
    readList(&l);
    printList(l);
}