#include <iostream>
#include <list> //to use class vector
using namespace std;

void printList(list<int> l)
{

    cout << l.front();
    for (auto i = ++l.begin(); i != l.end(); ++i)
    {
        cout << ", " << *i;
    }
    cout << endl;
}
int main()
{
    list<int> L; // create an empty list
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        L.push_back(temp);
    }
    printList(L);

    list<int>::iterator it = L.begin();
    advance(it, 3);
    L.insert(it, 20);
    printList(L);

    L.pop_front();
    printList(L);
    int x;
    cin >> x;
    int temp = 1;
    for (auto i = L.begin(); i != L.end(); ++i)
    {
        temp++;
        if (*i == x)
        {
            cout << temp;
            break;
        }
    }

    return 0;
}