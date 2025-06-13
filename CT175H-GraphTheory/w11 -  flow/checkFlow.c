#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct
{
    int n, m;
    int capacity[MAX][MAX];
    int flow[MAX][MAX];
} Graph;

int check_flow(Graph *g, int s, int t)
{
    int in[MAX] = {0};
    int out[MAX] = {0};
    for (int u = 1; u <= g->n; u++)
    {
        for (int v = 1; v <= g->n; v++)
        {
            if (u == v)
                continue;
            if (g->flow[u][v] < 0 || g->capacity[u][v] < g->flow[u][v])
                return 0;
            in[u] += g->flow[u][v];
            out[u] += g->flow[v][u];
        }
        if (in[u] != out[u] && u != s && u != t)
            return 0;
    }
    if (out[s] != in[t])
        return 0;

    return 1;
}

int main()
{
    Graph G;
    scanf("%d%d", &G.n, &G.m);

    for (int i = 0; i < G.n + 1; i++)
    {

        for (int j = 0; j < G.n + 1; j++)
        {
            G.capacity[i][j] = 0;
            G.flow[i][j] = 0;
        }
    }
    for (int i = 1; i <= G.m; i++)
    {
        int u, v, c, f;
        scanf("%d%d%d%d", &u, &v, &c, &f);
        G.capacity[u][v] = c;
        G.flow[u][v] = f;
    }
    if (check_flow(&G, 1, G.n))
        printf("YES");
    else
        printf("NO");
}
