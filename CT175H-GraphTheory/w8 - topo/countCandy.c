#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int mark[MAX_SIZE + 1];
int rank[MAX_SIZE + 1];
typedef struct
{
    int m, n;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void toPoDFS(Graph *g, int u, int c)
{
    mark[u] = 1;
    int max = 1;
    for (int i = 1; i <= g->n; i++)
    {

        if (g->A[u][i] == 0 || u == i)
            continue;
        if (mark[i] == 0)
            toPoDFS(g, i, c);
        max = max > rank[i] + 1 ? max : rank[i] + 1;
    }
    rank[u] = max;
}

int main(int argc, char const *argv[])
{
    // freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m;
    scanf("%d%d", &n, &m);
    G.m = m;
    G.n = n;

    for (int i = 1; i <= G.n; i++)
    {
        mark[i] = 0;
        rank[i] = 1;
        for (int j = 0; j < G.n; j++)
            G.A[i][j] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G.A[u][v] = 1;
    }
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 0)
        {
            toPoDFS(&G, i, count);
            count++;
        }
    }
    int total = 0;
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", rank[i]);
        total += rank[i];
    }
    printf("%d", total);
}
