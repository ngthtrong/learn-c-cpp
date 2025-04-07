#include <iostream>
#include <list>   //to use list class
#include <string> //to use string class
using namespace std;

// 1. Define Student struct

struct Student
{
    string name;
    int mark;
};

void printList(list<Student> &L)
{
    //     list<Student>::iterator it;
    for (list<Student>::iterator it = L.begin(); it != L.end(); it++)
        cout << it->name << ": " << it->mark << endl;
    cout << "---END---" << endl;
}

int main()
{
    // 2. Create a list L to store students using list<Student> class
    list<Student> L; // create an empty list to store Students

    // 3. Insert 5 students into L in ordered of its occurrence
    L.push_back({"Harry Potter", 10});    // append {"Harry Potter", 10} to L
    L.push_back({"Hermione Granger", 8}); // append {"Harry Potter", 10} to L
    L.push_back({"Draco Malfoy", 7});     // append {"Harry Potter", 10} to L
    L.push_back({"Luna Lovegood", 8});    // append {"Harry Potter", 10} to L
    L.push_back({"Ron Weasley", 9});
    printList(L);
    list<Student>::iterator it = L.begin();
    L.insert(++it, {"Gini Weasley", 6});
    printList(L);
    L.erase(++it);
    printList(L);

    string s;
    getline(cin, s); // read a line and assign to string s
    it = L.begin();
    for (it = L.begin(); it != L.end(); it++)
        if (s == it->name) // compare two strings
            cout << it->mark << endl;

    return 0;
}
