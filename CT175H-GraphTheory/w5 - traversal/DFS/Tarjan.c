#include <stdio.h>
#include <stdlib.h>
#define MAX 100
<<<<<<< HEAD
=======
#define VISITTED 1
#define UNVISITTED 0
>>>>>>> 9d0f63368273b9117f9da1ec1084db33fbde0d66

typedef int ElementType;
typedef struct NodeStack
{
    ElementType data;
    struct NodeStack *next;
} NodeStack;
typedef NodeStack *Stack;
int isEmptyStack(Stack s)
{
    return s->next == NULL;
};
void makeNull(Stack *s)
{
    NodeStack *header = (Stack)malloc(sizeof(NodeStack));
    header->next = NULL;
    (*s) = header;
};
ElementType pop(Stack *s)
{
    NodeStack *a = *s;
    if (!isEmptyStack(a))
    {
        NodeStack *temp = a->next;
        int rs = temp->data;
        a->next = a->next->next;
        free(temp);
        return rs;
    }
    printf("pop: stack empty\n");
    exit(EXIT_FAILURE);
};
void push(ElementType x, Stack *s)
{
    NodeStack *temp = (Stack)malloc(sizeof(NodeStack));
    temp->data = x;
    temp->next = (*s)->next;
    (*s)->next = temp;
};

typedef struct
{
    int m, n;
    int A[MAX][MAX];
} Graph;

int on_stack[MAX + 1];
int num[MAX + 1];
int min_num[MAX + 1];
int k = 0;
int count = 0;
Stack S;

void SCC(Graph *pg, int u)
{
    num[u] = min_num[u] = ++k;
    push(u, &S);
    on_stack[u] = 1;
    for (int i = 1; i <= pg->n; i++)
    {
        if (pg->A[u][i] == 0 || u == i)
            continue;
        if (num[i] == 0)
            SCC(pg, i);

        min_num[u] = min_num[i] > min_num[u] ? min_num[u] : min_num[i];
    }
    if (num[u] == min_num[u])
    {
        count++;
    }
}

int main(int argc, char const *argv[])
{
    // freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    makeNull(&S);
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    G.m = m;
    G.n = n;

    for (int i = 0; i <= G.n; i++)
    {
        for (int j = 0; j <= G.n; j++)
        {
            G.A[i][j] = 0;
            if (i == j)
                G.A[i][j] = 1;
        }
        num[i] = 0;
        min_num[i] = 0;
        on_stack[i] = 0;
    }

    for (e = 0; e < m; e++)
    {
        scanf("%d%d", &u, &v);
        G.A[u][v] = 1;
    }
    for (int i = 1; i < G.n + 1; i++)
    {
        if (num[i] == 0)
            SCC(&G, i);
    }

    // SCC(&G, 1);
    // for (int i = 1; i <= G.n; i++)
    // {
    //     printf("%d %d\n", num[i], min_num[i]);
    // }
    //======
    // if (count == 1)
    //     printf("STRONG CONNECTED");
    // else
    //     printf("DISCONNECTED");
    //======

    printf("%d", count);
}
// int isEmptyStack(Stack s) {};
// void makeNull(Stack *s) {};
// ElementType pop(Stack *s) {};
// void push(ElementType x, Stack *s) {};
