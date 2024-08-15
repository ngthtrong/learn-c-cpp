#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void *ptr1, const void *ptr2)
{
  int *x = (int *)ptr1;
  int *y = (int *)ptr2;
  return *x - *y;
}
int binarySearch(long int arr[], int l, int r, long int x)
{
  while (l <= r)
  {
    int mid = l + (r - l) / 2;
    if (arr[mid] == x)
      return 1;
    if (arr[mid] < x)
      l = mid + 1;
    else
      r = mid - 1;
  }
  return 0;
}

void printArr(long int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%ld ", arr[i]);
  printf("\n");
}

int main()
{
  int n;
  int q;
  scanf("%d %d", &n, &q);
  long int a[n];
  for (int i = 0; i < n - 1; i++)
    scanf("%ld ", &a[i]);
  scanf("%ld", &a[n - 1]);
  qsort(a, n, sizeof(long int), cmp);
  for (int i = 0; i < q; i++)
  {
    int x;
    scanf("%lld ", &x);
    int result = binarySearch(a, 0, n - 1, x);
    if (result)
      printf("YES\n");
    else
      printf("NO\n");
  }
  return 0;
}