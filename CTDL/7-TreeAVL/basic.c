#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
  int key;
  struct Node *left;
  struct Node *right;
  int height;
};
typedef struct Node *Tree;

int height(Tree tr)
{
  if (tr != NULL)
  {
    int hl = height(tr->left);
    int hr = height(tr->right);
    hl = hl > hr ? hl : hr;
    return 1 + hl;
  }
  return 0;
};

Tree rightRotate(Tree tr)
{
  Tree x = tr->left, z = x->right;
  x->right = tr;
  tr->left = z;
  x->height = height(x);
  tr->height = height(tr);
  return x;
};
Tree leftRotate(Tree tr)
{
  Tree y = tr->right, z = y->left;
  y->left = tr;
  tr->right = z;
  y->height = height(y);
  tr->height = height(tr);
  return y;
};

int getBalance(Tree tr)
{
  if (tr != NULL)
  {
    int hr = tr->right != NULL ? tr->right->height : 0;
    int hl = tr->left != NULL ? tr->left->height : 0;
    return hl - hr;
  }
  return 0;
};
Tree insertNode(Tree tr, int key)
{
  if (tr == NULL)
  {
    Tree temp = (Tree)malloc(sizeof(struct Node));
    temp->left = NULL;
    temp->right = NULL;
    temp->key = key;
    temp->height = 0;
    return temp;
  }
  else if (key < tr->key)
    tr->left = insertNode(tr->left, key);
  else if (key > tr->key)
    tr->right = insertNode(tr->right, key);

  int balanceIndex = getBalance(tr);
  printf("%d\n", balanceIndex);
  if (balanceIndex == 1 && key < tr->left->key)
    tr = rightRotate(tr);
  else if (balanceIndex == 2 && key > tr->right->key)
    tr = leftRotate(tr);
  else if (balanceIndex == 1 && key > tr->left->key)
  {
    tr->left = leftRotate(tr->left);
    tr = rightRotate(tr);
  }
  else if (balanceIndex == 2 && key < tr->right->key)
  {
    tr->right = rightRotate(tr->right);
    tr = leftRotate(tr);
  }
  return tr;
};

Tree deleteNode(Tree root, int key)
{
  if (root != NULL)
  {
    if (key < root->key)
      root->left = deleteNode(root->left, key);
    else if (key > root->key)
      root->right = deleteNode(root->right, key);
    else
    {
      if (root->left == NULL && root->right == NULL)
      {
        free(root);
        root = NULL;
        return NULL;
      }
      else if (root->left == NULL)
      {
        Tree delNode = root;
        root = root->right;
        free(delNode);
        return delNode;
      }
      else if (root->right == NULL)
      {
        Tree delNode = root;
        root = root->left;
        free(delNode);
        delNode = NULL;
        return delNode;
      }
      else
      {
        Tree minNode = root->right;
        while (minNode->left != NULL)
          minNode = minNode->left;
        root->key = minNode->key;
        root->right = deleteNode(root->right, minNode->key);
      }
    }
  }
  int balanceIndex = getBalance(root);
  if (balanceIndex == 2)
    root = rightRotate(root);
  else if (balanceIndex == 1)
    root = leftRotate(root);
  return root;
}

void printPosOrder(Tree tr)
{
  if (tr != NULL)
  {
    printPosOrder(tr->left);
    printPosOrder(tr->right);
    printf("%d ", tr->key);
  }
}
void printInOrder(Tree tr)
{
  if (tr != NULL)
  {
    printInOrder(tr->left);
    printf("%d ", tr->key);
    printInOrder(tr->right);
  }
}
void printPreOrder(Tree tr)
{
  if (tr != NULL)
  {
    printf("%d ", tr->key);
    printPreOrder(tr->left);
    printPreOrder(tr->right);
  }
}

int main()
{
  printf("Hello World\n");
}