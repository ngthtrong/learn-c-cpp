// stack by dynamic array
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int ElementType;
typedef struct
{
  ElementType *elements;
  int size, capacity, top;
} Stack;

int makenull(Stack *s)
{
  s->top = -1;
  s->capacity = 2;
  s->elements = (ElementType *)malloc(s->capacity * sizeof(ElementType));
}
int is_empty(Stack s)
{
  return s.top == -1;
}

void push(int x, Stack *s)
{
  if (s->top == s->capacity - 1)
  {
    s->capacity *= 2;
    s->elements = (ElementType *)realloc(s->elements, s->capacity * sizeof(ElementType));
  }
  s->elements[++s->top] = x;
}
ElementType pop(Stack *s)
{
  if (s->top == -1)
    return -1;
  s->elements = (ElementType *)realloc(s->elements, s->capacity-- * sizeof(ElementType));
  return s->elements[s->top--];
}
void print(Stack *s)
{
  while (!is_empty(*s))
  {
    printf("%d", pop(s));
  }
  printf("\n");
}
void to_binary(int n)
{
  printf("%d -> ", n);
  Stack s;
  makenull(&s);
  if (n == 0)
    push(n % 2, &s);
  else
  {
    while (n)
    {
      push(n % 2, &s);
      n /= 2;
    }
  }
  print(&s);
}

int calFibo(int n)
{
  Stack s;
  makenull(&s);
  push(n, &s);
  int rs = 0;
  while (!is_empty(s))
  {
    int temp = pop(&s);
    if (temp > 2)
    {
      push(temp - 2, &s);
      push(temp - 1, &s);
    }
    else{
      rs+=1;
    }
  }
  return rs;
}
int calC(int k, int n){
  Stack ks;
  makenull(&ks);
  Stack ns;
  makenull(&ns);
  int rs = 0;
  push(k,&ks);
  push(n,&ns);
  while(!(is_empty(ks)&&is_empty(ns))){
      int tempK = pop(&ks);
      int tempN = pop(&ns);
      if(tempK == 0|| tempK==tempN)
        rs+=1;
      else if(tempK==1||tempK==tempN-1)
        rs += tempN;
      else {
        push(tempK-1,&ks);
        push(tempK,&ks);
        push(tempN-1,&ns);
        push(tempN-1,&ns);
      }
  }
  return rs;


}



int main()
{
//  int rs =  calFibo(7);
//  printf("%d\n",rs);
 int c =  calC(3,5);
 printf("%d\n",c);
  return 0;
}