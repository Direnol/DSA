#include "graph.h"


struct graph *graph_create(int nvertices)
{
    struct graph *g;
    g = malloc(sizeof(*g));
    g->nvertices = nvertices;
    g->visited = malloc(sizeof(int) * (nvertices + 1));
    g->m = (int **) malloc(nvertices * sizeof(int *));
    if (g->m != NULL) {
        for (int i = 0; i < nvertices; i++) {
            g->m[i] = (int *) malloc(nvertices * sizeof(int));
        }
    }
    else {
        printf("Can't create buffer!\n");
    }
    graph_clear(g); // Опционально, O(n^2)
    return g;
}

void graph_clear(struct graph *g)
{
    int i, j;
    for (i = 0; i < g->nvertices; i++) {
	g->visited[i] = 0;
	for (j = 0; j < g->nvertices; j++) {
	    g->m[i][j] = 0;
	}
    }
}

void graph_free(struct graph *g)
{
    for (int i = 0; i < g->nvertices; i++)
	free(g->m[i]);
    free(g->m);
    free(g);
}

void graph_set_edge(struct graph *g, int i, int j, int w)
{
    g->m[i - 1][j - 1] = w;
    g->m[j - 1][i - 1] = w;
}

int graph_get_edge(struct graph *g, int i, int j)
{
    return g->m[i - 1][j - 1];
}

void graph_dfs(struct graph *g, int v)
{
    int i;
    g->visited[v - 1] = 1;
    printf("Vertex %d\n", v);
    for (i = 0; i < g->nvertices; i++) {
	if (g->m[v - 1][i] > 0 && g->visited[i] == 0) {
	    graph_dfs(g, i + 1);
	}
    }
}

void graph_bfs(struct graph *g, int v)
{
    int i, j;
    struct queue *q;
    for (i = 0; i < g->nvertices; i++)
	g->visited[i] = 0;
    // Создаем очередь
    q = queue_create();
    // Обрабатываем стартовую вершину
    g->visited[v - 1] = 1;
    printf("Vertex %d\n", v);
    queue_enqueue(q, v - 1);
    while (queue_size(q) > 0) {
	i = queue_dequeue(q);
	for (j = 0; j < g->nvertices; j++) {
	    if (g->m[i][j] > 0 && g->visited[j] == 0) {
		queue_enqueue(q, j);
		g->visited[j] = 1;
		printf("Vertex %d\n", j + 1);
	    }
	}
    }
    queue_free(q);
}

int graph_nvertices(struct graph *g)
{
    return g->nvertices;
}

struct path *Serch_Shortest_Path(struct graph *g, int src, int dest)
{
    
    struct g_path *p;
    p = malloc(sizeof(*p));
    p->path = malloc(g->nvertices * sizeof(int));
    
    int *prev = malloc((g->nvertices + 1) * sizeof(int));
    int *d = malloc((g->nvertices + 1) * sizeof(int));
    
    ShortestPath_Dijekstra(g, src, d, prev);
    
    int i = dest;
    p->pathlen = 1;
    while (i != src) {
	p->pathlen = p->pathlen + 1;
	i = prev[i];
    }
    
    int j = 0;
    i = dest;
    
    while (i != src) {
	p->path[p->pathlen - j] = i;
	i = prev[i];
	j = j + 1;
    }
    
    free(prev);
    free(d);
    
    return p;
}

void ShortestPath_Dijekstra(struct graph *g, int src, int *d, int *prev)
{
    struct heap *prio_q;
    prio_q = heap_create(g->nvertices);
    
    int v;
    
    for (v = 1; v <= g->nvertices; v++) {
	if (v != src) {
	    g->visited[v] = 0;
	    d[v] = INT_MAX;
	    prev[v] = -1;
	    heap_insert(prio_q, d[v], v);
	}
    }
    
    d[src] = 0;
    prev[src] = -1;
    g->visited[src] = 0;
    heap_insert(prio_q, d[src], src);
    
    struct heapnode node;
    int tmp;
    for (v = 1; v <= g->nvertices; v++) {
	node = heap_extract_min(prio_q);
	tmp = node.value;
	g->visited[tmp] = 1;
	printf("vert %d\n\n", v);
	printf("min prio %d to vert %d\n", node.key, node.value);

	for (int u  = 1; u <= g->nvertices; u++) {
	    
	    int way = graph_get_edge(g, tmp, u);
	    if ((way != 0) && (g->visited[u] != 1)) {
		printf("sm ne pos vert %d\nway %d\n", u, way);
		if (d[tmp] + way < d[u]) {
		    d[u] = d[tmp] + way;
		    printf("path do %d = %d\n", u, d[u]);
		    heap_decrease_key(prio_q, u, d[u]);
		    prev[u] = tmp;
		}
	    }
	}
    }
}
