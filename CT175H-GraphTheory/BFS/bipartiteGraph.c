#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define BLACK 2
#define RED 1
#define SUM 3
#define NO 0

int color[MAX_SIZE + 1];
int conflict = 0;

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

Queue q;

typedef struct
{
    int m, n;
    int e[MAX_SIZE][MAX_SIZE];
} Graph;

void BFS(Graph *pg, int s)
{
    color[s] = RED;
    while (!emptyQueue(q))
    {
        int r = deQueue(&q);
        for (int i = 1; i <= pg->n; i++)
        {
            if (pg->e[r][i] == 1)
            {
                if (color[i] == NO)
                {
                    color[i] = SUM - color[r];
                    enQueue(i, &q);
                }
                else if (color[i] == color[r])
                {
                    conflict = 1;
                    return;
                }
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    G.m = m;
    G.n = n;

    for (int i = 0; i <= G.n; i++)
    {
        for (int j = 0; j < G.n; j++)
            G.e[i][j] = 0;
    }

    for (e = 0; e < m; e++)
    {
        color[e + 1] = NO;
        scanf("%d%d", &u, &v);
        G.e[u][v] = 1;
        G.e[v][u] = 1;
    }
    int s;
    scanf("%d", &s);
    makeNull(&q);
    enQueue(1, &q);
    BFS(&G, 1);
    if (conflict == 1)
        printf("IMPOSSIBLE");
    else
    {
        for (int i = 1; i <= G.n; i++)
        {
            if (color[i] == RED)
            {
                printf("%d ", i);
            }
        }
        printf("\n");
        for (int i = 1; i <= G.n; i++)
        {
            if (color[i] == BLACK)
            {
                printf("%d ", i);
            }
        }
    }
}