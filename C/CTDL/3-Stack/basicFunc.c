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
void print(Stack *s){
  while(!is_empty(*s)){
    printf("%d ", pop(s));
  }
  printf("\n");
}
void to_binary(int n, Stack *s){
  makenull(s);
  while(n){
    push(n%2, s);
    n /= 2;
  } 
}