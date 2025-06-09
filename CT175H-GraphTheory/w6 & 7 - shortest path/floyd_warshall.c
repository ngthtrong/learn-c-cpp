#include <stdio.h>
#define MAX 101
#define oo 99999
int d[MAX][MAX];
int p[MAX][MAX];

typedef struct
{
    int n, m;
    int A[MAX][MAX];
} Graph;

void floyd_warshall(Graph const *G)
{
    for (int k = 1; k <= G->n; k++)
    {
        for (int i = 1; i <= G->n; i++)
            for (int j = 1; j <= G->n; j++)
            {
                if (d[i][k] != oo && d[k][j] != oo)
                {
                    if (d[i][j] > d[i][k] + d[k][j])
                    {
                        d[i][j] = d[i][k] + d[k][j];
                        p[i][j] = p[k][j];
                    }
                }
            }
    }
}

void printPath(int s, int t)
{
    if (t == s)
        return;
    printPath(s, p[s][t]);
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
        for (int j = 1; j <= n; j++)
        {
            G.A[i][j] = 0;
            d[i][j] = oo;
            p[i][j] = -1;
            if (i == j)
                d[i][j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int u;
        int v;
        int w;
        scanf("%d%d%d", &u, &v, &w);
        G.A[u][v] = w;
        d[u][v] = w;
        p[u][v] = u;
    }
    floyd_warshall(&G);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            // printf("path(%d, %d): ", i, j);
            printf("%d -> %d: ", i, j);
            if (d[i][j] >= 9999)
                printf("NO PATH\n");
            else
            {
                printf("%d\n", d[i][j]);
                // printf("%d", i);
                // printPath(i, j);
                // printf("\n");
            }
        }
    }
    //=====
}