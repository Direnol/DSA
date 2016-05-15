#ifndef BINARY_HEAP_H
#define BINARY_HEAP_H

#include <stdlib.h>

struct heapnode {
    int key; /* Priority (key) */
    char *value; /* Data */
};

struct heap {
    int maxsize; /* Array size */
    int nnodes; /* Number of keys */
    struct heapnode *nodes; /* Nodes: [0..maxsize] */
};

struct heap *heap_create(int maxsize);
void heap_free(struct heap *h);
void heap_swap(struct heapnode *a, struct heapnode *b);
struct heapnode *heap_min(struct heap *h);
int heap_insert(struct heap *h, int key, char *value);
struct heapnode heap_extract_min(struct heap *h);
void heap_heapify(struct heap *h, int index);
int heap_increase_key(struct heap *h, int index, int key);


#endif
