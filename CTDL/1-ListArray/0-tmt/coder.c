#include <stdlib.h>
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

List coder(List tring, int key[])
{
    
}

int main()
{
}