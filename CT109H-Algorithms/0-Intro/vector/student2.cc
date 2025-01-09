#include <iostream>
#include <vector> //to use vector class
#include <string> //to use string class
using namespace std;

typedef struct
{
    string name;
    int mark;
} Student;

void static printList(vector<pair<string, int>> L)
{
    for (int i = 0; i < L.size(); i++)
    {
        cout << L[i].first << ": " << L[i].second << endl;
    }
    cout << "---END---" << endl;
}

int main()
{

    // 1. Create a list L to store students using class vector< pair<string, int> >
    vector<pair<string, int>> L; // create an empty list to store Students

    // 2. Insert 5 students into L in ordered of its occurrence
    L.push_back(make_pair("Harry Potter", 10));    // append {"Harry Potter", 10} to L
    L.push_back(make_pair("Hermione Granger", 8)); // append {"Harry Potter", 10} to L
    L.push_back(make_pair("Draco Malfoy", 7));     // append {"Harry Potter", 10} to L
    L.push_back(make_pair("Luna Lovegood", 8));    // append {"Harry Potter", 10} to L
    L.push_back(make_pair("Ron Weasley", 9));      // append {"Harry Potter", 10} to L

    printList(L);

    L.insert(L.begin() + 1, make_pair("Gini Weasley",6));

    printList(L);
    L.erase(L.begin() + 2);
    printList(L);

    string s;
    getline(cin, s); // read a line and assign to string s
    for (int i = 0; i < L.size(); i++)
        if (s == L[i].first) // compare two strings
            cout << L[i].second << endl;

    return 0;
}