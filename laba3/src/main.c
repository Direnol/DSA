#include <stdio.h>
#include "graph.h"
#include "binary_heap.h"

int main ()
{
    struct graph *g;
    g = graph_create(20);
    graph_set_edge(g, 1, 2, 3);
    graph_set_edge(g, 1, 3, 5);
    graph_set_edge(g, 1, 4, 2);
    graph_set_edge(g, 1, 16, 1);
    graph_set_edge(g, 1, 14, 7);
    graph_set_edge(g, 1, 7, 6);
    graph_set_edge(g, 2, 13, 4);
    graph_set_edge(g, 2, 6, 10);
    graph_set_edge(g, 3, 6, 3);
    graph_set_edge(g, 3, 4, 1);
    graph_set_edge(g, 3, 8, 1);
    graph_set_edge(g, 4, 17, 10);
    graph_set_edge(g, 4, 12, 3);
    graph_set_edge(g, 5, 17, 11);
    graph_set_edge(g, 6, 11, 1);
    graph_set_edge(g, 7, 9, 3);
    graph_set_edge(g, 7, 18, 6);
    graph_set_edge(g, 8, 11, 4);
    graph_set_edge(g, 8, 10, 2);
    graph_set_edge(g, 9, 10, 6);
    graph_set_edge(g, 9, 12, 13);
    graph_set_edge(g, 9, 19, 1);
    graph_set_edge(g, 13, 14, 1);
    graph_set_edge(g, 14, 15, 6);
    graph_set_edge(g, 15, 16, 1);
    graph_set_edge(g, 16, 17, 8);
    graph_set_edge(g, 18, 20, 1);
    graph_set_edge(g, 19, 20, 1);
    
    
    int *prev = malloc(g->nvertices * sizeof(int));
    int *d = malloc(g->nvertices * sizeof(int));
    
    struct g_path *path;
    
    for (int i = 2; i <= g->nvertices; i++) {
	printf("Min path from 1 to %d\n", i);
	path = Serch_Shortest_Path(g, 1, i);
	printf("partlen: %d\n", path->pathlen);
	printf("path ");
	for (int j = 0; j <= path->edge; j++) {
	    printf("%d ", path->path[j]);
	}
	printf("\n\n");
    }
    
    return 0;
}
