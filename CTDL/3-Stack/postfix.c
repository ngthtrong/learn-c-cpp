#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//------------------//
typedef struct
{
  char Elements[30];
  int Top_idx;
} Stack;







float tinhGiatri(char st[])
{
  Stack s;
  makenullStack(&s);
  for (int i = 0; st[i] != '\0'; i++)
  {
    int temp = st[i];
    if (temp >= 48 && temp <= 57)
    {
      float n = temp - 48;
      push(n, &s);
    }
    else if (temp == 42 || temp == 43 || temp == 45 || temp == 47)
    {
      float n1 = top(s);
      pop(&s);
      float n2 = top(s);
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
  float n = top(s);
  return n;
}

void chuyenHauto(char trungto[], char hauto[])
{
  Stack s;
  makenullStack(&s);
  int j = 0;
  for (int i = 0; trungto[i] != '\0'; i++)
  {
    int temp = trungto[i];
    if ((temp >= 48 && temp <= 57) || (temp >= 97 && temp <= 112))
    {
      hauto[j] = trungto[i];
      j++;
    }
    else if (temp == 40)
    {
      push(trungto[i], &s);
    }
    else if (temp == 41)
    {
      char topp = top(s);
      while (topp != '(')
      {
        hauto[j] = topp;
        j++;
        pop(&s);
        topp = top(s);
      }
      pop(&s);
    }
    else if (temp == 42 || temp == 43 || temp == 45 || temp == 47)
    {
      char tempInStack = top(s);
      int flag = mucUutien(trungto[i]) - mucUutien(tempInStack);
      int isEmpty = emptyStack(s);
      while (!isEmpty && tempInStack != '(' && flag <= 0)
      {
        hauto[j] = tempInStack;
        j++;
        pop(&s);
        tempInStack = top(s);
        isEmpty = emptyStack(s);
        flag = mucUutien(temp) - mucUutien(tempInStack);
      }
      push(trungto[i], &s);
    }
  }
  int isEmpty = emptyStack(s);
  while (!isEmpty)
  {
    char temp = top(s);
    hauto[j] = temp;
    j++;
    pop(&s);
    isEmpty = emptyStack(s);
  }
  hauto[j] = '\0';
}

void inThaplucphan(int n)
{
  Stack s;
  makenullStack(&s);
  for (int i = n; i != 0; i /= 16)
  {
    int r = (i % 16);
    if (r <= 9)
      r += 48;
    else
      r += 55;
    char temp = r;
    push(temp, &s);
  }
  for (int isEmpty = emptyStack(s); !isEmpty; isEmpty = emptyStack(s))
  {
    char temp = top(s);
    printf("%c", temp);
    pop(&s);
  }
}

int ktChuoi()
{
  char st[50];
  fgets(st, 50, stdin);
  if (st[strlen(st) - 1] == '\n')
    st[strlen(st) - 1] = '\0';
  Stack s;
  makenullStack(&s);
  for (int i = 0; st[i] != '\0'; i++)
  {
    if (st[i] == '(')
      push('(', &s);
    else if (st[i] == ')')
    {
      int isEmpty = emptyStack(s);
      if (!isEmpty)
        pop(&s);
      else
        return 0;
    }
  }
  int isEmpty = emptyStack(s);
  if (!isEmpty)
    return 0;
  else
    return 1;
}

//------------------//
int main()
{
  printf("%d", 0 % 16);
}

//-------------not test yet-------------//

int emptyStack(Stack s)
{
  if (s.Elements[s.Top_idx - 1])
    return 1;
  else
    return 0;
  return -1;
}
int mucUutien(char op)
{
  if (op == '+' || op == '-')
    return 1;
  else if (op == '*' || op == '/')
    return 2;
  return -1;
}
void to_posfix(char trungto[], char hauto[])
{
  Stack s;
  makenull(&s);
  int j = 0;
  for (int i = 0; trungto[i] != '\0'; i++)
  {
    int temp = trungto[i];
    if ((temp >= 48 && temp <= 57) || (temp >= 97 && temp <= 112))
    {
      hauto[j] = trungto[i];
      j++;
    }
    else if (temp == 40)
    {
      push(trungto[i], &s);
    }
    else if (temp == 41)
    {
      char topp = top(s);
      while (topp != '(')
      {
        hauto[j] = topp;
        j++;
        pop(&s);
        topp = top(s);
      }
      pop(&s);
    }
    else if (temp == 42 || temp == 43 || temp == 45 || temp == 47)
    {
      char tempInStack = top(s);
      int flag = mucUutien(trungto[i]) - mucUutien(tempInStack);
      int isEmpty = emptyStack(s);
      while (!isEmpty && tempInStack != '(' && flag <= 0)
      {
        hauto[j] = tempInStack;
        j++;
        pop(&s);
        tempInStack = top(s);
        isEmpty = emptyStack(s);
        flag = mucUutien(temp) - mucUutien(tempInStack);
      }
      push(trungto[i], &s);
    }
  }
  int isEmpty = emptyStack(s);
  while (!isEmpty)
  {
    char temp = top(s);
    hauto[j] = temp;
    j++;
    pop(&s);
    isEmpty = emptyStack(s);
  }
  hauto[j] = '\0';
}