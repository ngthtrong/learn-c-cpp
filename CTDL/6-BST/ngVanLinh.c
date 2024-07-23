#include <stdlib.h>
#include <stdio.h>
#include <string.h>
typedef char DataType;
struct Node
{
  DataType Data;
  struct Node *Left, *Right;
};
typedef struct Node *Tree;
void makenullTree(Tree *pT) {};
int emptyTree(Tree T) {};
Tree leftChild(Tree n) {};
Tree rightChild(Tree n) {};
int isLeaf(Tree n) {};
int getLeaves(Tree T) {};
void preOrder(Tree T) {};
void inOrder(Tree T) {};
void postOrder(Tree T)
{
  if (T != NULL)
  {
    postOrder(T->Left);
    postOrder(T->Right);
    printf("%c ", T->Data);
  }
};

DataType findMax(Tree tr)
{
  if (tr != NULL)
  {
    DataType maxLeft = findMax(tr->Left);
    DataType maxRight = findMax(tr->Right);
    DataType temp = maxLeft > maxRight ? maxLeft : maxRight;
    return temp > tr->Data ? temp : tr->Data;
  }
  return -100;
}

int findIndex(DataType x, char in[], int star, int end)
{
  int i = star;
  while (i <= end)
  {
    if (x == in[i])
      return i;
    else
      i++;
  }
  return i;
}

Tree createTree(DataType pre[], char in[], int star, int end)
{
  static int preIndex = 0;
  if (star <= end)
  {
    Tree n = (Tree)malloc(sizeof(struct Node));
    n->Data = pre[preIndex++];
    if (star == end)
    {
      n->Left = NULL;
      n->Right = NULL;
    }
    else
    {
      int index = findIndex(n->Data, in, star, end);
      n->Left = createTree(pre, in, star, index - 1);
      n->Right = createTree(pre, in, index + 1, end);
    }
    return n;
  }
  return NULL;
}

void printArray(int path[], int len)
{
  int i;
  for (i = 0; i < len; i++)
    printf("%d", path[i]);
  printf("\n");
}

Tree convertTree(Tree root)
{
  if (root != NULL)
  {
    Tree mir;
    mir = createNode(root->Data);
    mir->Left = convertTree(root->Right);
    mir->Right = convertTree(root->Left);
    return mir;
  }
  return NULL;
}

int isMirrors(Tree t1, Tree t2)
{
  if (t1 != NULL && t2 != NULL)
  {
    if (t1->Data == t2->Data)
      return isMirrors(t1->Right, t2->Left) && isMirrors(t1->Left, t2->Right);
    else
      return 0;
  }
  else if (t1 == NULL && t2 == NULL)
    return 1;
  return 0;
}

void printAllPaths(Tree tr, DataType path[], int len, int pathlen)
{
  if (tr != NULL)
  {
    path[len] = tr->Data;
    if (len == pathlen && tr->Left == NULL && tr->Right == NULL)
    {
      printArray(path, len + 1);
    }
    else if (len < pathlen)
    {
      len++;
      printAllPaths(tr->Left, path, len, pathlen);
      printAllPaths(tr->Right, path, len, pathlen);
    }
  }
}

int main()
{
  Tree T;
  char pre[10], in[10];
  fgets(pre, 10, stdin);
  if (pre[strlen(pre) - 1] == '\n')
  {
    pre[strlen(pre) - 1] = '\0';
  }
  fgets(in, 10, stdin);
  if (in[strlen(in) - 1] == '\n')
  {
    in[strlen(in) - 1] = '\0';
  }
  T = createTree(pre, in, 0, strlen(in) - 1);
  printf("Ket qua duyet hau tu: ");
  if (T != NULL)
    postOrder(T);
}