#include <stdio.h>
#define MAX_SIZE 100
#define VISITED 1
#define UNVISITED 0
#define oo 999

int mark[MAX_SIZE + 1];
int parent[MAX_SIZE + 1];
int d[MAX_SIZE + 1];

typedef struct
{
    int m, n;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

int prim(Graph *g, int s)
{
    d[s] = 0;
    int u = s;
    int total = 0;
    for (int i = 1; i < g->n; i++)
    {
        mark[u] = VISITED;
        int indexMin = -1;
        int min = oo;
        for (int v = 1; v <= g->n; v++)
        {
            if (d[v] > g->A[u][v] && v != u && g->A[u][v] != 0 && mark[v] == UNVISITED)
            {
                d[v] = g->A[u][v];
                parent[v] = u;
            }
            if (min > d[v] && mark[v] == UNVISITED)
            {
                min = d[v];
                indexMin = v;
            }
        }
        total += g->A[u][indexMin];
        u = indexMin;
    }
    return total;
}

void printPath(Graph *g, int u)
{
    for (int i = 1; i <= g->n; i++)
        if (i != u && parent[i] == u)
        {
            printf("%d %d %d\n", u, i, g->A[u][i]);
            printPath(g, i);
        }
}

int main(int argc, char const *argv[])
{
    // freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, w;
    scanf("%d%d", &n, &m);
    G.m = m;
    G.n = n;

    for (int i = 0; i <= G.n; i++)
    {
        parent[i] = -1;
        mark[i] = UNVISITED;
        d[i] = oo;
        for (int j = 0; j <= G.n; j++)
            G.A[i][j] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        G.A[u][v] = w;
        G.A[v][u] = w;
    }
    printf("%d\n", prim(&G, 1));
    printPath(&G, 1);
}