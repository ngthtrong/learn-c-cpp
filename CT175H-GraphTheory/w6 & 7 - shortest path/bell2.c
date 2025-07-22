#include <stdio.h>
#define M 100
#define oo 9999
int d[M];
int A[M][M];
int m, n;

void bellman_ford(int s)
{
    d[s] = 0;
    for (int e = 1; e < m; e++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                if (A[u][v])
                {
                    if (d[v] > d[u] + A[u][v]&& d[u]!=oo)
                    {
                        d[v] = d[u] + A[u][v];
                    }
                }
            }
        }
    }
}

int check(int s)
{
    d[s] = 0;
    for (int u = 1; u <= n; u++)
    {
        for (int v = 1; v <= n; v++)
        {
            if (A[u][v])
            {
                if (d[v] > d[u] + A[u][v] && d[u]!=oo )
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            d[i] = oo;
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        A[u][v] = w;
    }
    int s;
    scanf("%d", &s);
    bellman_ford(s);

    if(check(s)) printf("YES");
    else printf("NO");
}