#include <stdio.h>
#include <string.h>

typedef struct Student
{
  int Code;
  char Name[50];
} Student;

void readClass(Student *m01, int n)
{
  for (int i = 0; i < n; i++)
  {
    scanf("%d\n", &m01[i].Code);
    fgets(m01[i].Name, 50, stdin);
    if (m01[i].Name[strlen(m01[i].Name) - 1] == '\n')
      m01[i].Name[strlen(m01[i].Name) - 1] = '\0';
  }
}

void readFile(Student *m01, int n)
{
  FILE *f = fopen("data.txt", "r");
  if (f == NULL)
  {
    perror("Error opening file");
    return;
  }
  for (int i = 0; i < n; i++)
  {
    fscanf(f,"%d\n", &m01[i].Code);
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
    printf("%2d: %5d - %s\n", i + 1, m01[i].Code, m01[i].Name);
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
      if (m01[j - 1].Code > m01[j].Code)
        swap(m01, j - 1, j);
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
  readFile(m01, n);
  // readClass(m01, n);
  sort(m01, n);
}
