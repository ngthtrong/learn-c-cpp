#include <stdio.h>
#include "2-LinkedList/tmt/plistlib.h"
#define MAX 100
typedef struct
{
    int n;           // number of vertices
    int m;           // number of edges
    int A[MAX][MAX]; // adjacency matrix
} Graph;

void init_graph(Graph *g, int n)
{
    g->n = n;
    g->m = 0;
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            g->A[i][j] = 0;
        }
    }
}
int adjacent(Graph *g, int u, int v)
{
    return g->A[u][v] == 1;
}
List neighbors(Graph *g, int u)
{
    List neighbors;
    makeNull(&neighbors);
    for (int v = 0; v < g->n; v++)
    {
        if (g->A[u][v] == 1)
        {
            insertFirst(v, &neighbors);
        }
    }
    return neighbors;
}
void add_edge(Graph *g, int u, int v)
{
    if (u < g->n && v < g->n)
    {
        g->A[u][v] = 1;
        g->A[v][u] = 1;
    }
}
void remove_edge(Graph *g, int u, int v)
{
    if (u < g->n && v < g->n)
    {
        g->A[u][v] = 0;
        g->A[v][u] = 0;
    }
}
int degree(Graph *g, int u)
{
    if (u < g->n)
    {
        int deg = 0;
        for (int v = 0; v < g->n; v++)
        {
            if (g->A[u][v] == 1)
            {
                deg++;
            }
        }
        return deg;
    }
    return -1; // Invalid vertex
}
