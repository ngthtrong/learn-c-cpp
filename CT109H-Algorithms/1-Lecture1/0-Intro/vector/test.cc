#include <iostream>
#include <vector> //to use vector class
using namespace std;

int main()
{
    // 1. Create an empty list L to store integer using vector<int> class.
    vector<int> L; // create an empty list
    int n, x;

    // 2. Read n integer from stdin and append them to L
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        L.push_back(tmp);
        // read an integer and append it to L using push_back() function
    }

    // 3. Print elements of L in format: a1, a2, a3
    for (int i = 0; i < L.size(); i++)
    {
        if (i > 0)
        {
            cout << ", ";
        }
        cout << L[i];
    }
    cout << endl;

    // 4. Insert 20 at the 4th position on L
    if (L.size() >= 4)
    {
        L.insert(L.begin() + 3, 20);
    }

    // 5. Print elements of L
    for (int i = 0; i < L.size(); i++)
    {
        if (i > 0)
        {
            cout << ", ";
        }
        cout << L[i];
    }
    cout << endl;

    // 6. Delete the 1st element
    L.erase(L.begin());

    // 7. Print elements of L
    for (int i = 0; i < L.size(); i++)
    {
        if (i > 0)
            cout << ", ";
        cout << L[i];
    }
    cout << endl;

    // 8. Print the position of x (x is read from stdin)
    cin >> x;
    bool find = false;
    for (int i = 0; i < n; i++)
    {
        if (L[i] == x)
        {
            cout << i+1 << endl;
            find = true;
            break;
        }
    }

    return 0;
}