#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int mark[MAX_SIZE + 1];
int d[MAX_SIZE + 1];
int min[MAX_SIZE + 1];
typedef struct
{
    int n, m;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void toPoDFS(Graph *g, int u, int c)
{
    mark[u] = 1;
    int maxNum = 0;
    for (int i = 1; i <= g->n; i++)
    {
        if (g->A[i][u] == 0 || u == i)
            continue;
        if (mark[i] == 0)
            toPoDFS(g, i, c);
        maxNum = maxNum > min[i] + d[i] ? maxNum : min[i] + d[i];
    }
    min[u] = maxNum;
}

int myMax(int *a, int n, int *d)
{
    int max = 0;
    for (int i = 1; i <= n; i++)
        if (max < a[i] + d[i])
            max = a[i] + d[i];
    return max;
}

int main(int argc, char const *argv[])
{
    // freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m;
    scanf("%d", &n);
    G.n = n;
    for (int i = 1; i <= n; i++)
    {
        mark[i] = 0;
        min[i] = 0;
        scanf("%d", &d[i]);
    }
    scanf("%d", &m);
    G.m = m;

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G.A[u][v] = d[u];
    }

    // get min
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (mark[i] == 0)
        {
            toPoDFS(&G, i, count);
            count += d[i];
        }

    printf("%d\n", myMax(min, n, d));
}
