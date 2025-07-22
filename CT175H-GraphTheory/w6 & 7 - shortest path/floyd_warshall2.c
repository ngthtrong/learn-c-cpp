#include <stdio.h>
#define M 100
#define oo 99999
int d[M][M];
int p[M][M];

void floyd_warshall(int n)
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (d[i][k] != oo && d[k][j] != oo && d[i][j] > d[i][k] + d[k][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    p[i][j] = k;
                }
}


void printPath(int s, int t){
    if( s ==t ){
        printf("%d", s);
        return;
    }
    printPath(s, p[t]);
    printf(" -> %d", t);
}

int main()
{
    int n, m;

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d[i][j] = oo;
            if (i == j)
                d[i][j] = 0;
            p[i][j] = -1;
        }
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        d[u][v] = w;
    }
    floyd_warshall(n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            printf("path(%d, %d): ", i, j);
            if (d[i][j] == oo)
                printf("NO PATH\n");
            else
                printPath(i, j);
        }
    }
}