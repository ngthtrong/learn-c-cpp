#include <stdio.h>
#include <string.h>

int sort(int A[], int n)
{
  int count = 0;
  int swapped = 1;
  while (swapped)
  {
    swapped = 0;
    count++;
    for (int i = 0; i < n - 2; i++)
    {
      if (A[i] > A[i + 1])
      {
        int temp = A[i];
        A[i] = A[i + 1];
        A[i + 1] = temp;
        swapped = 1;
      }
    }
  }
  return count;
}