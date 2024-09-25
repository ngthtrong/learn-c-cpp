#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct
{
    ElementType *element;
    int top;
    int capacity;
} Stack;

int isEmpty(Stack s)
{
    return s.top == -1;
};
int isFull(Stack s)
{
    return s.top == s.capacity - 1;
}
void makeNull(Stack *s)
{
    s->element = (ElementType *)malloc(sizeof(ElementType));
    s->top = -1;
    s->capacity = 1;
};

ElementType pop(Stack *s)
{
    if (!isEmpty(*s))
    {
        ElementType rs = s->element[s->top--];
        s->element = (ElementType *)realloc(s->element, sizeof(ElementType) * (--s->capacity));
        return rs;
    }
    printf("pop: stack empty\n");
    exit(EXIT_FAILURE);
};
void push(ElementType x, Stack *s)
{
    if (isFull(*s))
    {
        s->capacity *= 2;
        s->element = (ElementType *)realloc(s->element, sizeof(ElementType) * s->capacity);
    }
    s->element[++s->top] = x;
};
