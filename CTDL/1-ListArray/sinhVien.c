#include <stdio.h>
#include <string.h>
typedef struct SinhVien
{
   char MSSV[10];
   char HoTen[50];
   float DiemLT, DiemTH1, DiemTH2;
} SinhVien;
typedef struct ListSV
{
   struct SinhVien A[40];
   int n;
} ListSV;
int checkNull(ListSV l)
{
   if (!l.n)
   {
      return 1;
   }

   return 0;
}
void deleteByMSSV(char mssv[], ListSV *pl)
{
   int n = tim(mssv, *pl);
   deleteByPosition(n, pl);
}
void printSV(SinhVien sv)
{
   printf("%s - %s - %.2f - %.2f - %.2f\n", sv.MSSV, sv.HoTen, sv.DiemLT, sv.DiemTH1, sv.DiemTH2);
}
void searchByMSSV(char mssv[], ListSV l)
{
   int i;
   for (i = 0; i < l.n; i++)
   {
      if (!strcmp(mssv, l.A[i].MSSV))
      {
         break;
      }
   }
   if (i < l.n){
      printf("Tim thay sinh vien %s. Thong tin sinh vien:\n", mssv);
      printSV(l.A[i]);
   }
   else
      printf("Khong tim thay sinh vien %s", mssv);
}
void deleteByPosition(int x, ListSV *pl)
{
   if (x <= pl->n && x > 0)
   {
      for (int i = x - 1; i < pl->n; i++)
      {
         pl->A[i] = pl->A[i + 1];
      }
      pl->n--;
   }
}
ListSV readListSV()
{
   ListSV L;
   scanf("%d\n", &L.n);
   for (int i = 0; i < L.n; i++)
   {
      struct SinhVien a;
      scanf("%[^\n]%*c", a.MSSV);
      int flag = 0;
      for (int j = 0; j < i; j++)
      {
         if (!strcmp(a.MSSV, L.A[j].MSSV))
         {
            flag = 1;
            L.n--;
         }
      }
      if (flag)
         continue;
      scanf("%[^\n]%*c", a.HoTen);
      scanf("%f %f %f\n", &a.DiemLT, &a.DiemTH1, &a.DiemTH2);
      L.A[i] = a;
   }
   return L;
}
void printList(ListSV l)
{
   for (int i = 0; i < l.n; i++)
   {
      struct SinhVien sv = l.A[i];
      printf("%s - %s - %.2f - %.2f - %.2f\n", sv.MSSV, sv.HoTen, sv.DiemLT, sv.DiemTH1, sv.DiemTH2);
   }
}
void printSVPass(ListSV l)
{
   printf("Sinh vien DAT\n");
   for (int i = 0; i < l.n; i++)
   {
      struct SinhVien sv = l.A[i];
      if (sv.DiemLT + sv.DiemTH1 + sv.DiemTH2 >= 4)
         printf("%s - %s - %.2f - %.2f - %.2f - %.2f\n", sv.MSSV, sv.HoTen, sv.DiemLT, sv.DiemTH1, sv.DiemTH2, sv.DiemLT + sv.DiemTH1 + sv.DiemTH2);
   }
}
int main()
{
   ListSV L = readListSV();
   printList(L);
   char mssv[10];
   scanf("%[^\n]%*c", mssv);
   searchByMSSV(mssv,L);
}