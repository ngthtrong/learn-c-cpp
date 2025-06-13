#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 255

typedef char ElementType;
typedef int Position;

typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node;

typedef Node *List;
typedef Node *PNode;

void makeNull(List *L)
{
    *L = (Node *)malloc(sizeof(Node));
    (*L)->next = NULL;
}
int len(List L)
{
    PNode p = L;
    int count = 0;
    while (p->next != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
void print(List L)
{
    PNode p = L;
    while (p->next != NULL)
    {
        printf("%c", p->next->data);
        p = p->next;
    }
    printf("\n");
}
void insertFirst(ElementType x, List *L)
{
    PNode temp = (Node *)malloc(sizeof(Node));
    temp->data = x;
    temp->next = (*L)->next;
    (*L)->next = temp;
}
void appendList(ElementType *a, int n, List *L)
{
    makeNull(L);
    for (int i = n - 1; i >= 0; i--)
        insertFirst(a[i], L);
}
void read(List *L)
{
    ElementType temp[MAXSIZE];
    fgets(temp, MAXSIZE, stdin);
    if (temp[strlen(temp) - 1] == '\n')
        temp[strlen(temp) - 1] = '\0';
    appendList(temp, strlen(temp), L);
}
PNode end(List L)
{
    PNode p = L;
    while (p->next != NULL)
        p = p->next;
    return p;
}

List coder(List L, List key)
{
    PNode tmpNode = L;
    PNode tmpKey = key;
    while (tmpNode->next != NULL)
    {
        if (tmpKey->next == NULL)
            tmpKey = key;
        tmpNode->next->data += tmpKey->next->data;
        tmpKey = tmpKey->next;
        tmpNode = tmpNode->next;
    }
    return L;
}
List decoder(List L, List key)
{
    PNode tmpNode = L;
    PNode tmpKey = key;
    while (tmpNode->next != NULL)
    {
        if (tmpKey->next == NULL)
            tmpKey = key;
        tmpNode->next->data -= tmpKey->next->data;
        tmpKey = tmpKey->next;

        tmpNode = tmpNode->next;
    }
    return L;
}

int main()
{
    ElementType a[] = {2, 3, 4, 9};
    List key;
    makeNull(&key);
    insertFirst(9, &key);
    insertFirst(4, &key);
    insertFirst(3, &key);
    insertFirst(2, &key);
    List L;
    read(&L);
    print(L);
    List code = coder(L, key);
    print(code);
    List decode = decoder(code, key);
    print(decode);
}