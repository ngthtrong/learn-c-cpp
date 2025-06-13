#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int ElementType;

typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node;
typedef Node *Position;
typedef Position List;

void makeNull(List *L)
{
    *L = (Node *)malloc(sizeof(Node));
    (*L)->next = NULL;
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
    printf("\n");
};
ElementType getAt(Position p, List L)
{
    if (p->next != NULL)
        return p->next->data;
    printf("err getAt: position doesn't exist\n");
    exit(EXIT_FAILURE);
};

Position first(List L)
{
    if (!empty(L))
        return L;
    printf("err first: empty list\n");
    exit(EXIT_FAILURE);
};
Position endList(List L)
{
    Position p = L;
    while (p->next != NULL)
        p = p->next;
    return p;
};
void setAt(Position p, ElementType x, List *L)
{
    if (p->next != NULL)
        p->next->data = x;
    else
    {
        printf("err setAt: position doesn't exist\n");
        exit(EXIT_FAILURE);
    }
};
void myInsertAt(Position p, ElementType x, List *L)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
};

void insertAt(int pos, ElementType x, List *L)
{
    Position p = (*L);
    for (int i = 1; i < pos; i++)
        p = p->next;

    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = p->next;
    p->next = temp;
};
ElementType popAt(Position p, List *L)
{
    if (p->next != NULL)
    {
        ElementType x = p->next->data;
        Position temp = p->next;
        p->next = p->next->next;
        free(temp);
        return x;
    }
    printf("err popAt: end of list\n");
    exit(EXIT_FAILURE);
};
void insertFirst(ElementType x, List *L)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = (*L)->next;
    (*L)->next = temp;
};
ElementType popFirst(List *L)
{
    if (!empty(*L))
    {
        Position fs = (*L);
        ElementType x = fs->next->data;
        (*L)->next = (*L)->next->next;
        free(fs->next);
        return x;
    }
    printf("err popFirst: empty list\n");
    exit(EXIT_FAILURE);
};
void append(ElementType x, List *L)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = NULL;
    Position end = endList(*L);
    end->next = temp;
};
ElementType popLast(List *L)
{
    Position end = endList(*L);
    ElementType x = end->data;
    Position p = *L;
    while (p->next != end)
        p = p->next;
    p->next = NULL;
    free(end);
    return x;
};
Position locate(ElementType x, List L)
{
    if (!empty(L))
    {
        Position p = L;
        while (p->next->data != x)
        {
            if (p->next == NULL)
            {
                printf("err locate: not found x\n");
                exit(EXIT_FAILURE);
            }
            p = p->next;
        }
        return p;
    }
    printf("err locate: empty list\n");
    exit(EXIT_FAILURE);
};
Position next(Position p, List L)
{
    if (p->next == NULL)
    {
        printf("err next: end of list\n");
        exit(EXIT_FAILURE);
    }
    return p->next;
};
Position previous(Position p, List L)
{
    if (p == first(L))
    {
        printf("err previous: first of list\n");
        exit(EXIT_FAILURE);
    }
    Position temp = L;
    while (temp->next != p)
    {
        if (temp->next == NULL)
        {
            printf("err previous: position doesn't exist\n");
            exit(EXIT_FAILURE);
        }
        temp = temp->next;
    }
    return temp;
};
void bubbleSort(List *L) // use functions: first(), empty(), endList(),getAt(),setAt()
{
    Position p, q;
    for (p = first(*L); p->next != NULL; p = next(p, *L))
    {
        for (q = first(*L); q->next != NULL; q = next(q, *L))
        {
            if (getAt(q, *L) > getAt(next(q, *L), *L))
            {
                ElementType temp = getAt(q, *L);
                setAt(q, getAt(next(q, *L), *L), L);
                setAt(next(q, *L), temp, L);
            }
        }
    }
};
int main()
{
    List L;
    makeNull(&L);
    insertFirst(9, &L);
    insertFirst(4, &L);
    insertFirst(10, &L);
    insertFirst(7, &L);
    insertFirst(6, &L);
    insertFirst(5, &L);
    insertFirst(1, &L);
    insertFirst(8, &L);
    insertFirst(3, &L);
    insertFirst(2, &L);
    print(L);
    bubbleSort(&L);
    print(L);
    return 0;
}