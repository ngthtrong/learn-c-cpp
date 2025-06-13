#include <stdio.h>
#include "../../3-Stack/tmt/astacklib.h"
#include "circleQueue.h"
#define NumOfEle 20

int a[] = {32, 51, 27, 83, 66, 11, 45, 22, 75};

void pushStack(int a[], int n, Stack *S)
{
    makeNull(S);
    printf("Noi dung ngan xep: ");
    for (int i = 0; i < n; i++)
    {
        push(a[i], S);
        printf("%d ", a[i]);
    }
    printf("\n");
}
void reverseStack(Stack *S)
{
    Queue Q;
    makeNullQueue(&Q);

    // Chuy?n t?t c? các ph?n t? t? ngăn x?p vào hàng đ?i
    while (!isEmpty(*S))
    {
        enQueue(pop(S), &Q);
    }

    // Chuy?n t?t c? các ph?n t? t? hàng đ?i tr? l?i ngăn x?p
    while (!emptyQueue(Q))
    {
        push(deQueue(&Q), S);
    }
}
void printStack1(Stack S)
{
    for (int i = 0; i <= S.top; i++)
    {
        printf("%d ", S.elements[i]);
    }
    printf("\n");
}

void bringinttoqueue(int a[], int n, Queue *pQ)
{
    makeNullQueue(pQ);
    int i;
    for (i = 0; i < n; i++)
    {
        enQueue(a[i], pQ);
    }
}

void reversequeue(Queue *Q)
{
    Stack S;
    makeNull(&S);
    // chuyen phan tu tu hang doi vao ngan xep
    while (!emptyQueue(*Q))
    {
        push(deQueue(Q), &S);
    }
    // chuyen phan tu tu ngan xep vao lai hang doi
    while (!isEmpty(S))
    {
        enQueue(pop(&S), Q);
    }
}
int main()
{
    Stack L1;
    pushStack(a, sizeof(a) / sizeof(int), &L1);
    printf("Stack: ");
    printStack1(L1);
    reverseStack(&L1);
    printf("Stack after reverss: ");
    printStack1(L1);
    Queue Q1;
    bringinttoqueue(a, sizeof(a) / sizeof(int), &Q1);
    printf("Queue: ");
    printQueue(Q1);
    printf("Queue after reverse: ");
    reversequeue(&Q1);
    printQueue(Q1);
}