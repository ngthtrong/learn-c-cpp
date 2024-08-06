#include <stdio.h>
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
void insertionSort(int a[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    if (a[i] > a[i + 1])
    {
      int key = a[i + 1];
      a[i + 1] = a[i];
      a[i] = key;
      for (int j = i - 1; j >= 0; j--)
      {
        if (key < a[j])
        {
          a[j + 1] = a[j];
          a[j]=key;
        }
      }
    }
    printArray(a, n);
  }
}
int main()
{
  int n;
  scanf("%d", &n);
  int arr[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &arr[i]);
  printArray(arr, n);
  insertionSort(arr, n);
  return 0;
}