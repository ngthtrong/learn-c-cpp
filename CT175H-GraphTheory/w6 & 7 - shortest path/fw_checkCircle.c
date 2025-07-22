#include <stdio.h>
#define MAX 101
#define oo 99999
int d[MAX][MAX];

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
                    }
                }
            }
    }
}
int check(Graph const *G)
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
                        return 1;
                    }
                }
            }
    }
    return 0;
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
    }
    floyd_warshall(&G);
    if (check(&G))
        printf("YES");
    else
        printf("NO");
}