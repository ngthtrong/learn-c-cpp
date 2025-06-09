#include <stdio.h>
#define MAX 101
#define oo 99999
int d[MAX];
int p[MAX];
int c[MAX];

typedef struct
{
    int n, m;
    int A[MAX][MAX];
} Graph;

void bellman_ford(Graph const *G, int s)
{
    d[s] = 0;
    for (int i = 1; i <= G->m; i++)
    {
        for (int u = 1; u <= G->n; u++)
            for (int v = 1; v <= G->n; v++)
            {
                if (G->A[u][v] != 0 && u != v)
                {
                    if (d[v] > d[u] + G->A[u][v])
                    {
                        d[v] = d[u] + G->A[u][v];
                        p[v] = u;
                        c[v] = c[u];
                    }
                    else if (d[v] == d[u] + G->A[u][v])
                        c[v] += c[u];
                }
            }
    }
}

void printPath(int s, int t)
{
    if (t == s)
        return;
    printPath(s, p[t]);
    printf(" -> %d", t);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    Graph G;
    G.n = n;
    G.m = m;
    for (int i = 1; i <= n; i++)
    {
        d[i] = oo;
        p[i] = -1;
        c[i] = 1;
        for (int j = 1; j <= n; j++)
            G.A[i][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u;
        int v;
        int w;
        scanf("%d%d%d", &u, &v, &w);
        G.A[u][v] = w;
        G.A[v][u] = w;
        if (u == 1)
            c[v] = 1;
        if (v == 1)
            c[u] = 1;
    }
    // int s,t;
    // scanf("%d%d",&s,&t);
    bellman_ford(&G, 1);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         printf("%d ", G.A[i][j]);
    //     }
    //     printf("\n");
    // }
    if (d[n] == oo)
        printf("-1 0");
    else
        printf("%d %d", d[n], c[n]);
    //===
    // printf("%d",s);
    // printPath(s,t);
    //===
    // for (int i = 1; i <= G.n; i++)
    // {
    //     printf("pi[%d] = %d, p[%d] = %d\n", i, d[i], i, p[i]);
    // }
}