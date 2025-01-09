/*
* MERGE SORT Implementation

* Author: Pham Nguyen Khang
*/

#include <iostream>
#include <vector>
#include <stdlib.h> /* srand, rand */
#include <time.h>	/* time */

using namespace std;

// Sort array [begin, end)
// from begin to BEFORE end
void merge_sort(int *begin, int *end)
{
	if (begin + 1 == end) // only one item
		return;

	int *mid = begin + (end - begin) / 2;

	// recursively call to sort left part [begin, mid) and right part [mid, end)
	merge_sort(begin, mid);
	merge_sort(mid, end);

	// merge
	int *left = begin;
	int *right = mid;

	vector<int> tmp;
	tmp.reserve(end - begin);
	while (left < mid && right < end)
	{
		if (*left < *right)
		{
			tmp.push_back(*left);
			left++;
		}
		else
		{
			tmp.push_back(*right);
			right++;
		}
	}

	while (left < mid)
	{
		tmp.push_back(*left);
		left++;
	}

	while (right < end)
	{
		tmp.push_back(*right);
		right++;
	}

	copy(tmp.begin(), tmp.end(), begin);
}

/////////////////////
// You could define some addition functions here

int select(int A[], int n, int k)
{
	// return the kth-smalest element of A
	// k = 1, 2, 3, ..., n

	// Your code goes here
}
//////////////////////

int main()
{

	// test with small array
	int C[] = {5, 6, 8, 2, 4, 3, 7, 2, 8, 1};
	merge_sort(C, C + 10);
	for (int i = 0; i < 10; i++)
		cout << C[i] << ' ';
	cout << endl;

	// compare to std::sort
	vector<int> A;
	srand(time(0));
	for (int i = 0; i < 100000; i++)
		A.push_back(rand());

	vector<int> B = A;

	merge_sort(&A[0], &A[0] + 100000);

	std::sort(B.begin(), B.end());

	if (A != B)
		cout << "fail\n";
	else
		cout << "okie!\n";

	return 0;
}
