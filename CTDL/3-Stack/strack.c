#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//------------------//
#define MaxLength 100
typedef struct
{
  int DuLieu[MaxLength];
  int Dinh;
} NganXep;
int ktDay(NganXep s)
{
  if (s.Dinh == 0)
    return 1;
  else
    return 0;
}
int giatriDinh(NganXep s)
{
  return s.DuLieu[s.Dinh - 1];
}
int ktRong(NganXep s)
{
  if (s.DuLieu[s.Dinh - 1])
    return 1;
  else
    return 0;
}
void xoa(NganXep *ps)
{
  if (!(ps->DuLieu[ps->Dinh - 1]))
  {
    ps->Dinh = 100;
  }
}
void hienthi(NganXep *ps)
{
  int flag = ktRong(*ps);
  while (!flag)
  {
    int temp = giatriDinh(*ps);
    printf("%d ", temp);
    xoa(ps);
    flag = ktRong(*ps);
  }
}