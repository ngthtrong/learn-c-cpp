#include <stdio.h>
#include <string.h>
typedef struct fan
{
  char name[20];
  long long int tt;
} Fan;

void printMostTt(Fan fan[], int k, int n)
{
  for (int q = 0; q < k; q++)
  {
    long long int most = -2;
    int index;
    for (int i = 0; i < n; i++)
    {
      if (fan[i].tt > most)
      {
        most = fan[i].tt;
        index = i;
      }
      else if (fan[i].tt == most)
      {
        if (strcmp(fan[i].name, fan[index].name) < 0)
          index = i;
      }
    }
    printf("%s\n", fan[index].name);
    fan[index].tt = -1;
  }
}

int main()
{
  int n;
  int k;
  scanf("%d %d\n", &n, &k);
  Fan fan[n];
  for (int i = 0; i < n; i++)
  {
    scanf("%[^ ]%*c", fan[i].name);
    if (fan[i].name[strlen(fan[i].name) - 1] == ' ' || fan[i].name[strlen(fan[i].name) - 1] == '\n' || fan[i].name[strlen(fan[i].name) - 1] == '\r')
    {
      fan[i].name[strlen(fan[i].name) - 1] = '\0';
    }
    if (i == n - 1)
      scanf(" %lld", &fan[i].tt);
    else
      scanf(" %lld\n", &fan[i].tt);
  }
  printMostTt(fan, k, n);
  return 0;
}