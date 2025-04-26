#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define VISITTED 1
#define UNVISITTED 0
int flag = 1;
int mark[MAX_SIZE + 1];

typedef struct
{
    int m, n;
    int e[MAX_SIZE][MAX_SIZE];
} Graph;

void DFS(Graph *pg, int s)
{

    mark[s] = VISITTED;
    for (int i = 1; i <= pg->n; i++)
    {
        if (pg->e[s][i] == 1 && mark[i] == UNVISITTED)
        {
            DFS(pg, i);
        }
    }
}

int main(int argc, char const *argv[])
{
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    G.m = m;
    G.n = n;

    for (int i = 1; i <= G.n; i++)
    {
        for (int j = 0; j < G.n; j++)
            G.e[i][j] = 0;
    }

    for (e = 0; e < m; e++)
    {
        mark[e + 1] = UNVISITTED;
        scanf("%d%d", &u, &v);
        G.e[u][v] = 1;
        G.e[v][u] = 1;
    }
    DFS(&G, 1);
    for (int i = 1; i <= G.n; i++)
    {
        if (mark[i] == UNVISITTED)
        {
            flag = 0;
        }
    }
    if (flag == 1)
        printf("CONNECTED\n");
    else
        printf("DISCONNECTED\n");
}