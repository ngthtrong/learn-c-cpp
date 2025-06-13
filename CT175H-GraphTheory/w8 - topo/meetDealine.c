#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int mark[MAX_SIZE + 1];
int d[MAX_SIZE + 1];
int min[MAX_SIZE + 1];
int max[MAX_SIZE + 1];
typedef struct
{
    int n;
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

void toPoDFS2(Graph *g, int u, int c)
{
    mark[u] = 1;
    int minNUm = c;
    for (int i = 1; i <= g->n; i++)
    {
        if (g->A[u][i] == 0 || u == i)
            continue;
        if (mark[i] == 0)
            toPoDFS2(g, i, c);
        minNUm = minNUm < max[i] - d[u] ? minNUm : max[i] - d[u];
    }
    max[u] = minNUm;
}

int myMax(int *a, int n)
{
    int max = 0;
    for (int i = 1; i <= n; i++)
        if (max < a[i])
            max = a[i];
    return max;
}

int main(int argc, char const *argv[])
{
    Graph G;
    int n;
    scanf("%d", &n);
    G.n = n;
    for (int i = 1; i <= G.n; i++)
    {
        mark[i] = 0;
        min[i] = 0;
        max[i] = 0;
        int temp;
        scanf("%d", &temp);
        d[i] = temp;
        while (temp != 0)
        {
            scanf("%d", &temp);
            if (temp == 0)
                break;
            G.A[temp][i] = temp;
        }
    }

    // int u, t;
    // scanf("%d%d", &u, &t);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if (G.A[i][j] > 0)
                G.A[i][j] = d[G.A[i][j]];

    // get min
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (mark[i] == 0)
        {
            toPoDFS(&G, i, count);
            count += d[i];
        }

    // reset state visit of all vertices
    for (int i = 0; i <= n; i++)
        mark[i + 1] = 0;
    count = myMax(min, n);
    // get max
    for (int i = 1; i <= n; i++)
        if (mark[i] == 0)
        {
            toPoDFS2(&G, i, count);
            count -= d[i];
        }

    // if (t <= max[u] && t >= min[u])
    //     printf("YES");
    // else
    //     printf("NO");

    for (int i = 1; i <= n + 2; i++)
        if (max[i] == min[i]||i==n+2||i==n+1)
            printf("%d\n", i);
}