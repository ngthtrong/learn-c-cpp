#include <stdio.h>
#define MAX 10
#define oo 999
int d[MAX][MAX];
int M[MAX][MAX];
int minDistance(int i, int j)
{
    int rs = oo;
    for (int u = i - 1; u <= i + 1; u++)
    {
        for (int v = j - 1; v <= j + 1; v++)
        {
            if (u == i && v == j)
                continue;
            if (rs > d[u][v] && (u == i || v == j))
                rs = d[u][v];
        }
    }
    return rs;
}
void moore_dijkstra(int n, int m)
{
    d[1][1] = M[1][1] = 0;
    int isChanged = 1;
    while (isChanged)
    {
        isChanged = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (d[i][j] > minDistance(i, j) + M[i][j])
                {
                    d[i][j] = minDistance(i, j) + M[i][j];
                    isChanged = 1;
                }
            }
        }
    }
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i <= n + 1; i++)
    {
        for (int j = 0; j <= m + 1; j++)
        {
            d[i][j] = oo;
            if (i == 0 || j == 0 || i == n + 1 || j == m + 1)
                M[i][j] = oo;
            else
                scanf("%d", &M[i][j]);
        }
    }
    moore_dijkstra(n, m);
    printf("%d\n", d[n][m]);
}