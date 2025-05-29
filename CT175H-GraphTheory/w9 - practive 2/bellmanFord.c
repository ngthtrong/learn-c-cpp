#include <stdio.h>
#include <limits.h>

#define MAXN 100
#define MAXM 500
#define INFINITY INT_MAX

typedef struct {
    int u, v, w;
} Edge;

typedef struct {
    int n, m;
    Edge edges[MAXM];
} Graph;

void init_graph(Graph *G, int n) {
    G->n = n;
    G->m = 0;
}

void add_edge(Graph *G, int u, int v, int w) {
    G->edges[G->m].u = u;
    G->edges[G->m].v = v;
    G->edges[G->m].w = w;
    G->m++;
}

int pi[MAXN + 1];
int p[MAXN + 1];

void bellman_ford(Graph *G, int s) {
    int i, j;
    for (i = 1; i <= G->n; i++) {
        pi[i] = INFINITY;
        p[i] = -1;
    }
    pi[s] = 0;

    for (i = 1; i < G->n; i++) {
        for (j = 0; j < G->m; j++) {
            int u = G->edges[j].u;
            int v = G->edges[j].v;
            int w = G->edges[j].w;
            if (pi[u] != INFINITY && pi[u] + w < pi[v]) {
                pi[v] = pi[u] + w;
                p[v] = u;
            }
        }
    }
}

int main() {
    Graph G;
    int n, m, i;
    scanf("%d %d", &n, &m);
    init_graph(&G, n);

    for (i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        add_edge(&G, u, v, w);
    }

    int s, t;
    scanf("%d %d", &s, &t);

    bellman_ford(&G, s);

    if (pi[t] == INFINITY) {
        printf("-1\n");
    } else {
        printf("%d\n", pi[t]);
    }

    return 0;
}
