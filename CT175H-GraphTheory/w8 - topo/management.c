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
// int maxx;
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
    // int index;
    for (int i = 1; i <= n; i++)
        if (max < a[i])
        {
            max = a[i];
            // index = i;
        }
    // maxx = index;
    return max;
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
    // maxx = d[maxx] + count;
    // get max
    for (int i = 1; i <= n; i++)
        if (mark[i] == 0)
        {
            toPoDFS2(&G, i, count);
            count -= d[i];
        }
    // printf("%d\n", maxx);
    for (int i = 1; i <= n; i++)
        // printf("%d %d\n", min[i], max[i]);
        printf("%d-%d\n", min[i], max[i]);
    // printf("%d-%d\n", 0, 0);
    // printf("%d-%d\n",maxx, maxx);
}
// Graph 1 matrix:
// 1 2 7
// 2 3 3
// 1 4 7
// 3 5 1
// 4 5 8
// 3 6 1
// 4 6 8
// 3 7 1
// 4 7 8
// 6 8 1
// 8 9 2
// 5 10 2
// 7 10 1
// 9 10 2

// for (int i = 0; i < n; i++)
// {
//     for (int j = 0; j < n; j++)
//         printf("%d ", G.A[i + 1][j + 1]);
//     printf("\n");
// }