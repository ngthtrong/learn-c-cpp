#include <stdio.h>
#include <iostream>
using namespace std;
// Cài đặt thuật toán sắp xếp xen
void insertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        // Các phần tử từ A[0] đến A[i-1] đã được sắp xếp tăng dần
        // Xen phần tử A[i] vào vị trí thích hợp để các phần tử
        // từ A[0] đến A[i] được sắp xếp tăng dần
        for (int j = i; j > 0; j--)
        {
            if (A[j] < A[j - 1])
            {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
            }
        }
    }

    // In các phần tử trong mảng A để kiểm tra việc xen
    for (int j = 0; j < n; j++)
        cout << A[j] << ' ';
    cout << endl;
}
