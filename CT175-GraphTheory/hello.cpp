#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
   vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
   int a =0;
   a= 1;
   cout<<a<<endl;
   for (const string& word : msg)
   {
      cout << word << " ";
   }
   cout << endl;
}
