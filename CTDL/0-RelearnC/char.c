#include <stdio.h>
#include <string.h>

typedef struct Student
{
  char Code[10];
  char Name[50];
} Student;

void readClass(Student *m01, int n)
{
  for (int i = 0; i < n; i++)
  {
    fgets(m01[i].Code, 10, stdin);
    if (m01[i].Code[strlen(m01[i].Code) - 1] == '\n')
      m01[i].Code[strlen(m01[i].Code) - 1] = '\0';
    fgets(m01[i].Name, 50, stdin);
    if (m01[i].Name[strlen(m01[i].Name) - 1] == '\n')
      m01[i].Name[strlen(m01[i].Name) - 1] = '\0';
  }
}

void printClass(Student *m01, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%d: %s - %s\n", i + 1, m01[i].Code, m01[i].Name);
  }
}

void swap(Student *m01, int a, int b)
{
  Student temp = m01[a];
  m01[a] = m01[b];
  m01[b] = temp;
}

void sort(Student *m01, int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int temp = i;
    for (int j = n - 1; j > i; j--)
    {
      if (strcmp(m01[j - 1].Code, m01[j].Code) > 0)
        temp = j;
    }
    swap(m01, temp, i);
  }
  printClass(m01, n);
}

int main()
{
  int n;
  printf("Nhap si so lop: ");
  scanf("%d\n", &n);
  Student m01[n];
  readClass(m01, n);
  sort(m01, n);
}
