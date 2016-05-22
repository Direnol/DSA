#ifndef GRAPH_H
#define GRAPH_H

#include "queue.h"
#include <stdio.h>
#include "binary_heap.h"
#include "limits.h"

struct g_path {
    int pathlen;
    int *path;
};

struct graph {
    int nvertices; /* Число вершин */
    int **m; /* Матрица n x n */
    int *visited;
};

struct graph *graph_create(int nvertices);
void graph_clear(struct graph *g);
void graph_free(struct graph *g);
void graph_set_edge(struct graph *g, int i, int j, int w);
int graph_get_edge(struct graph *g, int i, int j);
void graph_dfs(struct graph *g, int v);
void graph_bfs(struct graph *g, int v);
int graph_nvertices(struct graph *g);
struct path *Serch_Shortest_Path(struct graph *g, int src, int dest);
void ShortestPath_Dijekstra(struct graph *g, int src, int *d, int *prev);

#endif
