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

int myheight(Tree tr)
{
  if (tr != NULL)
  {
    int hl = myheight(tr->left);
    int hr = myheight(tr->right);
    hl = hl > hr ? hl : hr;
    return 1 + hl;
  }
  return 0;
};

Tree leftRotate(Tree tr)
{
  Tree x = tr->right, z = x->left;
  x->left = tr;
  tr->right = z;
  x->height = myheight(x);
  tr->height = myheight(tr);
  return x;
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

Tree insertNode(Tree root, int key)
{
  if (root == NULL)
  {
    root = (Tree)malloc(sizeof(struct Node));
    root->height = 0;
    root->key = key;
    root->left = NULL;
    root->right = NULL;
    return root;
  }
  if (key > root->key)
  {
    root->right = insertNode(root->right, key);
    root->right->height = myheight(root->right);
  }
  else if (key < root->key)
  {
    root->left = insertNode(root->left, key);
    root->left->height = myheight(root->left);
  }
  else if (key == root->key)
    return root;
  root->height = myheight(root);
  int gB = getBalance(root);
  if (gB == 2)
  {
    if (key < root->left->key)
      return rightRotate(root);
    else if (key > root->left->key)
    {
      root->left = leftRotate(root->left);
      return rightRotate(root);
    }
  }
  else if (gB == -2)
  {
    if (key > root->right->key)
      return leftRotate(root);
    else if (key < root->right->key)
    {
      root->right = rightRotate(root->right);
      return leftRotate(root);
    }
  }
  return root;
}

Tree insertNode_Solution(Tree node, int key)
{
  // Find the correct position to insertNode the node and insertNode it
  if (node == NULL)
    return (newNode(key));

  if (key < node->key)
    node->left = insertNode(node->left, key);
  else if (key > node->key)
    node->right = insertNode(node->right, key);
  else
    return node;

  // Update the balance factor of each node and
  // Balance the tree
  node->height = 1 + max(height(node->left), height(node->right));

  int balance = getBalance(node);
  if (balance > 1 && key < node->left->key)
    return rightRotate(node);

  if (balance < -1 && key > node->right->key)
    return leftRotate(node);

  if (balance > 1 && key > node->left->key)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  if (balance < -1 && key < node->right->key)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

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