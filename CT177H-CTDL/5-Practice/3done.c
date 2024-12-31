#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MaxLength 50;
//------------------//
typedef struct
{
  char elements[30];
  int top;
} Stack;

void makenull(Stack *pS);

int stackEmpty(Stack s)
{
  if (s.elements[s.top] == '\0')
    return 1;
  else
    return 0;
  return -1;
}
int indexChar(char op)
{
  if (op == '+' || op == '-')
    return 1;
  else if (op == '*' || op == '/')
    return 2;
  return -1;
}
void to_posfix(char st[], char st_out[])
{
  Stack s;
  makenull(&s);
  int j = 0;
  for (int i = 0; st[i] != '\0'; i++)
  {
    int temp = st[i];
    if ((temp >= 65 && temp <= 90) || (temp >= 97 && temp <= 112))
    {
      st_out[j] = st[i];
      j++;
    }
    else if (temp == 40)
    {
      push(st[i], &s);
    }
    else if (temp == 41)
    {
      char tempTop = top(s);
      while (tempTop != '(')
      {
        st_out[j] = tempTop;
        j++;
        pop(&s);
        tempTop = top(s);
      }
      pop(&s);
    }
    else if (temp == 42 || temp == 43 || temp == 45 || temp == 47)
    {
      char tempInStack = top(s);
      int flag = indexChar(st[i]) - indexChar(tempInStack);
      int isEmpty = stackEmpty(s);
      while (!isEmpty && tempInStack != '(' && flag <= 0)
      {
        st_out[j] = tempInStack;
        j++;
        pop(&s);
        tempInStack = top(s);
        isEmpty = stackEmpty(s);
        flag = indexChar(temp) - indexChar(tempInStack);
      }
      push(st[i], &s);
    }
  }
  int isEmpty = stackEmpty(s);
  while (!isEmpty)
  {
    char temp = top(s);
    st_out[j] = temp;
    j++;
    pop(&s);
    isEmpty = stackEmpty(s);
  }
  st_out[j] = '\0';
}
