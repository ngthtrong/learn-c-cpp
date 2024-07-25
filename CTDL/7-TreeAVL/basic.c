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

int height(Tree T) {};

Tree rightRotate(Tree tr)
{
  Tree x = tr->left, z = x->right;
  x->right = tr;
  tr->left = z;
  x->height = height(x);
  tr->height = height(tr);
  return x;
};

int main()
{
  printf("Hello World\n");
}