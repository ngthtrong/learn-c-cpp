#include <stdio.h>

int binarySearch(int A[], int l, int r, int x)
{
  while (l <= r)
  {
    int m = (l + r) / 2;
    if (A[m] == x)
      return 1;
    else if (A[m] < x)
      l = m + 1;
    else
      r = m - 1;
  }
  return 0;
}

int main()
{

  int n, q;
  long long int A[n];
  scanf("%d %d", &n, &q);
  for (int i = 0; i < n - 1; i++)
  {
    scanf("%lld ", &A[i]);
  }
  scanf("%lld", &A[n - 1]);

  for (int i = 0; i < q; i++)
  {
    long long int x;
    scanf("%lld\n", &x);

    int result = binarySearch(A, 0, n - 1, x);
    if (result == 1)
      printf("YES\n");
    else
      printf("NO\n");
  }
}