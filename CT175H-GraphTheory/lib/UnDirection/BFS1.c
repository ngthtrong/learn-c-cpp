#include <stdio.h>
#include "2-LinkedList/tmt/plistlib.h"

#define MAX 100
typedef struct
{
    int u;
    int v;
} Edge;
typedef struct
{
    int n;           // number of vertices
    int m;           // number of edges
    Edge edges[MAX]; // maximum of 100 edges
} Graph;

void init_graph(Graph *g, int n)
{
    g->n = n;
    g->m = 0;
    for (int i = 0; i < 100; i++)
    {
        g->edges[i].u = 0;
        g->edges[i].v = 0;
    }
}
int adjacent(Graph *g, int u, int v)
{
    for (int i = 0; i < g->m; i++)
    {
        if ((g->edges[i].u == u && g->edges[i].v == v) ||
            (g->edges[i].u == v && g->edges[i].v == u))
        {
            return 1; // Edge exists
        }
    }
    return 0; // Edge does not exist
}
List neighbors(Graph *g, int u)
{
    List neighbors;
    makeNull(&neighbors);
    for (int i = 0; i < g->m; i++)
    {
        if (g->edges[i].u == u)
        {
            insertFirst(g->edges[i].v, &neighbors);
        }
        else if (g->edges[i].v == u)
        {
            insertFirst(g->edges[i].u, &neighbors);
        }
    }
    return neighbors;
}
void add_edge(Graph *g, int u, int v)
{
    if (g->m < MAX)
    {
        g->edges[g->m].u = u;
        g->edges[g->m].v = v;
        g->m++;
    }
    else
    {
        printf("Graph is full, cannot add more edges.\n");
    }
}
void remove_edge(Graph *g, int u, int v)
{
    for (int i = 0; i < g->m; i++)
    {
        if ((g->edges[i].u == u && g->edges[i].v == v) ||
            (g->edges[i].u == v && g->edges[i].v == u))
        {
            // Shift edges to remove the edge
            for (int j = i; j < g->m - 1; j++)
            {
                g->edges[j] = g->edges[j + 1];
            }
            g->m--;
            return;
        }
    }
}
int degree(Graph *g, int u)
{
    int deg = 0;
    for (int i = 0; i < g->m; i++)
    {
        if (g->edges[i].u == u)
        {
            deg++;
        }
        else if (g->edges[i].v == u)
        {
            deg++;
        }
    }
    return deg;
}