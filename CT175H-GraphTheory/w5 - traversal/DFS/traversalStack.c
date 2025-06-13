#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
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

int mark[MAX_SIZE + 1];
int status[MAX_SIZE + 1];
int parent[MAX_SIZE + 1];

typedef struct
{
    int m, n;
    int e[MAX_SIZE][MAX_SIZE];
} Graph;

void DFS(Graph *pg, int s)
{
    Stack S;
    makeNull(&S);
    push(s, &S);
    while (!isEmptyStack(S))
    {
        int temp = pop(&S);
        if (mark[temp] == VISITTED)
            continue;
        // printf("%d\n", temp);
        mark[temp] = VISITTED;
        for (int i = 1; i <= pg->n; i++)
        {
            if (pg->e[temp][i] == 1 && mark[i] == UNVISITTED)
            {
                parent[i] = temp;
                push(i, &S);
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    // freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    G.m = m;
    G.n = n;

    for (int i = 0; i <= G.n; i++)
    {
        parent[i] = 0;
        for (int j = 0; j <= G.n; j++)
            G.e[i][j] = 0;
    }

    for (e = 0; e < m; e++)
    {
        mark[e + 1] = UNVISITTED;
        scanf("%d%d", &u, &v);
        G.e[u][v] = 1;
        G.e[v][u] = 1;
    }
    for (int i = 1; i <= G.n; i++)
    {
        if (mark[i] == UNVISITTED)
        {
            DFS(&G, i);
        }
    }
    for (int i = 1; i <= G.n; i++)
    {
        printf("%d %d\n", i, parent[i]);
    }
}