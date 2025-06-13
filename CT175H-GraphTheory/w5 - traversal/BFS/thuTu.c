#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100
#define VISITTED 1
#define UNVISITTED 0

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
Queue q;
typedef struct
{
    int m, n;
    int e[MAX_SIZE][MAX_SIZE];
} Graph;

void BFS(Graph *pg)
{

    while (!emptyQueue(q))
    {
        int s = deQueue(&q);
        if (mark[s] == VISITTED)
            continue;
        for (int i = 1; i <= pg->n; i++)
        {
            if (mark[i] == UNVISITTED && pg->e[s][i] == 1)
            {
                enQueue(i, &q);
            }
        }
        mark[s] = VISITTED;
        printf("%d\n", s);
    }
}

int main(int argc, char const *argv[])
{
    // freopen("dt.txt", "r", stdin); // Khi nộp bài nhớ bỏ dòng này.
    Graph G;
    int n, m, u, v, e;
    scanf("%d%d", &n, &m);
    G.m = m;
    G.n = n;

    for (int i = 1; i <= G.n; i++)
    {
        for (int j = 0; j < G.n; j++)
            G.e[i][j] = 0;
    }

    for (e = 1; e <= m; e++)
    {
        mark[e] = UNVISITTED;
        scanf("%d%d", &u, &v);
        G.e[u][v] = 1;
        G.e[v][u] = 1;
    }
    int s;
    scanf("%d", &s);
    makeNull(&q);
    enQueue(s, &q);
    BFS(&G);
}