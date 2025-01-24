#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSort(vector<int> A)
{
    int n = A.size();
    if (n <= 1)
        return A;

    int m = n / 2;
    vector<int> L = mergeSort(vector<int>(A.begin(), A.begin() + m));
    vector<int> R = mergeSort(vector<int>(A.begin() + m, A.end()));
    vector<int> K;
    // Trộn 2 danh sách L và R thành danh sách K
    long unsigned int i = 0, j = 0;
    while (i < L.size() && j < R.size())
    {
        if (L[i] < R[j])
        {

            K.push_back(L[i]);
            i++;
        }
        else
        {

            K.push_back(R[j]);
            j++;
        }
    }

    while (i < L.size())
    {
        K.push_back(L[i]);
        i++;
    }
    while (j < R.size())
    {
        K.push_back(R[j]);
        j++;
    }

    return K;
}

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
