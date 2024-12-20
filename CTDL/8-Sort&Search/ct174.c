#include <stdio.h>

void sort(int *a, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i; j < n - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int tempData = a[i];
                a[i] = a[j];
                a[j] = tempData;
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
