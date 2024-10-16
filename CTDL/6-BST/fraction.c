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

int canStore(Tree tr)
{
  if (tr == NULL)
    return 1;
  else if ((tr->key >= 'a' && tr->key <= 'z'))
    return 0;
  else
    return canStore(tr->right) || canStore(tr->left);
}
void insertFromPostString(char *str, Tree *tr)
{
  
}

int main()
{
  char inStr[] = "(a*(b+c))+(d*((e+f)+n*(g+j)))";
  char postStr[50];
  infixToPostfix(inStr, postStr);
  printString(postStr);
  reverseByStack(postStr);
  printString(postStr);
  // Tree tr = initTree();
  // insertFromPostString( postStr, &tr);
}