#include <stdio.h>
#include <string.h>

typedef struct Student
{
  char Code[10];
  char Name[50];
} Student;

void normalReadClass(Student *m01, int n)
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

void readByFile(Student *m01, int n)
{
  FILE *f = fopen("data.txt", "r");
  if (f == NULL)
  {
    perror("Error opening file");
    return;
  }
  for (int i = 0; i < n; i++)
  {
    fgets(m01[i].Code, 10, f);
    if (m01[i].Code[strlen(m01[i].Code) - 1] == '\n')
      m01[i].Code[strlen(m01[i].Code) - 1] = '\0';
    fgets(m01[i].Name, 50, f);
    if (m01[i].Name[strlen(m01[i].Name) - 1] == '\n')
      m01[i].Name[strlen(m01[i].Name) - 1] = '\0';
  }
  fclose(f);
}

void printClass(Student *m01, int n)
{
  for (int i = 0; i < n; i++)
  {
    printf("%2d: %s - %s\n", i + 1, m01[i].Code, m01[i].Name);
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
    for (int j = n - 1; j > i; j--)
    {
      if (strcmp(m01[j - 1].Code, m01[j].Code) > 0)
        swap(m01, j, j - 1);
    }
  }
  printClass(m01, n);
}

int main()
{
  int n;
  printf("Nhap si so lop: ");
  scanf("%d", &n);
  Student m01[n];
  readByFile(m01, n);
  // normalReadClass(m01, n);
  sort(m01, n);
}
