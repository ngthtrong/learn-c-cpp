#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

// Graph structure with adjacency matrix
typedef struct {
    int A[MAX_VERTICES][MAX_VERTICES];
    int n; // number of vertices
} Graph;

// Queue structure for BFS
typedef struct {
    int items[MAX_VERTICES];
    int front, rear;
} Queue;

// Queue operations
Queue* createQueue() {
    Queue* q = (Queue*)malloc(sizeof(Queue));
    q->front = -1;
    q->rear = -1;
    return q;
}

int isEmpty(Queue* q) {
    return q->rear == -1;
}

void enqueue(Queue* q, int value) {
    if (q->rear == MAX_VERTICES - 1)
        printf("Queue is full");
    else {
        if (q->front == -1)
            q->front = 0;
        q->rear++;
        q->items[q->rear] = value;
    }
}

int dequeue(Queue* q) {
    int item;
    if (isEmpty(q)) {
        printf("Queue is empty");
        item = -1;
    } else {
        item = q->items[q->front];
        q->front++;
        if (q->front > q->rear) {
            q->front = -1;
            q->rear = -1;
        }
    }
    return item;
}

// Graph operations
void init_graph(Graph* G, int n) {
    G->n = n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            G->A[i][j] = 0;
}

void add_edge(Graph* G, int u, int v) {
    G->A[u][v] = 1;
    G->A[v][u] = 1; // For undirected graph
}

// BFS algorithm
void BFS(Graph* G, int start) {
    Queue* q = createQueue();
    int visited[MAX_VERTICES] = {0};
    
    // Visit and enqueue the start vertex
    printf("%d\n", start);
    visited[start] = 1;
    enqueue(q, start);
    
    while (!isEmpty(q)) {
        int current = dequeue(q);
        
        // Visit all adjacent vertices in ascending order
        for (int i = 1; i <= G->n; i++) {
            if (G->A[current][i] == 1 && !visited[i]) {
                printf("%d\n", i);
                visited[i] = 1;
                enqueue(q, i);
            }
        }
    }
    
    free(q);
}

int main() {
    // freopen("dt.txt", "r", stdin); // Uncomment when testing locally, remove when submitting
    
    Graph G;
    int n, m, u, v, e;
    
    scanf("%d%d", &n, &m);
    init_graph(&G, n);
    
    for (e = 0; e < m; e++) {
        scanf("%d%d", &u, &v);
        add_edge(&G, u, v);
    }
    
    BFS(&G, 1); // Start BFS from vertex 1
    
    return 0;
}
