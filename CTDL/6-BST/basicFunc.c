#include <stdlib.h>
#include <string.h>

struct Node
{
  int Key;
  struct Node *Left, *Right;
};
typedef struct Node *Tree;

void insertNode(int x, Tree *Root) {}

Tree initTree()
{
  Tree temp;
  temp = NULL;
  return temp;
}

void preOrder(Tree tr)
{
  if (tr != NULL)
  {
    printf("%d ", tr->Key);
    preOrder(tr->Left);
    preOrder(tr->Right);
  }
}

Tree getNext(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->Key)
      return getNext(x, tr->Right);
    else if (x < tr->Key)
      return getNext(x, tr->Left);
    else if (x == tr->Key)
    {
      if (tr->Right != NULL)
        return tr->Right;
      return NULL;
    }
  }
  return tr;
}

Tree getPrevious(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->Key)
      return getPrevious(x, tr->Right);
    else if (x < tr->Key)
      return getPrevious(x, tr->Left);
    else if (x == tr->Key)
    {
      if (tr->Left != NULL)
        return tr->Left;
      return NULL;
    }
  }
  return tr;
}

Tree rightSibling(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->Key)
    {
      return rightSibling(x, tr->Right);
    }
    else if (x < tr->Key)
    {
      if (x == tr->Left->Key)
        return tr->Right;
      return rightSibling(x, tr->Left);
    }
    return NULL;
  }
  return tr;
}

Tree getParent(int x, Tree tr)
{
  if (x < tr->Key)
  {
    if (x == tr->Left->Key)
      return tr;
    return getParent(x, tr->Left);
  }
  else if (x > tr->Key)
  {
    if (x == tr->Right->Key)
      return tr;
    return getParent(x, tr->Right);
  }
  return NULL;
}

void printPath(int x, Tree tr)
{
  {
    if (tr != NULL)
    {
      printf("%d ", tr->Key);
      if (x > tr->Key)
      {
        printPath(x, tr->Right);
      }
      else if (x < tr->Key)
      {
        printPath(x, tr->Left);
      }
      else if (x == tr->Key)
      {
        printf("-> Tim thay");
      }
    }
    else
      printf("-> Khong thay");
  }
}

void insertNode(int x, Tree *tr)
{
  if ((*tr) != NULL)
  {
    if (x < (*tr)->Key)
      insertNode(x, &((*tr)->Left));
    else if (x > (*tr)->Key)
      insertNode(x, &((*tr)->Right));
  }
  else
  {
    struct Node *tempN = (struct Node *)malloc(sizeof(struct Node));
    (*tr) = tempN;
    (*tr)->Key = x;
    (*tr)->Left = NULL;
    (*tr)->Right = NULL;
  }
}

void posOrder(Tree tr)
{
  if (tr != NULL)
  {
    posOrder(tr->Left);
    posOrder(tr->Right);
    printf("%d ", &tr->Key);
  }
}

int getHeight(Tree tr)
{
  if (tr != NULL)
  {
    if (tr->Left != NULL && tr->Right != NULL)
    {
      int tempR = getHeight(tr->Right);
      int tempL = getHeight(tr->Left);
      return 1 + (tempR > tempL ? tempR : tempL);
    }
    else if (tr->Left != NULL)
      return 1 + getHeight(tr->Left);
    else
      return 1 + getHeight(tr->Right);
  }
  return -1;
}

void deleteNode(int x, Tree *tr)
{
}

int main()
{
  prinf("Hello world");
}
