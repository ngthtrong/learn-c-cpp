#include <stdio.h>
#include "2-LinkedList/tmt/plistlib.h"

#define MAX 100

typedef struct
{
    int n;       // number of vertices
    int m;       // number of edges
    List A[MAX]; // adjacency list
} Graph;

void init_graph(Graph *g, int n)
{
    g->n = n;
    g->m = 0;
    for (int i = 1; i <= n; i++)
    {
        makeNull(&g->A[i]); // Initialize each adjacency list
    }
}
int adjacent(Graph *g, int u, int v)
{
    if (locate(v, g->A[u]) != -1 || locate(v, g->A[u]) != -1)
        return 1;

    return 0;
}
List neighbors(Graph *g, int u)
{
    return g->A[u];
}
void add_edge(Graph *g, int u, int v)
{
    if (u > 0 && u <= g->n && v > 0 && v <= g->n)
    {
        append(v, &(g->A[u]));
        if (u != v)
            append(u, &(g->A[v]));
    }
    g->m++;
}
void remove_edge(Graph *g, int u, int v)
{
    
}
int degree(Graph *g, int u)
{
}