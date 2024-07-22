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
void postOrder(Tree T) {
  if (T != NULL)
  {
    postOrder(T->Left);
    postOrder(T->Right);
    printf("%c ", T->Data);
  }
};

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

// Tree createTree(DataType pre[], char in[], int star, int end)
// {
//   static int preIndex = 0;
//   if (star > end)
//     return NULL;
//   Tree temp = (Tree)malloc(sizeof(struct Node));
//   temp->Data = pre[preIndex++];
//   if (star == end)
//   {
//     temp->Left = NULL;
//     temp->Right = NULL;
//     return temp;
//   }
//   int inIndex = findIndex(temp->Data, in, star, end);
//   temp->Left = createTree(pre, in, star, inIndex - 1);
//   temp->Right = createTree(pre, in, inIndex + 1, end);
//   return temp;
// }


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