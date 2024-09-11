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

ElementType retrieve(int p)
{
    if (p->next == NULL)
        exit(EXIT_FAILURE);
    else
        return p->next->data;
}
Position getPosition(int i, List L)
{
    Position p = L;
    for (int j = 0; (j < i) && p->next != NULL; j++)
        p = p->next;
    return p;
}
