#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define YES 1
#define NO 0

int p[MAX_SIZE + 1];
int mark[MAX_SIZE + 1];

typedef struct
{
    int u, v, w;
} Edge;
typedef struct
{
    int m, n;
    Edge e[MAX_SIZE]; // 0 -> m-1
} Graph;

int cmp(const void *a, const void *b)
{
    return ((Edge *)a)->w - ((Edge *)b)->w;
}

int getParent(int i)
{
    if (i == p[i])
        return i;
    return getParent(p[i]);
}

int kruskal(Graph *g)
{
    int total = 0;
    for (int i = 0; i < g->m; i++)
    {
        int pU = getParent(g->e[i].u);
        int pV = getParent(g->e[i].v);
        if (pU != pV)
        {
            mark[i] = YES;
            p[pV] = p[pU];
            total += g->e[i].w;
        }
    }
    return total;
}

int main(int argc, char const *argv[])
{
    Graph G;
    int n, m, u, v, w;
    scanf("%d%d", &n, &m);
    G.m = m;
    G.n = n;

    for (int i = 0; i <= G.n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++)
    {
        mark[i] = NO;
        int temp;
        scanf("%d%d%d%d", &u, &v, &w, &temp);
        w *= temp;
        if (u < v)
        {
            G.e[i].u = u;
            G.e[i].v = v;
        }
        else
        {
            G.e[i].u = v;
            G.e[i].v = u;
        }
        G.e[i].w = w;
    }
    qsort(G.e, G.m, sizeof(Edge), cmp);
    printf("%d\n", kruskal(&G));
    // int total = 0;
    // for (int i = 0; i < m; i++)
    //     if (mark[i] == NO)
    //         total += G.e[i].w;
    // printf("%d\n", total);
}