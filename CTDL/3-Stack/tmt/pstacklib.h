#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node
{
    ElementType data;
    struct Node *next;
} Node;
typedef Node *Stack;

int isEmpty(Stack s)
{
    return s->next == NULL;
};
void makeNull(Stack *s)
{
    Node *header = (Stack)malloc(sizeof(Node));
    header->next = NULL;
    (*s) = header;
};
ElementType pop(Stack *s)
{
    Node *a = *s;
    if (!isEmpty(a))
    {
        Node *temp = a->next;
        int rs = temp->data;
        a->next = a->next->next;
        free(temp);
        return rs;
    }
    printf("pop: stack empty\n");
    exit(EXIT_FAILURE);
};
void push(ElementType x, Stack *s)
{
    Node *temp = (Stack)malloc(sizeof(Node));
    temp->data = x;
    temp->next = (*s)->next;
    (*s)->next = temp;
};
void print(Stack *s)
{
    while (!isEmpty(*s))
        printf("%d", pop(s));
    printf("\n");
}