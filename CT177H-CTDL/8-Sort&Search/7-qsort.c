#include <stdio.h>
#include <stdlib.h>
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
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
  int n;
  scanf("%d", &n);
  int a[n];
  for (int i = 0; i < n - 1; i++)
    scanf("%d ", &a[i]);
  scanf("%d", &a[n - 1]);
  qsort(a, n, sizeof(int), cmp);
  printArray(a, n);
}