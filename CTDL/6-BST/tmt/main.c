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

Tree create2(DataType x, Tree l, Tree r)
{
    Tree tr;
    tr = (Tree)malloc(sizeof(struct Node));
    tr->key = x;
    tr->left = l;
    tr->right = r;
    return tr;
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
        printf("%c ", tr->key);
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

int countNode(Tree tr)//O(n)
{
    if (tr != NULL)
        return countNode(tr->right) + countNode(tr->left) + 1;
    return 0;
}
int countLeaf(Tree tr)//O(n)
{
    if (tr != NULL)
    {
        if (isLeaf(tr))
            return 1;
        return  countLeaf(tr->right) + countLeaf(tr->left);
    }
    return 0;
}
int main()
{
    Tree tr;
    makeNull(&tr);
    tr = create2('*', tr->left, tr->right);
    tr->left = create2('+', create2('+', create2('+', create2('a', NULL, NULL), create2('b', NULL, NULL)), create2('*', create2('c', NULL, NULL), create2('+', create2('d', NULL, NULL), create2('e', NULL, NULL)))), create2('f', NULL, NULL));
    tr->right = create2('+', create2('g', NULL, NULL), create2('f', NULL, NULL));
    inOrder(tr);
    printf("\n");
    preOrder(tr);
    printf("\n");
    printf("node: %d", countNode(tr));
    printf("\n");
    printf("leaf: %d", countLeaf(tr));
    printf("\n");

    return 0;
}
