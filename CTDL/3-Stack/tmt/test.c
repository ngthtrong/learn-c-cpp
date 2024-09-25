#include <stdio.h>
#include <stdlib.h>
// #include "astacklib.h"
// #include "pstacklib.h"
#include "dstacklib.h"

int main()
{
    Stack s;
    makeNull(&s);
    for (int i = 0; i < 5; i++)
    {
        push(i * 2, &s);
    }
    printf("%d ", pop(&s));
    for (int i = 0; i < 5; i++)
    {
        printf("%d ", pop(&s));
    }
    printf(" \n");
}