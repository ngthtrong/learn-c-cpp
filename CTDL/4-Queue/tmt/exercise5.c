#include <stdio.h>
#include "../../3-Stack/tmt/pstacklib.h"
#include "circleQueue.h"
#define NumOfEle 20;

void exer5a()
{
    int n = NumOfEle;
    Stack s;
    makeNull(&s);
    Queue q;
    makeNullQueue(&q);
    for (int i = 1; i <= n; i++)
        push(i, &s);
    printf("Stack: ");
    printStack(s);
    for (int i = 1; i <= n; i++)
        enQueue(pop(&s), &q);
    for (int i = 1; i <= n; i++)
        push(deQueue(&q), &s);
    printf("Stack after reverse: ");
    printStack(s);
}

void exer5b()
{
    int n = NumOfEle;
    Stack s;
    makeNull(&s);
    Queue q;
    makeNullQueue(&q);
    for (int i = n; i > 0; i--)
        enQueue(i, &q);
    printf("Queue: ");
    printQueue(q);
    for (int i = 1; i <= n; i++)
        push(deQueue(&q), &s);
    for (int i = 1; i <= n; i++)
        enQueue(pop(&s), &q);
    printf("Queue after reverse: ");
    printQueue(q);
}
void exer5c(){

}
int main(int argc, char *argv[])
{
    exer5a();
    exer5b();
    exer5c();
    return 0;
}
