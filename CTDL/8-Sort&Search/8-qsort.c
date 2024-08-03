#include <stdio.h>
#include <stdlib.h>

void printArr(long int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%ld ", arr[i]);
  printf("\n");
}

int cmp(const void *ptr1, const void *ptr2)
{
  int *x = (int *)ptr1;
  int *y = (int *)ptr2;
  return *x - *y;
}

int main()
{
  int n, k;
  scanf("%d %d", &n, &k);
  long int arr[n];
  for (int i = 0; i < n - 1; i++)
    scanf("%ld ", &arr[i]);
  scanf("%ld", &arr[n - 1]);
  qsort(arr, n, sizeof(long int), cmp);
  int long long total = 0;
  for (int i = 0; i < k; i++)
    total += arr[i];
  printf("%lld ", total);
  total = 0;
  for (int i = n - 1; i > n - k - 1; i--)
    total += arr[i];
  printf("%lld\n", total);
  return 0;
}