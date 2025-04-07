#include <iostream>
#include <list>   //to use list class
#include <string> //to use string class
using namespace std;

// 1. Define Student struct

void printList(list<pair<string, int>> &L)
{
    //     list<Student>::iterator it;
    for (list<pair<string, int>>::iterator it = L.begin(); it != L.end(); it++)
        cout << it->first << ": " << it->second << endl;
    cout << "---END---" << endl;
}

int main()
{
    // 2. Create a list L to store students using list<Student> class
    list<pair<string, int>> L; // create an empty list to store Students

    // 3. Insert 5 students into L in ordered of its occurrence
    L.push_back(make_pair("Harry Potter", 10));    // append {"Harry Potter", 10} to L
    L.push_back(make_pair("Hermione Granger", 8)); // append {"Harry Potter", 10} to L
    L.push_back(make_pair("Draco Malfoy", 7));     // append {"Harry Potter", 10} to L
    L.push_back(make_pair("Luna Lovegood", 8));    // append {"Harry Potter", 10} to L
    L.push_back(make_pair("Ron Weasley", 9));
    printList(L);
    list<pair<string, int>>::iterator it = L.begin();
    L.insert(++it, {"Gini Weasley", 6});
    printList(L);
    L.erase(it);
    printList(L);

    string s;
    getline(cin, s); // read a line and assign to string s
    it = L.begin();
    for (it = L.begin(); it != L.end(); it++)
        if (s == it->first) // compare two strings
            cout << it->second << endl;

    return 0;
}
