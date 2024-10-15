#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef char DataType;
struct Node
{
  DataType key;
  struct Node *left, *right;
};
typedef struct Node *Tree;

Tree initTree()
{
  Tree temp;
  // temp = (Tree)malloc(sizeof(struct Node));
  // temp->left = NULL;
  // temp->right = NULL;
  temp = NULL;
  return temp;
};

int isEmpty(Tree tr)
{
  return tr == NULL;
}

void preOrder(Tree tr)
{
  if (tr != NULL)
  {
    printf("%c ", tr->key);
    preOrder(tr->left);
    preOrder(tr->right);
  }
}

void in_order(Tree tr)
{
  if (tr != NULL)
  {
    in_order(tr->left);
    printf("%c ", tr->key);
    in_order(tr->right);
  }
  
}

void post_order(Tree tr)
{
  if (tr != NULL)
  {
    post_order(tr->left);
    post_order(tr->right);
    printf("%d ", tr->key);
  }
}

Tree search(DataType x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->key)
      return search(x, tr->right);
    else if (x < tr->key)
      return search(x, tr->left);
    else if (x == tr->key)
    {
      return tr;
    }
  }
  return NULL;
}

Tree getNext(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->key)
      return getNext(x, tr->right);
    else if (x < tr->key)
      return getNext(x, tr->left);
    else if (x == tr->key)
    {
      if (tr->right != NULL)
        return tr->right;
      return NULL;
    }
  }
  return tr;
}

Tree getPrevious(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->key)
      return getPrevious(x, tr->right);
    else if (x < tr->key)
      return getPrevious(x, tr->left);
    else if (x == tr->key)
    {
      if (tr->left != NULL)
        return tr->left;
      return NULL;
    }
  }
  return tr;
}

Tree rightSibling(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->key)
    {
      return rightSibling(x, tr->right);
    }
    else if (x < tr->key)
    {
      if (x == tr->left->key)
        return tr->right;
      return rightSibling(x, tr->left);
    }
    return NULL;
  }
  return tr;
}

Tree getParent(int x, Tree tr)
{
  if (x < tr->key)
  {
    if (x == tr->left->key)
      return tr;
    return getParent(x, tr->left);
  }
  else if (x > tr->key)
  {
    if (x == tr->right->key)
      return tr;
    return getParent(x, tr->right);
  }
  return NULL;
}

void print_path(int x, Tree tr)
{
  {
    if (tr != NULL)
    {
      printf("%d ", tr->key);
      if (x > tr->key)
      {
        print_path(x, tr->right);
      }
      else if (x < tr->key)
      {
        print_path(x, tr->left);
      }
      else if (x == tr->key)
      {
        printf(" --> Tim thay");
      }
    }
    else
      printf(" --> Tim khong thay");
  }
}
Tree createNode(DataType key)
{
  Tree newNode = (Tree)malloc(sizeof(struct Node));
  newNode->key = key;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}

void insertNode(DataType x, Tree *tr)
{
  if ((*tr) != NULL)
  {
    if (x < (*tr)->key)
      insertNode(x, &((*tr)->left));
    else if (x > (*tr)->key)
      insertNode(x, &((*tr)->right));
  }
  else
  {
    struct Node *tempN = (struct Node *)malloc(sizeof(struct Node));
    (*tr) = tempN;
    (*tr)->key = x;
    (*tr)->left = NULL;
    (*tr)->right = NULL;
  }
}

Tree insert_node(int x, Tree root)
{
  if (root == NULL)
  {
    Tree temp = (Tree)malloc(sizeof(struct Node));
    root = temp;
    root->key = x;
    root->right = NULL;
    root->left = NULL;
  }
  else if (x < root->key)
  {
    root->left = insert_node(x, root->left);
  }
  else if (x > root->key)
  {
    root->right = insert_node(x, root->right);
  }
  return root;
}

void posOrder(Tree tr)
{
  if (tr != NULL)
  {
    posOrder(tr->left);
    posOrder(tr->right);
    printf("%d ", &tr->key);
  }
}

