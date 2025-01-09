/*
	Author: Pham Nguyen Khang
	Date: 7 Jan 2018
	Grade school multiplication (optimized version)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<int> Number;

//Store a number as an array of digits in reverse order
//e.g: 473 will store as
//index:     2  1  0
//array:    [4, 7, 3]
//or
//index:     0  1  2
//array:    [3, 7, 4]

void print_number(const Number& a) {
	for (int i = a.size() - 1; i >= 0; i--)
		cout << a[i];
	cout << endl;
}

//Multiplication of two big integer
// n.....3210
// aaaaaaaaaa
//     bbbbbb
//-----------
//       b[0]*a
//     b[1]*a*10
//   b[2]*a*100
//...

Number multiply(Number a, Number b) {
	Number res(a.size() + b.size());
	
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			res[i+j] += a[i]*b[j];

	return res;
}

#define base 10

void finalize(Number& res) {
	for (int i = 0; i < res.size(); ++i) {
    	res[i + 1] += res[i] / base;
        res[i] %= base;
    }
}


int main() {
	Number a, b;
	string s1, s2;
	cout << "Enter two big numbers: ";
	cin >> s1 >> s2;
	
	for (int i = s1.size() - 1; i >= 0; i--)
		a.push_back(s1[i] - '0');

	for (int i = s2.size() - 1; i >= 0; i--)
		b.push_back(s2[i] - '0');
		
	int n = std::max(a.size(), b.size());
	//extend_vec(a, n);
	//extend_vec(b, n);

	print_number(a);
	print_number(b);

	Number d = multiply(a, b);
	finalize(d);

	cout << "a * b = ";
	print_number(d);
	
	return 0;
}
