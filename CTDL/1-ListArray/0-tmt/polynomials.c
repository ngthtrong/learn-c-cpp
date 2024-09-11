#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10

typedef struct Monomial
{
    int exponent;
    float factor;
} Monomial;

typedef struct Pylonomial
{
    Monomial data[MAX_SIZE];
    int size;
} Pylonomial;

void simplification(Pylonomial *p) {};
void derivative(Pylonomial *p)
{
    for (int i = 0; i < p->size; i++)
    {
        if (p->data[i].exponent == 0)
        {
            p->size--;
            p->data[i] = '\0';
        }
        else
        {
            p->data[i].factor *= p->data[i].exponent--;
        }
    }
};
Pylonomial add(Pylonomial a, Pylonomial b)
{
    for (int i = a.size; i < a.size + b.size; i++)
        a.data[i] = b.data[i - a.size];
    simplification(&a);
    return a;
};

void print(Pylonomial p)
{
    for (int i = 0; i < p.size; i++)
        printf("%.3fx^%d ", p.data[i].factor, p.data[i].exponent);
    printf("\n");
};
void read(Pylonomial *p)
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        Monomial temp;
        scanf("%f %d", temp.factor, temp.exponent);
        p->data[i] = temp;
    }
};
int main(int argc, char const *argv[])
{

    return 0;
}
