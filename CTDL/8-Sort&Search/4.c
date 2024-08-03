#include <stdio.h>
#include <stdlib.h>
typedef struct
{
  int pos;
  int dir;
} Student;

int cmp(const void *a, const void *b)
{
  return ((Student *)a)->pos - ((Student *)b)->pos;
}

int main()
{
  int n, m, t;
  scanf("%d %d %d", &n, &m, &t);
  Student student[m];
  for (int i = 0; i < m; i++)
    scanf("%d %d", student[i].pos, student[i].dir);
  for (int i = 0; i < m; i++)
    student[i].pos = (student[i].pos + student[i].dir * t) % n;

  qsort(student, m, sizeof(Student), cmp);
  for (int i = 0; i < m; i++)
  {
    printf("%d ", student[i].pos);
  }
}
