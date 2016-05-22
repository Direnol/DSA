#include <stdio.h>
#include "graph.h"
#include <binary_heap.h>

int main ()
{
    struct graph *g;
    g = graph_create(5);
    graph_set_edge(g, 1, 2, 10);
    graph_set_edge(g, 1, 4, 30);
    graph_set_edge(g, 2, 3, 50);
    graph_set_edge(g, 1, 5, 100);
    graph_set_edge(g, 4, 5, 60);
    graph_set_edge(g, 4, 3, 20);
    graph_set_edge(g, 5, 3, 10);
    
    
    
    int *prev = malloc(g->nvertices * sizeof(int));
    int *d = malloc(g->nvertices * sizeof(int));
    
    ShortestPath_Dijekstra(g, 1, d, prev);
    
    for(int i = 1; i <= g->nvertices; i++) {
	printf("prev %d - %d\n", i, prev[i]);
	printf("dl%d %d\n", i, d[i]);
    }
    return 0;
}
