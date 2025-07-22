#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

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

#define M 100
typedef struct
{
    int m, n;
    int A[M][M];
} Graph;
int in_degree[M];
Queue q;
void topoSort(Graph *g)
{
    while (!emptyQueue(q))
    {
        int u = deQueue(&q);
        printf("%d ", u);
        for (int i = 1; i <= g->n; i++)
        {
            if (g->A[u][i] == 1)
            {
                if (--in_degree[i] == 0)
                    enQueue(i, &q);
            }
        }
    }
}

int main()
{
    Graph G;
    int m, n;
    scanf("%d%d", &n, &m);
    G.n = n;
    G.m = m;

    // Khởi tạo
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            G.A[i][j] = 0;
        }
        in_degree[i] = 0;
    }

    for (int i = 1; i <= m; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        G.A[u][v] = 1;
        in_degree[v]++;
    }
    makeNull(&q);

    for (int i = 1; i <= n; i++)
    {
        if (in_degree[i] == 0)
        {
            enQueue(i, &q);
        }
    }
    topoSort(&G);

    return 0;
}