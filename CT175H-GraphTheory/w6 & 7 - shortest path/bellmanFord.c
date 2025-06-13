#include <stdio.h>
#define MAX 101
#define oo 99999
int d[MAX];
int p[MAX];
int c[MAX];

typedef struct
{
    int n, m;
    int A[MAX][MAX];
} Graph;

// Bellman-Ford: KHÔNG PHẢI là quy hoạch động thuần túy
// Đây là thuật toán RELAXATION (nới lỏng) - duyệt tất cả cạnh nhiều lần
// Nguyên lý: Sau k lần lặp, tìm được đường ngắn nhất có tối đa k cạnh
void bellman_ford(Graph const *G, int s)
{
    d[s] = 0;
    // Lặp tối đa V-1 lần (không phải DP table)
    // Mỗi lần duyệt TẤT CẢ các cạnh để relaxation
    for (int i = 1; i <= G->n-1; i++)  // Sai: nên là G->n-1 lần lặp
    {
        // Duyệt tất cả các cạnh - KHÔNG có tính chất con tối ưu rõ ràng
        for (int u = 1; u <= G->n; u++)
            for (int v = 1; v <= G->n; v++)
            {
                if (G->A[u][v] != 0 && u != v)
                {
                    // RELAXATION: Cập nhật nếu tìm được đường ngắn hơn
                    // Không có công thức truy hồi DP rõ ràng
                    if (d[v] > d[u] + G->A[u][v])
                    {
                        d[v] = d[u] + G->A[u][v];
                        p[v] = u;
                        c[v] = c[u];
                    }
                    else if (d[v] == d[u] + G->A[u][v])
                        c[v] += c[u];
                }
            }
    }
}

void printPath(int s, int t)
{
    if (t == s)
        return;
    printPath(s, p[t]);
    printf(" -> %d", t);
}

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    Graph G;
    G.n = n;
    G.m = m;
    for (int i = 1; i <= n; i++)
    {
        d[i] = oo;
        p[i] = -1;
        c[i] = 1;
        for (int j = 1; j <= n; j++)
            G.A[i][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        int u;
        int v;
        int w;
        scanf("%d%d%d", &u, &v, &w);
        G.A[u][v] = w;
        // G.A[v][u] = w;
        if (u == 1)
            c[v] = 1;
        if (v == 1)
            c[u] = 1;
    }
    int s,t;
    scanf("%d%d",&s,&t);
    bellman_ford(&G, s);
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         printf("%d ", G.A[i][j]);
    //     }
    //     printf("\n");
    // }
    if (d[t] == oo)
        printf("-1");
    else
        printf("%d", d[t]);
    //===
    // if (d[n] == oo)
    //     printf("-1 0");
    // else
    //     printf("%d %d", d[n], c[n]);
    //===
    // printf("%d",s);
    // printPath(s,t);
    //===
    // for (int i = 1; i <= G.n; i++)
    // {
    //     printf("pi[%d] = %d, p[%d] = %d\n", i, d[i], i, p[i]);
    // }
}