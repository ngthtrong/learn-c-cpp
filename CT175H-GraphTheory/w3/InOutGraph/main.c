#include <stdio.h>

typedef struct
{
    int u, v;

} Edge;

typedef struct
{
    int n, m;
    int A[100][100];

} Graph;

int main()
{
    int n, m;
    freopen("dt1.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    Graph G;
    G.n = n;
    G.m = m;
    for (int i = 1; i <= m; i++)
    {
        int tempu;
        int tempv;
        scanf("%d%d", &tempu, &tempv);
        G.A[tempu][tempv]++;
        G.A[tempv][tempu]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("%d ", G.A[i][j]);
        }
        printf("\n");
    }
}
