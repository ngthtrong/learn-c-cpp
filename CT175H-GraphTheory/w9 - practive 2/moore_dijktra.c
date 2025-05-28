#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define VISITTED 1

#define UNVISITTED 0
#define oo 999

typedef int ElementType;
typedef struct
{
    ElementType elements[MAX_SIZE];
    int front, rear;
} Queue;

void makeNull(Queue *q)
{
    q->front = 0;
    q->rear = 0;
}
int emptyQueue(Queue q)
{
    return (q.front == q.rear);
}
void shiftLeft(int n, Queue *q)
{
    for (int i = 0; i < q->rear - q->front; i++)
        q->elements[i] = q->elements[i + n];
    q->front = 0;
    q->rear -= n;
}
void enQueue(ElementType x, Queue *q)
{
    if (q->front != 0 && q->rear == MAX_SIZE)
        shiftLeft(q->front, q);
    q->elements[q->rear++] = x;
}
ElementType deQueue(Queue *q)
{
    if (!emptyQueue(*q))
    {
        ElementType rs = q->elements[q->front];
        if (q->front == q->rear - 1)
            makeNull(q);
        else
            q->front++;
        return rs;
    }
    printf("deQueue: stack empty\n");
    exit(EXIT_FAILURE);
}

int mark[MAX_SIZE + 1];
int status[MAX_SIZE + 1];
int parent[MAX_SIZE + 1];
int d[MAX_SIZE + 1];
typedef struct
{
    int m, n;
    int A[MAX_SIZE][MAX_SIZE];
} Graph;

void moore_dijkstra(Graph *g, int s)
{
    d[s] = 0;
    Queue q;
    makeNull(&q);
    enQueue(s, &q);
    while (!emptyQueue(q))
    {
        int u = deQueue(&q);
        // mark[u] = VISITTED;
        for (int v = 1; v <= g->n; v++)
        {
            if (u != v && g->A[u][v] >= 0)
            {
                if (d[v] > d[u] + g->A[u][v])
                {
                    d[v] = d[u] + g->A[u][v];
                    parent[v] = u;
                    enQueue(v, &q);
                }
            }
        }
    }
}

void printPath(int s, int t)
{
    if (t == s)
        return;
    printPath(s, parent[t]);
    printf(" -> %d", t);
}

int main(int argc, char const *argv[])
{
    // freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, w;
    scanf("%d%d", &n, &m);
    G.m = m;
    G.n = n;

    for (int i = 0; i <= G.n; i++)
    {
        parent[i] = -1;
        mark[i] = UNVISITTED;
        d[i] = oo;
        for (int j = 0; j <= G.n; j++)
            G.A[i][j] = -1;
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        G.A[u][v] = w;
        G.A[v][u] = w;
    }
    int s, t;
    scanf("%d%d", &s, &t);
    moore_dijkstra(&G, s);

    // for (int i = 1; i <= G.n; i++)
    // {
    //     printf("pi[%d] = %d, p[%d] = %d\n", i, d[i], i, parent[i]);
    // }
    //===
    // if (d[n] == oo)
    //     printf("-1");
    // else
    //     printf("%d", d[n]);
    //===
    printf("%d", s);
    printPath(s, t);
}