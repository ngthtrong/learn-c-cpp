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
    for (int i = 0; i < MAX; i++)
    {
        makeNull(&g->A[i]); // Initialize each adjacency list
    }
}
int adjacent(Graph *g, int u, int v)
{
    
}
List neighbors(Graph *g, int u)
{
}
void add_edge(Graph *g, int u, int v)
{
}
void remove_edge(Graph *g, int u, int v)
{
}
int degree(Graph *g, int u)
{
}