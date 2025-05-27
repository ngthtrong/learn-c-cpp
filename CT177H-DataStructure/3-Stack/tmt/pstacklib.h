#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct NodeStack
{
    ElementType data;
    struct NodeStack *next;
} NodeStack;
typedef NodeStack *Stack;

int isEmptyStack(Stack s)
{
    return s->next == NULL;
};
void makeNull(Stack *s)
{
    NodeStack *header = (Stack)malloc(sizeof(NodeStack));
    header->next = NULL;
    (*s) = header;
};
ElementType pop(Stack *s)
{
    NodeStack *a = *s;
    if (!isEmptyStack(a))
    {
        NodeStack *temp = a->next;
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
    NodeStack *temp = (Stack)malloc(sizeof(NodeStack));
    temp->data = x;
    temp->next = (*s)->next;
    (*s)->next = temp;
};
void print(Stack *s)
{
    while (!isEmptyStack(*s))
        printf("%d ", pop(s));
    printf("\n");
}
void printStack(Stack s)
{
    NodeStack *temp = s;
    while (temp->next != NULL)
    {
        printf("%d ", temp->next->data);
        temp = temp->next;
    }

    printf("\n");
}
// void freeStack(Stack *s)
// {
//     while (!isEmptyStack(*s))
//         int temp = pop(s);
//     free(s);
// }

void infixToPostfix(char *infix, char *postfix)
{
    Stack s;
    makeNull(&s);
    int i = 0, j = 0;
    while (infix[i] != '\0')
    {
        if (infix[i] >= 'a' && infix[i] <= 'z')
        {
            postfix[j++] = infix[i];
        }
        else if (infix[i] == '(')
        {
            push(infix[i], &s);
        }
        else if (infix[i] == ')')
        {
            while (s->next->data != '(')
            {
                postfix[j++] = pop(&s);
            }
            pop(&s);
        }
        else
        {
            while (!isEmptyStack(s) && s->next->data != '(' && s->next->data != '+' && s->next->data != '-' && s->next->data != '*' && s->next->data != '/')
            {
                postfix[j++] = pop(&s);
            }
            push(infix[i], &s);
        }
        i++;
    }
    while (!isEmptyStack(s))
    {
        postfix[j++] = pop(&s);
    }
    postfix[j] = '\0';
}

void reverseByStack(char *postStr)
{
    Stack temp;
    makeNull(&temp);
    for (int i = 0; postStr[i] != '\0'; i++)
        push(postStr[i], &temp);
    for (int i = 0; postStr[i] != '\0'; i++)
        postStr[i] = pop(&temp);
    // freeStack(&temp);
}