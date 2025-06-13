#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define UNVISITED 0
#define NGHICH -1
#define THUAN 1
#define oo 999
typedef int ElementType;
typedef struct
{
    ElementType elements[MAX];
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
    if (q->front != 0 && q->rear == MAX)
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

int mark[MAX];
int parent[MAX];
int sigma[MAX];

typedef struct
{
    int n, m;
    int capacity[MAX][MAX];
    int flow[MAX][MAX];
} Graph;

int findIncreasePath(Graph *g, int s, int t)
{
    for (int i = 1; i <= g->n; i++)
    {
        mark[i] = UNVISITED;
        parent[i] = i;
        sigma[i] = 0;
    }
    Queue q;
    makeNull(&q);
    sigma[s] = oo;
    mark[s] = THUAN;
    parent[s] = s;
    enQueue(s, &q);
    while (!emptyQueue(q))
    {
        int u = deQueue(&q);
        for (int i = 1; i <= g->n; i++)
        {
            if (mark[i] != UNVISITED || i == u)
                continue;
            if (g->capacity[u][i] - g->flow[u][i] > 0)
            {
                mark[i] = THUAN;
                parent[i] = u;
                sigma[i] = sigma[u] < g->capacity[u][i] - g->flow[u][i] ? sigma[u] : g->capacity[u][i] - g->flow[u][i];
                enQueue(i, &q);
            }
            if (g->flow[i][u] > 0)
            {
                mark[i] = NGHICH;
                parent[i] = u;
                sigma[i] = sigma[u] < g->flow[i][u] ? sigma[u] : g->flow[i][u];
                enQueue(i, &q);
            }
        }
        if (sigma[t] > 0)
            return 1;
    }
    return 0;
}

int ford_fulkerson(Graph *g, int s, int t)
{
    int max = 0;
    while (findIncreasePath(g, s, t))
    {
        int increase = sigma[t];
        for (int v = t; v != s; v = parent[v])
        {
            int u = parent[v];
            g->flow[u][v] += increase * mark[v];
        }
        max += increase;
    }
    return max;
}

void printMinCut(Graph *g)
{
    printf("S:");
    for (int i = 1; i <= g->n; i++)
        if (mark[i] != UNVISITED)
            printf(" %d", i);
    printf("\n");
    printf("T:");
    for (int i = 1; i <= g->n; i++)
        if (mark[i] == UNVISITED)
            printf(" %d", i);
}

int main()
{
    Graph G;
    scanf("%d%d", &G.n, &G.m);

    for (int i = 0; i < G.n + 1; i++)
        for (int j = 0; j < G.n + 1; j++)
        {
            G.capacity[i][j] = 0;
            G.flow[i][j] = 0;
        }
    for (int i = 1; i <= G.m; i++)
    {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G.capacity[u][v] = w;
    }
    printf("Max flow: %d\n", ford_fulkerson(&G, 1, G.n));
    printMinCut(&G);
}
