#include <stdio.h>
// #include "basicQueue.h"
// #include "circleQueue.h"
#include "linkedQueue.h"

int main(int argc, char const *argv[])
{
    Queue q;
    makeNull(&q);
    enQueue(1, &q);
    enQueue(2, &q);
    enQueue(3, &q);
    enQueue(4, &q);
    enQueue(4, &q);
    printQueue(q);
    printf("de: %d\n", deQueue(&q));
    printf("de: %d\n", deQueue(&q));
    printQueue(q);
    enQueue(5, &q);
    enQueue(6, &q);
    enQueue(7, &q);
    printf("add 5,6:\n");
    printQueue(q);
    printf("de: %d\n", deQueue(&q));
    printf("de: %d\n", deQueue(&q));
    printQueue(q);

    return 0;
}
