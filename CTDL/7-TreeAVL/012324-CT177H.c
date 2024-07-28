#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int KeyType;
struct Node
{
  int Height;
  KeyType Key;
  struct Node *Left, *Right;
};
typedef struct Node *AVLTree;

void printLeaves(AVLTree root)
{
  if (root != NULL)
  {
    if (root->Left == NULL && root->Right == NULL)
      printf("%d ", root->Key);
    else
    {
      printLeaves(root->Left);
      printLeaves(root->Right);
    }
  }
}

void printNLR(AVLTree tr)
{
  if (tr != NULL)
  {
    printf("(%d - %d); ", tr->Key, tr->Height);
    printNLR(tr->Left);
    printNLR(tr->Right);
  }
}

void printLRN(AVLTree tr)
{
  if (tr != NULL)
  {
    printLRN(tr->Left);
    printLRN(tr->Right);
    printf("(%d - %d); ", tr->Key, tr->Height);
  }
}

void printLNR(AVLTree tr)
{
  if (tr != NULL)
  {
    printLNR(tr->Left);
    printf("(%d - %d); ", tr->Key, tr->Height);
    printLNR(tr->Right);
  }
}

int getBalance(AVLTree tr)
{
  if (tr != NULL)
  {
    int hl = tr->Left != NULL ? tr->Left->Height : -1;
    int hr = tr->Right != NULL ? tr->Right->Height : -1;
    return hl - hr;
  }
  return 0;
}

int myGetHeight(AVLTree tr)
{
  if (tr != NULL)
  {
    int hl = myGetHeight(tr->Left);
    int hr = myGetHeight(tr->Right);
    hr = hl > hr ? hl : hr;
    return 1 + hr;
  }
  return -1;
}

AVLTree rightRotate(AVLTree tr)
{
  AVLTree x = tr->Left;
  tr->Left = x->Right;
  x->Right = tr;
  x->Height = myGetHeight(x);
  tr->Height = myGetHeight(tr);
  return x;
}

AVLTree leftRotate(AVLTree tr)
{
  AVLTree x = tr->Right;
  tr->Right = x->Left;
  x->Left = tr;
  x->Height = myGetHeight(x);
  tr->Height = myGetHeight(tr);
  return x;
}

AVLTree leftrightRotate(AVLTree tr)
{
  

}


