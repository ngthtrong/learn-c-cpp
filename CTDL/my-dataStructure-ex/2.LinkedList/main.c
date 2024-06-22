typedef struct SinhVien
{
   char mssv[10];
   char name[50];
   float lt, tt1, tt2;
} SinhVien;
typedef struct List
{
   SinhVien A[40];
   int n;
} List;