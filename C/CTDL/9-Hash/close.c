#include <stdio.h>

#define B 100
#define Deleted -1000
#define Empty 1000
typedef int ElementType;
typedef ElementType Dictionary[B];

void print(Dictionary d)
{
  printf("DIC:");
  for (int i = 0; i < B; i++)
  {
    if (d[i] != Empty || d[i] != Deleted)
      printf("%5d ", d[i]);
  }
}

void makenull(Dictionary d)
{
  for (int i = 0; i < B; i++)
  {
    d[i] = Empty;
  }
}

int full(Dictionary d)
{
  for (int i = 0; i < B; i++)
  {
    if (d[i] == Empty || d[i] == Deleted)
      return 0;
  }
  return 1;
}

int h(ElementType x)
{
  return x % B;
}

int member(ElementType x, Dictionary d)
{
  if (d[h(x)] == x)
    return 1;
  return 0;
}

void delete(ElementType x, Dictionary d)
{
  if (empty(d))
    printf("\nBang bam rong");
  else if (member(x, d))
  {
    if (d[h(x)] == x)
      d[h(x)] = Deleted;
    else
    {
      int temp = h(x);
      for (int i = 0; i < B; i++)
      {
        temp = (temp + i) % B;
        if (d[temp] == x)
        {
          d[temp] = Deleted;
          break;
        }
      }
    }
  }
}

void insert(ElementType x, Dictionary d)
{
  if (full(d))
    printf("Bang bam day");
  else if (member(x, d))
    printf("\nPhan tu %d da ton tai trong bang bam", x);
  else
  {
    if (d[h(x)] == Empty)
      d[h(x)] = x;
    else
      printf("Vi tri %d da ton tai trong bang bam", x);
  }
}
