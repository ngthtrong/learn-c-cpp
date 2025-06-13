#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define MAXSIZE 100

typedef int Position;
typedef char ElementType;
typedef struct
{
    ElementType elements[MAXSIZE];
    Position size;
} List;
List L;

void makeNull(List *L)
{
    L->elements[0] = '\0';
    L->size = 0;
}

void print(List L)
{
    Position i;
    for (i = 1; i <= L.size; ++i)
        printf("%d ", L.elements[i - 1]);
    printf("\n");
}

void read(List *L)
{
    fgets(L->elements, MAXSIZE, stdin);
    if (L->elements[strlen(L->elements) - 1] == '\n')
        L->elements[strlen(L->elements) - 1] = '\0';
    L->size = strlen(L->elements);
}

List doubleList(List L)
{
    List rs;
    makeNull(&rs);
    strcpy(rs.elements, L.elements);
    rs.size = L.size;
    return rs;
}
void insertAt(Position p, ElementType x, List *L)
{
    if (p >= 1 && p <= L->size + 1)
    {
        for (Position i = L->size; i >= p; i--)
            L->elements[i] = L->elements[i - 1];
        L->elements[p - 1] = x;
        L->size++;
    }
    else
    {
        printf("Error Position not found!\n");
        exit(EXIT_FAILURE);
    }
}
int empty(List L)
{
    return (L.size == 0);
}

Position endList(List L)
{
    if (empty(L))
        return 1;
    else
        return L.size + 1;
}

void append(ElementType x, List *L)
{
    insertAt(endList(*L), x, L);
}

List coder(List L, List key)
{
    List rs = doubleList(L);
    int size = 0;
    for (int i = 0; i < rs.size; i++)
        rs.elements[i] += key.elements[i % key.size];
    return rs;
}
List decoder(List L, List key)
{
    List rs = doubleList(L);
    int size = 0;
    for (int i = 0; i < rs.size; i++)
        rs.elements[i] -= key.elements[i % key.size];
    return rs;
}

int main()
{
    List L;
    List key;
    makeNull(&key);
    makeNull(&L);
    append(2, &key);
    append(3, &key);
    append(4, &key);
    append(9, &key);
    read(&L);
    printf("%s\n", L.elements);
    List code = coder(L, key);
    printf("%s\n", code.elements);
    List decode = decoder(code, key);
    printf("%s\n", decode.elements);
}