#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

typedef struct
{
    double c; // coefficients
    int e;    // exponents
} ElementType;

typedef vector<ElementType> Polynomial; // declares the data structure Polynomial

void printPolynomial(Polynomial *pL)
{ // prints the Polynomial pL
    if (pL->size() == 0)
        return;

    cout << std::fixed << setprecision(2); // sets the decimal precision to 2, e.g.: 5.23
    cout << '(' << (*pL)[0].c << ")x^" << (*pL)[0].e;

    for (int i = 1; i < pL->size(); i++)
        cout << setprecision(2) << " + " << '(' << (*pL)[i].c << ")x^" << (*pL)[i].e;

    cout << endl;
}

void insert(double c, int e, Polynomial *pl)
{
    if (pl->size() == 0)
    {
        pl->push_back({c, e});
        return;
    }
    for (int i = 0; i < pl->size(); i++)
    {
        if (e == (*pl)[i].e)
        {
            (*pl)[i].c = c;
            return;
        }
        else if (e > (*pl)[i].e)
        {
            pl->insert(pl->begin() + i, {c, e});
            return;
        }
    }
    pl->push_back({c, e});
}

void delete_e(int e, Polynomial *pl)
{
    for (int i = 0; i < pl->size(); i++)
    {
        if (e == (*pl)[i].e)
        {
            pl->erase(pl->begin() + i);
            return;
        }
    }
    cout << "The exponent does not appear." << endl;
}
Polynomial differentiate(Polynomial *pl)
{
    Polynomial R;
    for (int p = 0; p < pl->size(); p++)
    {
        if ((*pl)[p].e == 0)
            continue;
        else
            R.push_back({(*pl)[p].c * (*pl)[p].e, (*pl)[p].e - 1});
    }
    return R;
}

double evaluate(double val, Polynomial *pl){
    
}