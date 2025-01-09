#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Student
{
    string name;
    int mark;
};

void static printList(vector<Student> L)
{
    for (auto &&i : L)
    {
        cout << i.name << ": " << i.mark << endl;
    }
    cout << "---END---" << endl;
}

int main(int argc, char const *argv[])
{
    vector<Student> L;
    L.push_back({"Harry Potter", 10});
    L.push_back({"Hermione Granger", 8});
    L.push_back({"Draco Malfoy", 7});
    L.push_back({"Luna Lovegood", 8});
    L.push_back({"Ron Weasley", 9});
    printList(L);
    L.insert(L.begin() + 1, {"Gini Weasley", 6});
    printList(L);
    L.erase(L.begin() + 2);
    printList(L);
    string s;
    getline(cin, s);
    for (auto &&i : L)
    {
        if (i.name == s)
        {
            cout << i.mark << endl;
        }
    }

    return 0;
}
