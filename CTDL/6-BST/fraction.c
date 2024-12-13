#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basicFunc.h"
#include "../3-Stack/tmt/pstacklib.h"

void printString(char *str)
{
  printf("%s", str);
  printf("\n");
}
void insertFraction(int *index, char *str, Tree *tr)
{
  if (str[*index] >= 'a' && str[*index] <= 'z')
  {
    (*tr) = createNode(str[*index]);
    (*index)++;
  }
  else
  {
    int temp = *index;
    (*index)++;
    if ((*tr)->right == NULL)
      (*tr)->right = initTree();
    insertFraction(index, str, &((*tr)->right));
    (*tr)->key = str[temp];
    if ((*tr)->left == NULL)
      (*tr)->left = initTree();
    insertFraction(index, str, &((*tr)->left));
  }
}
void insertFromPostString(char *str, Tree *tr)
{
  int index = 0;
  insertFraction(&index, str, tr);
}

int main()
{
  // char inStr[] = "(a*(b+c))+(d*((e+f)+n*(g+j)))";
  char inStr[] = "(a*(b+c)*(m+k))+(d*((e+f)+n*(g+j)))";
  char postStr[50];
  infixToPostfix(inStr, postStr);
  printString(postStr);
  reverseByStack(postStr);
  printString(postStr);

  //------------------------//
  Tree tr = initTree();
  insertFromPostString(postStr, &tr);
  in_order(tr);
  printf("\n");

}