int get_height(Tree tr)
{
  if (tr != NULL)
  {
    if (tr->left != NULL && tr->right != NULL)
    {
      int tempR = get_height(tr->right);
      int tempL = get_height(tr->left);
      return 1 + (tempR > tempL ? tempR : tempL);
    }
    else if (tr->left != NULL)
      return 1 + get_height(tr->left);
    else
      return 1 + get_height(tr->right);
  }
  return -1;
}

int hNode(int x, Tree tr)
{
  if (tr != NULL)
  {
    if (x > tr->key)
      return hNode(x, tr->right);
    else if (x < tr->key)
      return hNode(x, tr->left);
    else if (x == tr->key)
    {
      if (tr->left != NULL && tr->right != NULL)
      {
        int tempR = hNode(tr->right->key, tr->right);
        int tempL = hNode(tr->left->key, tr->left);
        return 1 + (tempR >= tempL ? tempR : tempL);
      }
      else if (tr->left != NULL)
        return 1 + hNode(tr->left->key, tr->left);
      else if (tr->right != NULL)
        return 1 + hNode(tr->right->key, tr->right);
      else
        return 0;
    }
    return -1;
  }
  return -1;
}

void deleteNode(int x, Tree *tr)
{
  if ((*tr) != NULL)
  {
    if (x < (*tr)->key)
      deleteNode(x, &((*tr)->left));
    else if (x > (*tr)->key)
      deleteNode(x, &((*tr)->right));
    else
    {
      if ((*tr)->left == NULL && (*tr)->right == NULL)
      {
        free((*tr));
        (*tr) = NULL;
      }
      else if ((*tr)->left == NULL)
      {
        Tree delNode = (*tr);
        (*tr) = (*tr)->right;
        free(delNode);
        delNode = NULL;
      }
      else if ((*tr)->right == NULL)
      {
        Tree delNode = (*tr);
        (*tr) = (*tr)->left;
        free(delNode);
        delNode = NULL;
      }
      else
      {
        Tree minNode = (*tr)->right;
        while (minNode->left != NULL)
          minNode = minNode->left;
        (*tr)->key = minNode->key;
        deleteNode(minNode->key, &((*tr)->right));
      }
    }
  }
}

Tree delete_node(int x, Tree root)
{
  if (root != NULL)
  {
    if (x < root->key)
      root->left = delete_node(x, root->left);
    else if (x > root->key)
      root->right = delete_node(x, root->right);
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
        root->right = delete_node(minNode->key, root->right);
      }
    }
  }
  return root;
}

Tree convertTree(Tree root)
{
  if (root != NULL)
  {
    Tree mir;
    mir = initTree(root->key);
    mir->left = convertTree(root->right);
    mir->right = convertTree(root->left);
    return mir;
  }
  return NULL;
}

char findMax(Tree tr)
{
  if (tr != NULL)
  {
    DataType l = -1, r = -1;
    if (tr->right != NULL)
      r = findMax(tr->right);
    else if (tr->left != NULL)
      l = findMax(tr->left);
    return l > r ? l : r;
  }
  return -1;
}

// Tree initTree() {};
// int isEmpty(Tree tr) {};
// void preOrder(Tree tr) {};
// void in_order(Tree tr) {};
// void post_order(Tree tr) {};
// Tree getParent(int x, Tree tr) {};
// Tree search(int x, Tree tr) {};
// Tree rightSibling(int x, Tree tr) {};
// Tree getPrevious(int x, Tree tr) {};
// Tree getNext(int x, Tree tr) {};
// void print_path(int x, Tree tr) {};
// void insertNode(int x, Tree *tr) {};
// Tree insert_node(int x, Tree root) {};
// void posOrder(Tree tr) {};
// int get_height(Tree tr) {};
// int hNode(int x, Tree tr) {};
// void deleteNode(int x, Tree *tr) {};
// Tree delete_node(int x, Tree root) {};
// Tree convertTree(Tree root) {};
// char findMax(Tree tr) {};

