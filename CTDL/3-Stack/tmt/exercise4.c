#include <stdio.h>
#include <stdlib.h>
// #include "astacklib.h"
// #include "pstacklib.h"s
#include "dstacklib.h"

void toBinary(int n)
{
    printf("%d -> ", n);
    Stack s;
    makeNull(&s);
    if (n == 0)
        push(n % 2, &s);
    else
    {
        while (n)
        {
            push(n % 2, &s);
            n /= 2;
        }
    }
    print(&s);
}

int Fibo(int n)
{
    Stack s;
    makeNull(&s);
    push(n, &s);
    int rs = 0;
    while (!isEmpty(s))
    {
        int temp = pop(&s);
        if (temp > 2)
        {
            push(temp - 2, &s);
            push(temp - 1, &s);
        }
        else
            rs += 1;
    }
    return rs;
}
int C(int k, int n)
{
    Stack ks;
    makeNull(&ks);
    Stack ns;
    makeNull(&ns);
    int rs = 0;
    push(k, &ks);
    push(n, &ns);
    while (!(isEmpty(ks) && isEmpty(ns)))
    {

        int tempK = pop(&ks);
        int tempN = pop(&ns);
        if (tempK == 0 || tempK == tempN)
            rs += 1;
        else if (tempK == 1)
            rs += tempN;
        else
        {
            push(tempK - 1, &ks);
            push(tempK, &ks);
            push(tempN - 1, &ns);
            push(tempN - 1, &ns);
        }
    }
    return rs;
}

int main()
{
    // toBinary(127);
    int rs = Fibo(10);
    printf("%d\n", rs);
    int c = C(3, 50);
    printf("%d\n", c);
    return 0;
}