#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemenType;
typedef struct
{
    ElemenType elements[MAXSIZE];
    int top;
} Stack;

int isEmpty(Stack s)
{
    return s.top == -1;
};
int isFull(Stack s)
{
    return s.top == MAXSIZE - 1;
};
void makeNull(Stack *s)
{
    s->top = -1;
};

ElemenType pop(Stack *s)
{
    if (!isEmpty(*s))
        return s->elements[s->top--];
    printf("pop: stack empty\n");
    exit(EXIT_FAILURE);
};
void push(ElemenType x, Stack *s)
{
    if (!isFull(*s))
    {
        s->top++;
        s->elements[s->top] = x;
    }
    else
    {
        printf("push: stack full\n");
        exit(EXIT_FAILURE);
    }
};
