#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct NodeTag
{
    ElementType data;
    struct Nodetag *next;
} Node;
typedef Node *List;
typedef Node *Position;

void makeNull(List *L)
{
    *L = (Node *)malloc(sizeof(Node));
    (*L)->next = NULL;
};
int empty(List L) {
    return L->next==NULL;
};
int len(List L)
{
    int count = 0;
    while (!empty(L))
        count++;
    return count;
};
int fullList(List L) {};
void print(List L) {};
ElementType getAt(Position p, List L) {};
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