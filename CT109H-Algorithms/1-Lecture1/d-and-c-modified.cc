/*
Author: PHAM Nguyen Khang
Date: 7 Jan 2018
Optimized version
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

//Grade school multiplication (optimized version)
Number naive_multiply(const Number& a, const Number& b) {
	Number res(a.size() + b.size());
	
	for (int i = 0; i < a.size(); i++)
		for (int j = 0; j < b.size(); j++)
			res[i+j] += a[i]*b[j];

	return res;
}

//Multiplication of two big integer
//Recursive version
//size(a) == size(b)
Number multiply(const Number& x, const Number& y) {
	//only one digit
	int len = x.size();
	Number result(2*len);
	
	if (len <= 4) { //should be changed to 64
		return naive_multiply(x, y);
	}
	//brake x and y
	//x = a*10^n/2 + b
	//y = c*10^n/2 + d


	int k = len/2;	
	Number b(x.begin(), x.begin() + k);
	Number a(x.begin() + k, x.end());
	Number d(y.begin(), y.begin() + k);
	Number c(y.begin() + k, y.end());
	
	Number ac = multiply(a, c);
	Number ad = multiply(a, d);
	Number bc = multiply(b, c);
	Number bd = multiply(b, d);
	
	//x*y = ac*10^n + (ad + bc)*10^n/2 + bd


	for (int i = 0; i < len; ++i) {
    	result[i] = bd[i];
    }

	for (int i = len; i < 2 * len; ++i) {
    	result[i] = ac[i - len];
    }

    for (int i = k; i < len + k; ++i) {
    	result[i] += ad[i-k] + bc[i-k];
    }

	return result;
}


void extend_vec(Number& v, size_t len) {    
    while (len & (len - 1)) {
    	++len;
    }
    // find k>=l such that k is power of 2
	v.resize(len);
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
	extend_vec(a, n);
	extend_vec(b, n);

	print_number(a);
	print_number(b);

	Number d = multiply(a, b);
	finalize(d);

	cout << "a * b = ";
	print_number(d);

	return 0;
}