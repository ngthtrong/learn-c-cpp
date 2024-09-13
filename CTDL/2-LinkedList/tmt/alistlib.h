#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;
typedef struct  Node
{
    ElementType data;
    struct Node *next;
}Node ;
// typedef struct Node Node;
typedef Node *List;
typedef Node *Position;

void makeNull(List *L)
{
    *L = (Node *)malloc(sizeof(Node));
    (*L)->next->data = NULL;
};
int empty(List L)
{
    return L->next == NULL;
};
int len(List L)
{
    Node *p = L;
    int count = 0;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
};
int fullList(List L)
{
    return 1;
};
void print(List L)
{
    Node *p = L;
    while (p->next != NULL)
    {
        printf("%d ", p->next->data);
        p = p->next;
    }
};
ElementType getAt(Position p, List L)
{
    if (p->next != NULL)
        return p->next->data;
    exit(EXIT_FAILURE);
};
Position first(List L) {};
Position endList(List L) {};
void setAt(Position p, ElementType x, List *L) {};
void insertAt(Position p, ElementType x, List *L) {};
ElementType popAt(Position p, List *L) {};
void insertFirst(ElementType x, List *L) {};
ElementType popFirst(List *L) {};
void append(ElementType x, List *L) {};
ElementType popLast(List *L) {};
Position locate(ElementType x, List L) {};
Position next(Position p, List L) {};
Position previous(Position p, List L) {};