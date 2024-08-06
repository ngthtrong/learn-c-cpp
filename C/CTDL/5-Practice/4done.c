#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 50
//------------------//
typedef struct
{
  int Elements[MaxLength];
  int Top_idx;
} Stack;

void makeNull(Stack *s)
{
  s->Top_idx = MaxLength;
  s->Elements[s->Top_idx - 1] = '\0';
}

int top(Stack s)
{
  return s.Elements[s.Top_idx];
}

void push(int n, Stack *pS)
{
  pS->Top_idx--;
  pS->Elements[pS->Top_idx] = n;
}
void pop(Stack *pS)
{
  pS->Elements[pS->Top_idx] = '\0';
  pS->Top_idx++;
}

int calcPostfix(char st[])
{
  Stack s;
  makeNull(&s);
  char tempNum[4];
  int indexTempNum = 0;
  for (int i = 0; st[i] != '\0'; i++)
  {
    int temp = st[i];
    if (temp >= 48 && temp <= 57)
    {
      tempNum[indexTempNum] = st[i];
      if (st[i + 1] == ' ')
      {
        int n = atoi(tempNum);
        push(n, &s);
        indexTempNum = 0;
        for (int j = 0; j < 4; j++)
        {
          tempNum[j]='\0';
        }
        
      }
      else
      {
        indexTempNum++;
      }
    }
    else if (temp == 42 || temp == 43 || temp == 45 || temp == 47)
    {
      int n1 = top(s);
      pop(&s);
      int n2 = top(s);
      pop(&s);
      if (temp == 42)
      {
        push(n2 * n1, &s);
      }
      if (temp == 43)
      {
        push(n2 + n1, &s);
      }
      if (temp == 45)
      {
        push(n2 - n1, &s);
      }
      if (temp == 47)
      {
        push(n2 / n1, &s);
      }
    }
  }
  int n = top(s);
  return n;
}
int main()
{
  char stIn[50];
  fgets(stIn, 50, stdin);
  if (stIn[strlen(stIn) - 1] == '\n')
    stIn[strlen(stIn) - 1] = '\0';

  int rs = calcPostfix(stIn);
  printf("%d", rs);
}