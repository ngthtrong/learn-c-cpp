#include <stdio.h>

struct Node
{
    int Key;
    struct Node *Left, *Right;
};
typedef struct Node *Tree;

void makenullTree(Tree *pT) {};
int emptyTree(Tree T) {};
Tree leftChild(Tree n) {};
Tree rightChild(Tree n) {};
int isLeaf(Tree n) {};
int getLeaves(Tree T) {}; /* hàm trả về số nút lá trên cây */
void preOrder(Tree T) {};
void inOrder(Tree T) {};
void postOrder(Tree T) {};

Tree initTree()
{
    Tree rs = (Tree)malloc(sizeof(struct Node));
    rs->Left = NULL;
    rs->Right = NULL;
    return rs;
}

void preOrder(Tree tr)
{
    if (tr == NULL)
        return;
    preOrder(tr->Left);
    printf("%d ", tr->Key);
    preOrder(tr->Right);
}

int getLeaves(Tree t)
{
    if (t == NULL)
        return 0;
    if (t->Left == NULL && t->Right == NULL)
        return 1;
    else
    {

        return getLeaves(t->Left) + getLeaves(t->Right);
    }
    return 0;
}

Tree getNext(int x, Tree tr)
{
    Tree rs = NULL;
    while (tr != NULL)
    {
        if (x < tr->Key)
        {
            rs = tr;
            tr = tr->Left;
        }
        else if (x > tr->Key)
        {
            tr = tr->Right;
        }
        else
        {
            if (tr->Right != NULL)
            {
                tr = tr->Right;
                while (tr->Left != NULL)
                    tr = tr->Left;
                return tr;
            }
            else
                return rs;
        }
    }
    return rs;
}

Tree getPrevious(int x, Tree tr)
{
    Tree rs = NULL;
    while (tr != NULL)
    {
        if (x < tr->Key)
        {
            tr = tr->Left;
        }
        else if (x > tr->Key)
        {
            rs = tr;
            tr = tr->Right;
        }
        else
        {
            if (tr->Left != NULL)
            {
                tr = tr->Left;
                while (tr->Right != NULL)
                    tr = tr->Right;
                return tr;
            }
            else
                return rs;
        }
    }
    return rs;
}
int getHeight(Tree tr)
{
    if (tr == NULL)
        return -1;
    int r = 1 + getHeight(tr->Right);
    int l = 1 + getHeight(tr->Left);
    return r > l ? r : l;
}
DataType findMax(Tree tr)
{
    if (tr != NULL)
    {
        DataType l = -1, r = -1;
        if (tr->Right != NULL)
            r = findMax(tr->Right);
        else if (tr->Left != NULL)
            l = findMax(tr->Left);
        else if (tr->Left == NULL && tr->Right == NULL)
            return tr->Data;
        return l > r ? l : r;
    }
    return -1;
}
Tree findElement(DataType x, Tree tr)
{
    if (tr != NULL)
    {
        if (tr->Data == x)
            return tr;
        else
        {
            Tree tempL = findElement(x,tr->Left);
            Tree tempR = findElement(x,tr->Right);
            if(tempL!=NULL)
                return tempL;
            if(tempR!=NULL)
                return tempR;
        }
    }
    return NULL;
}
