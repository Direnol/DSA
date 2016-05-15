#include <stdio.h>
#include "graph.h"
#include "binary_heap.h"

int main ()
{
    struct graph *g;
    g = graph_create(10);
    graph_set_edge(g, 2, 1, 1);
    graph_set_edge(g, 2, 3, 1);
    graph_set_edge(g, 2, 5, 1);
    graph_set_edge(g, 1, 4, 1);
    graph_set_edge(g, 1, 5, 1);
    graph_set_edge(g, 3, 5, 1);
    graph_set_edge(g, 3, 4, 1);
    graph_set_edge(g, 4, 5, 1);
    graph_set_edge(g, 4, 6, 1);
    graph_set_edge(g, 6, 7, 1);
    graph_set_edge(g, 7, 8, 1);
    graph_set_edge(g, 8, 3, 1);
    graph_set_edge(g, 8, 9, 1);
    graph_set_edge(g, 8, 10, 1);
    
    int n = 2;
    
    printf("DFS:\n");
    graph_dfs(g, n);
    
    printf("BFS:\n");
    graph_bfs(g, n);
    
    graph_free(g);
    
    
    
    struct heap *heap_node;
    
    heap_node = heap_create(5);
    
    heap_insert(heap_node, 5, "drty");
    heap_insert(heap_node, 3, "kdgjoiuer");
    heap_insert(heap_node, 1, "kkfgjo");
    heap_insert(heap_node, 7, "dryyu");
    heap_insert(heap_node, 2, "dhgi");
    
    struct heapnode min;
    min = heap_extract_min(heap_node);
    printf("min heap %d\n", min.key);
    
    struct heapnode *node;
    node = heap_min(heap_node);
    
    printf("min heap %d\n", node->key);
    return 0;
}
