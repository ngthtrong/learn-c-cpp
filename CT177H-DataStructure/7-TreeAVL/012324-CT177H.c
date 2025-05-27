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
  x->Height = mymyGetHeight(x);
  tr->Height = mymyGetHeight(tr);
  return x;
}

AVLTree leftRotate(AVLTree tr)
{
  AVLTree x = tr->Right;
  tr->Right = x->Left;
  x->Left = tr;
  x->Height = mymyGetHeight(x);
  tr->Height = mymyGetHeight(tr);
  return x;
}

AVLTree leftrightRotate(AVLTree tr)
{
  tr->Left = leftRotate(tr->Left);
  return rightRotate(tr);
}

AVLTree rightleftRotate(AVLTree tr)
{
  tr->Right = rightRotate(tr->Right);
  return leftRotate(tr);
}

AVLTree search(KeyType key, AVLTree root)
{
  if (root != NULL)
  {
    if (key < root->Key)
      return search(key, root->Left);
    else if (key > root->Key)
      return search(key, root->Right);
    else
      return root;
  }
  return NULL;
}

void printHeight(int h, AVLTree root)
{
  if (root != NULL)
  {
    if (h == root->Height)
    {
      printf("%d ", root->Key);
    }
    printHeight(h, root->Left);
    printHeight(h, root->Right);
  }
}

int isAVL(AVLTree tr)
{
  if (!getBalance(tr))
    return 1;
  return 0;
}

AVLTree insertNode(KeyType key, AVLTree root)
{
  if (root == NULL)
  {
    root = (AVLTree)malloc(sizeof(struct Node));
    root->Height = 0;
    root->Key = key;
    root->Left = NULL;
    root->Right = NULL;
    return root;
  }
  if (key > root->Key)
  {
    root->Right = insertNode(key, root->Right);
    root->Right->Height = myGetHeight(root->Right);
  }
  else if (key < root->Key)
  {
    root->Left = insertNode(key, root->Left);
    root->Left->Height = myGetHeight(root->Left);
  }
  else if (key == root->Key)
    return root;
  root->Height = myGetHeight(root);
  int gB = getBalance(root);
  if (gB == 2)
  {
    if (key < root->Left->Key)
      return rightRotate(root);
    else if (key > root->Left->Key)
      return leftrightRotate(root);
  }
  else if (gB == -2)
  {
    if (key > root->Right->Key)
      return leftRotate(root);
    else if (key < root->Right->Key)
      return rightleftRotate(root);
  }
  return root;
}
