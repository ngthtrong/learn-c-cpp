#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "basicFunc.h"
#include "../3-Stack/tmt/pstacklib.h"

void printString(char *str)
{
  for (int i = 0; str[i] != '\0'; i++)
  {
    printf("%c", str[i]);
  }
  printf("\n");
}

struct Node createNode(DataType x)
{
  struct Node *tempN = (struct Node *)malloc(sizeof(struct Node));
  tempN->key = x;
  tempN->left = NULL;
  tempN->right = NULL;
  return tempN;
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
  (*tr) = createNode(str[0]);
  for (int i = 1; str[i] != '\0'; i++)
  {
    if (canStore(*tr))
    {
      if (canStore((*tr)->right))
      {
        (*tr)->right = createNode(str[i]);
        (*tr) = (*tr)->right;
      }
      else
      {
        (*tr)->left = createNode(str[i]);
        (*tr) = (*tr)->left;
      }
    }
    else
    {
      (*tr)=getParent()
    }
  }
}

int main()
{
  char inStr[] = "(a*(b+c))+(d*((e+f)+n*(g+j)))";
  char postStr[50];
  infixToPostfix(inStr, postStr);
  printString(postStr);
  reverseByStack(postStr);
  printString(postStr);
  Tree tr = initTree();
  insertFromPostString(index, postStr, &tr);
}