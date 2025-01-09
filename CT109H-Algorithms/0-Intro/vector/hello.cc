#include <iostream>
#include <bits/stdc++.h>
#include <vector> //to use vector class
using namespace std;

void static print(vector<int> L)
{
    for (auto& i : L)
        if (&i != &L.back())
            cout << i << ", ";
        else
            cout << i;
    cout << endl;
}

int main()
{
    // 1. Create an empty list L to store integer using vector<int> class.
    vector<int> L; // create an empty list

    // 2. Read n integer from stdin and append them to L
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        L.insert(L.end(), temp);
    }

    // 3. Print elements of L in format: a1, a2, a3
    print(L);

    // 4.Insert 20 at the 4th position on L
    L.insert(L.begin() + 3, 20);
    print(L);

    L.erase(L.begin());
    print(L);

    int x;
    cin >> x;
    cout << find(L.begin(), L.end(), x) - L.begin() + 1;

    return 0;
}