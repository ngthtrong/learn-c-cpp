#include <stdio.h>

void swap(long int *arr, int a, int b)
{
  long int temp = *(arr + a);
  *(arr + a) = *(arr + b);
  *(arr + b) = temp;
}
void printArr(long int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%ld ", arr[i]);
  printf("\n");
}

void bubbleSort(long int *arr, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    if (arr[i] > arr[i + 1])
    {
      swap(arr, i, i + 1);
      for (int j = i; arr[j] < arr[j - 1] && j > 0; j--)
        swap(arr, j, j - 1);
    }
  }
}

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  long int arr[n];
  for (int i = 0; i < n - 1; i++)
    scanf("%ld ", &arr[i]);
  scanf("%ld", &arr[n - 1]);
  bubbleSort(arr, n);
  int long long total = 0;
  for (int i = 0; i < k; i++)
    total += arr[i];
  printf("%lld ", total);
  total = 0;
  for (int i = n - 1; i > n - k; i--)
    total += arr[i];
  printf("%lld\n", total);

  return 0;
}