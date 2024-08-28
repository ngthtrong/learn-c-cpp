#include <stdio.h>
typedef int ElementType;
typedef int Position;
#define MaxLenght 100
typedef struct List
{
    ElementType data[MaxLenght];
    int size;
} List;

Position locate(ElementType x, List l)
{
    for (Position i = 0; i < l.size; i++)
    {
        if (l.data[i] == x)

        {
            return i;
        }

    }
    return (Position)l.size;
}

int main()
{
    List l = {{1, 2, 3, 4, 5}, 5};
    printf("%d", locate(456, l));
}