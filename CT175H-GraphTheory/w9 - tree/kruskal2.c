#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
int p[MAX_SIZE + 1];

typedef struct
{
    int u, v, w, m;
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
int cmp2(const void *a, const void *b)
{
    return ((Edge *)a)->u - ((Edge *)b)->u;
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
            g->e[i].m = 1;
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
        scanf("%d%d%d", &u, &v, &w);
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
        G.e[i].m = 0;
    }

    qsort(G.e, G.m, sizeof(Edge), cmp);
    printf("%d\n", kruskal(&G));
    qsort(G.e, G.m, sizeof(Edge), cmp2);
    for (int i = 0; i < m; i++)
        if (G.e[i].m == 1)
            printf("%d %d %d\n", G.e[i].u, G.e[i].v, G.e[i].w);
}