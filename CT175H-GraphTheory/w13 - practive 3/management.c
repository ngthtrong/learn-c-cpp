#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
int mark[MAX_SIZE + 1];
int rank[MAX_SIZE + 1];
int d[MAX_SIZE + 1];
typedef struct
{
    int m, n;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void toPoDFS(Graph *g, int u, int c)
{
    mark[u] = 1;
    int max = 0;
    for (int i = 1; i <= g->n; i++)
    {

        if (g->A[i][u] == 0 || u == i)
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
    int n;
    scanf("%d", &n);
    G.n = n;

    for (int i = 1; i <= G.n; i++)
    {
        mark[i] = 0;
        rank[i] = 0;
        int temp;
        scanf("%d", &temp);
        d[i] = temp;
        while (temp != 0)
        {
            scanf("%d", &temp);
            G.A[temp][i] = d[i];
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (mark[i] == 0)
        {

            toPoDFS(&G, i, count);
            count++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        // printf("r[%d] = %d\n", i, rank[i]);
        printf("%d ", rank[i] + 1);
    }
}
