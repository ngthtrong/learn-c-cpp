#include <stdio.h>
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}

void swap(int *arr, int a, int b)
{
  int temp = *(arr + a);
  *(arr + a) = *(arr + b);
  *(arr + b) = temp;
}

void bubSort(int a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int temp = i;
    for (int j = n - 1; j > i; j--)
    {
      if (a[j] < a[j - 1])
        swap(a, j - 1, j);
    }
    printArray(a, n);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n - 1; i++)
    scanf("%d ", &a[i]);
  scanf("%d", &a[n - 1]);
  bubSort(a, n);
}