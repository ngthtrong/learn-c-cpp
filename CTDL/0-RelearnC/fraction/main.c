#include <stdio.h>
#include <math.h>

typedef struct Fraction
{
    int numerator;
    int denominator;
} Fraction;

Fraction read()
{
    Fraction temp;
    scanf("%d", &temp.numerator);
    scanf("%d", &temp.denominator);
    return temp;
}

int ungChung(int b, int a)
{
    int r = b;
    if (b > a)
    {
        b = a;
        a = r;
        r = a;
    }
    while (a % b != 0)
    {
        r = a % b;
        a = b;
        b = r;
    }
    return r;
}

void print(Fraction p)
{
    if (p.denominator != 1)
        printf("%d/%d\n", p.numerator, p.denominator);
    else
        printf("%d\n", p.numerator);
}
void reduce(Fraction *p)
{
    int UCLL = ungChung(p->numerator, p->denominator);
    p->numerator = p->numerator / UCLL;
    p->denominator = p->denominator / UCLL;
}

Fraction add(Fraction p1, Fraction p2)
{
    Fraction temp;
    temp.numerator = p1.numerator * p2.denominator + p2.numerator * p1.denominator;
    temp.denominator = p1.denominator * p2.denominator;
    reduce(&temp);
    return temp;
}
Fraction subtract(Fraction p1, Fraction p2)
{
    Fraction temp;
    temp.numerator = p1.numerator * p2.denominator - p2.numerator * p1.denominator;
    temp.denominator = p1.denominator * p2.denominator;
    reduce(&temp);
    return temp;
}
Fraction multiply(Fraction p1, Fraction p2)
{
    Fraction temp;
    temp.numerator = p1.numerator * p2.numerator;
    temp.denominator = p1.denominator * p2.denominator;
    reduce(&temp);
    return temp;
}
Fraction divide(Fraction p1, Fraction p2)
{
    Fraction temp;
    temp.numerator = p1.numerator * p2.denominator;
    temp.denominator = p2.numerator * p1.denominator;
    reduce(&temp);
    return temp;
}

int main()
{
    Fraction p1, p2;
    p1 = read();
    p2 = read();
    reduce(&p1);
    reduce(&p2);
    print(p1);
    print(p2);
    printf("add    :");
    print(add(p1,p2));
    printf("sub    :");
    print(subtract(p1,p2));
    printf("mul    :");
    print(multiply(p1,p2));
    printf("divide :");
    print(divide(p1,p2));
    return 0;
}
