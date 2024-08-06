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

void selSort(int a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int temp = i;
    for (int j = temp + 1; j < n; j++)
    {
      if (a[temp] > a[j])
        temp = j;
    }
    swap(a, i, temp);
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
  selSort(a, n);
}