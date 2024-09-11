#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

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

void sort(Pylonomial *L)
{
    for (int i = 0; i < L->size - 1; i++)
    {
        for (int j = L->size - 1; j > i; j--)
        {
            if (L->data[j - 1].exponent < L->data[j].exponent)
            {
                Monomial temp = L->data[j];
                L->data[j] = L->data[j - 1];
                L->data[j - 1] = temp;
            }
        }
    }
}

void simplification(Pylonomial *p)
{
    sort(p);
    for (int i = 0; i < p->size; i++)
    {
        if (p->data[i].exponent == p->data[i + 1].exponent)
        {
            p->data[i].factor += p->data[i + 1].factor;
            for (int j = i + 1; j < p->size; j++)
                p->data[j] = p->data[j + 1];
            p->size--;
            i--;
        }
        else if (p->data[i].factor == 0)
        {
            for (int j = i; j < p->size; j++)
                p->data[j] = p->data[j + 1];
            p->size--;
            i--;
        }
    }
};
void derivative(Pylonomial *p)
{
    simplification(p);

    for (int i = 0; i < p->size; i++)
    {
        if (p->data[i].exponent == 0)
        {
            p->size--;
        }
        else
        {
            float tempExponent = (float)p->data[i].exponent--;
            p->data[i].factor *= tempExponent;
        }
    }
};
Pylonomial add(Pylonomial *a, Pylonomial *b)
{
    Pylonomial temp;
    temp.size = a->size + b->size;
    for (int i = 0; i < a->size; i++)
        temp.data[i] = a->data[i];
    for (int i = 0; i < b->size; i++)
        temp.data[i + a->size] = b->data[i];
    simplification(&temp);
    return temp;
};

void print(Pylonomial p)
{
    for (int i = 0; i < p.size; i++)
    {
        if (p.data[i].exponent == 0)
            printf("%.0f ", p.data[i].factor);
        else if (p.data[i].exponent == 1)
            printf("%.0fx ", p.data[i].factor);
        else
            printf("%.0fx^%d ", p.data[i].factor, p.data[i].exponent);
        if (i != p.size - 1)
            printf("+ ");
    }
    printf("\n");
};
void read(Pylonomial *p)
{
    int n;
    printf("Enter number monomial of pylonomial: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Enter monomial %d: ", i);
        Monomial temp;
        scanf("%f %d", &temp.factor, &temp.exponent);
        p->data[i] = temp;
    }
    p->size = n;
};
int main(int argc, char const *argv[])
{
    Pylonomial a, b;
    a.size = 0;
    b.size = 0;
    read(&a);
    read(&b);
    printf("a %d: ", a.size);
    print(a);
    printf("b %d: ", b.size);
    print(b);
    Pylonomial sum = add(&a, &b);
    printf("sum: ");
    print(sum);
    derivative(&a);
    printf("derivative of a: ");
    print(a);
    return 0;
}
