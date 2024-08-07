#include <stdio.h>
#include <string.h>

typedef struct Student
{
  char Code[10];
  char Name[50];
} Student;

void readClass(Student **m, int n)
{
}
void printClass(Student m[], int n)
{
}

void sort()
{
}

int main()
{
  int n;
  printf("Nhap si so lop: ");
  scanf("%d", &n);
  Student m01[n];
  for (int i; i < n; i++)
  {
    strcpy(m01[i].Code, "2305615");
    strcpy(m01[i].Name, "Thanh Trong");
  }
  for (int i = 0; i < n; i++)
  {
    printf("%d: %s %s\n", i, m01[i].Code, m01[i].Name);
  }
}
// fgets(m01[i].Name, 50, stdin);
// if (m01[i].Name[strlen(m01[i].Name) - 1] == '\n')
//   m01[i].Name[strlen(m01[i].Name) - 1] = '\0';
