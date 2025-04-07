#include <iostream>
#include <list>
#include <iomanip>
#include <math.h>
using namespace std;

typedef struct
{
    double c; // coefficients
    int e;    // exponents
} ElementType;

typedef list<ElementType> Polynomial; // declares the data structure Polynomial

void printPolynomial(Polynomial *pL)
{ // prints the Polynomial pL
    if (pL->size() == 0)
        return;

    cout << fixed << setprecision(2); // sets the decimal precision to 2, e.g.: 5.23

    Polynomial::iterator it = pL->begin();
    cout << '(' << it->c << ")x^" << it->e;

    it++;
    for (; it != pL->end(); it++)
        cout << " + (" << it->c << ")x^" << it->e;

    cout << endl;
}

void insert(double c, int e, Polynomial *pl)
{

    Polynomial::iterator it = pl->begin();
    if (it == pl->end())
    {
        (*pl).push_front({c, e});
        return;
    }
    while (it->e > e)
        it++;
    if (it->e == e)
        it->c = c;
    else
        (*pl).insert(it, {c, e});
}

void delete_e(int e, Polynomial *pl)
{
    Polynomial::iterator it = pl->begin();
    while (it->e != e)
    {
        if (it == (*pl).end())
        {
            cout << "The exponent does not appear." << endl;
            return;
        }
        it++;
    }
    (*pl).erase(it);
}
Polynomial differentiate(Polynomial *pl)
{
    Polynomial rs;
    Polynomial::iterator p;
    for (p = pl->begin(); p != pl->end(); p++)
    {

        if (p->e == 0)
            return rs;
        rs.push_back({p->c * p->e, p->e - 1});
    }
    return rs;
}

double evaluate(double val, Polynomial *pl)
{
    double rs = 0;
    Polynomial::iterator p;
    for (p = pl->begin(); p != pl->end(); p++)
        rs += p->c * pow(val, p->e);
    return rs;
}

double coefficient(int e, Polynomial *pl)
{
    Polynomial::iterator p;
    for (p = pl->begin(); p != pl->end(); p++)
        if (p->e == e)
            return p->c;
    return 0;
}