#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int DataType;
struct Node
{
    DataType key;
    struct Node *left, *right;
};
typedef struct Node *Tree;

void makeNull(Tree *tr)
{
    (*tr) = (Tree)malloc(sizeof(struct Node));
    (*tr)->left = NULL;
    (*tr)->right = NULL;
};

Tree leftChild(Tree tr)
{
    if (tr != NULL)
        return tr->left;
    return NULL;
}
Tree rightChild(Tree tr)
{
    if (tr != NULL)
        return tr->right;
    return NULL;
}

int isLeaf(Tree tr)
{
    if (tr != NULL)
        return (leftChild(tr) == NULL && rightChild(tr) == NULL);
    return 0;
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

void inOrder(Tree tr)
{
    if (tr != NULL)
    {
        inOrder(tr->left);
        printf("%d ", tr->key);
        inOrder(tr->right);
    }
}

void postOrder(Tree tr)
{
    if (tr != NULL)
    {
        postOrder(tr->left);
        postOrder(tr->right);
        printf("%c ", tr->key);
    }
}

int countNode(Tree tr) // O(n)
{
    if (tr != NULL)
        return countNode(tr->right) + countNode(tr->left) + 1;
    return 0;
}
int countLeaf(Tree tr) // O(n)
{
    if (tr != NULL)
    {
        if (isLeaf(tr))
            return 1;
        return countLeaf(tr->right) + countLeaf(tr->left);
    }
    return 0;
}

Tree search(DataType x, Tree tr)
{
    if (tr == NULL)
        return NULL;

    if (x == tr->key)
        return tr;
    else if (x < tr->key)
        return search(x, tr->left);
    else
        return search(x, tr->right);
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
        makeNull(tr);
        (*tr)->key = x;
    }
}
DataType deleteMin(Tree* T) {
    DataType key;
    Tree temp;
    if (((*T)->left) == NULL) {
        temp = (*T);
        key = (*T)->key;
        (*T) = (*T)->right;
        free(temp);
        return key;
    } else {
        return deleteMin(&((*T)->left));
    }
}

// deleteMax
void deleteNode(DataType x, Tree* T) {
    Tree temp;
    if ((*T)!=NULL) {
        // Tim x
        if (x < (*T)->key) {
            deleteNode(x, &((*T)->left));
        } else if (x > (*T)->key) {
            deleteNode(x, &((*T))->right);
        } else {  // found x
            if (isLeaf(*T)) {
                temp = (*T);
                (*T) = NULL;
                free(temp);
            } else if ((*T)->left == NULL && (*T)->right != NULL) {
                temp = (*T);
                (*T) = (*T)->right;
                free(temp);
            } else if ((*T)->right == NULL && (*T)->left != NULL) {
                temp = (*T);
                (*T) = (*T)->left;
                free(temp);
            } else {
                (*T)->key = deleteMin(&((*T)->right));
            }
        }
    }
}





void myDeleteNode(int x, Tree *tr)
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
        Tree temp = (*tr);
        (*tr) = (*tr)->right;
        free(temp);
        temp = NULL;
      } 
      else if ((*tr)->right == NULL)
      {
        Tree temp = (*tr);
        (*tr) = (*tr)->left;
        free(temp);
        temp = NULL;
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







Tree readTree()
{
    Tree T = NULL;
    int a[] = {13, 3, 4, 14, 1, 2, 18, 12, 10, 5, 11, 8, 7, 6, 9};
    for (int i = 0; i < sizeof(a) / sizeof(int); i++)
    {
        insertNode(a[i], &T);
    }
    return T;
}

int main()
{
    Tree tr = readTree();

    inOrder(tr);
    printf("\n");
    deleteNode(5, &tr);
    deleteNode(2, &tr);
    deleteNode(3, &tr);
    deleteNode(4, &tr); 

    inOrder(tr);
    printf("\n");


    // printf("%d\n", countLeaf(tr));
    // printf("%d\n", countNode(tr));

    return 0;
}
