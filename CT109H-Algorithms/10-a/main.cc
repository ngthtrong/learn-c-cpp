#include <iostream>
#include <algorithm>
using namespace std;

int a[100000];

int maxSubArray(int l, int r)
{
    if (l == r)
    {
        return a[l];
    }
    int m = (l + r) / 2;
    int lmax = maxSubArray(l, m);
    int rmax = maxSubArray(m + 1, r);

    // Calculate the maximum subarray crossing the middle
    // First, find max suffix sum in left half
    int leftSum = 0;
    int maxLeftSum = -999999;
    for (int i = m; i >= l; i--)
    {
        leftSum += a[i];
        maxLeftSum = max(maxLeftSum, leftSum);
    }

    // Find max prefix sum in right half
    int rightSum = 0;
    int maxRightSum = -999999;
    for (int i = m + 1; i <= r; i++)
    {
        rightSum += a[i];
        maxRightSum = max(maxRightSum, rightSum);
    }

    // Maximum crossing sum
    int crossSum = maxLeftSum + maxRightSum;
    
    return max(max(lmax, rmax), crossSum);
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout<< maxSubArray(0, n-1)<<endl;

    return 0;
}




///////////////
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

const int MAXN = 1000000; // Support up to 10^6 elements
int a[MAXN];

// Non-recursive O(n) Kadane's algorithm implementation
int maxSubArray(int n)
{
    int maxSoFar = INT_MIN;
    int maxEndingHere = 0;
    
    for (int i = 0; i < n; i++)
    {
        maxEndingHere = max(a[i], maxEndingHere + a[i]);
        maxSoFar = max(maxSoFar, maxEndingHere);
    }
    
    return maxSoFar;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cout << maxSubArray(n) << endl;

    return 0;
}



