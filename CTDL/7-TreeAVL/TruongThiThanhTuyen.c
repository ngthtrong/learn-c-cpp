#include <stdio.h>
#include <string.h>
typedef int KeyType;

struct Node
{
  KeyType Key;
  int Height;
  struct Node *Left, *Right;
};
typedef struct Node *AVLTree;

AVLTree search(KeyType key, AVLTree tr)
{
  if (tr != NULL)
  {
    if (key == tr->Key)
      return tr;
    else if (key > tr->Key)
      return search(key, tr->Right);
    else if (key < tr->Key)
      return search(key, tr->Left);
  }
  return NULL;
}
void printHeight(int h, AVLTree root)
{
  if (root != NULL)
  {
    if (h == root->Height)
      printf("%d ", root->Key);
    printHeight(h, root->Left);
    printHeight(h, root->Right);
  }
}
int getHeight(AVLTree tr)
{
  if (tr != NULL)
  {
    int hl = getHeight(tr->Left);
    int hr = getHeight(tr->Right);
    hr = hl > hr ? hl : hr;
    return 1 + hr;
  }
  return -1;
}
int isAVL(AVLTree root)
{
  if (root != NULL)
  {
    if (!getBalance(root))
      return 1;
  }
  return 0;
}