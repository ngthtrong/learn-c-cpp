#include <stdio.h>
#include <stdlib.h>
#define MAX 15
#define VISITTED 1
#define UNVISITTED 0

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
        {
            SCC(pg, i);
            min_num[u] = min_num[i] > min_num[u] ? min_num[u] : min_num[i];
        }
        else if (on_stack[i] == 1)
        {
            min_num[u] = num[i] > min_num[u] ? min_num[u] : num[i];
        }
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
    int n, m, u, v, e, p;
    scanf("%d%d", &n, &m);
    G.m = m;
    G.n = n;

    for (int i = 0; i <= G.n; i++)
    {
        for (int j = 0; j <= G.n; j++)
            G.A[i][j] = 0;
        num[i] = 0;
        min_num[i] = 0;
        on_stack[i] = 0;
    }

    for (e = 0; e < m; e++)
    {
        scanf("%d%d%d", &u, &v, &p);
        G.A[u][v] = 1;
        if (p == 2)
            G.A[v][u] = 1;
    }
    for (int i = 1; i < G.n + 1; i++)
    {
        if (num[i] == 0)
            SCC(&G, i);
    }

    // for (int i = 1; i <= G.n; i++)
    // {
    //     printf("%d %d\n", num[i], min_num[i]);
    // }
    //======
    if (count == 1)
        printf("OKIE");
    else
        printf("NO");
    //======

    // printf("%d", max);
}
// int isEmptyStack(Stack s) {};
// void makeNull(Stack *s) {};
// ElementType pop(Stack *s) {};
// void push(ElementType x, Stack *s) {};
