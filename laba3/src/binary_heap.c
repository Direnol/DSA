#include "binary_heap.h"

struct heap *heap_create(int maxsize)
{
    struct heap *h;
    h = malloc(sizeof(*h));
    if (h != NULL) {
	h->maxsize = maxsize;
	h->nnodes = 0;
	/* Heap nodes [0, 1, ..., maxsize] */
	h->Vtoidx = calloc(maxsize + 1, sizeof(int));
	h->nodes = malloc(sizeof(*h->nodes) * (maxsize + 1));
	if (h->nodes == NULL) {
	    free(h);
	    return NULL;
	}
    }
    return h;
}

void heap_free(struct heap *h)
{
    free(h->nodes);
    free(h);
}

void heap_swap(struct heap *h, int idx_a, int idx_b)
{
    struct heapnode temp, *a, *b;
    a = &h->nodes[idx_a];
    b = &h->nodes[idx_b];
    int tmp = h->Vtoidx[a->value];
    h->Vtoidx[a->value] = h->Vtoidx[b->value];
    h->Vtoidx[b->value] = tmp;
    temp = *a;
    *a = *b;
    *b = temp;
}

struct heapnode *heap_min(struct heap *h)
{
    if (h->nnodes == 0)
	return NULL;
    return &h->nodes[1];
}

int heap_insert(struct heap *h, int key, int value)
{
    if (h->nnodes >= h->maxsize) {
	/* Heap overflow */
	return -1;
    }
    h->nnodes++;
    h->nodes[h->nnodes].key = key;
    h->nodes[h->nnodes].value = value;
    h->Vtoidx[value] = h->nnodes;
    // HeapifyUp
    int i;
    for (i = h->nnodes; i > 1 && h->nodes[i].key < h->nodes[i / 2].key; i = i / 2) {
	heap_swap(h, i, i / 2);
	h->Vtoidx[value] = i / 2;
    }
    return 0;
}

struct heapnode heap_extract_min(struct heap *h)
{
    if (h->nnodes == 0)
	return (struct heapnode){0, NULL};
    struct heapnode minnode = h->nodes[1];
    h->nodes[1] = h->nodes[h->nnodes];
    h->Vtoidx[h->nodes[1].value] = 1;
    h->nnodes--;
    heap_heapify(h, 1);
    return minnode;
}

void heap_heapify(struct heap *h, int index)
{
    for (;;) {
	int left = 2 * index;
	int right = 2 * index + 1;
	// Find largest key: A[index], A[left] and A[right]
	int largest = index;
	if (left <= h->nnodes && h->nodes[largest].key > h->nodes[left].key) {
	    largest = left;
	}
	if (right <= h->nnodes && h->nodes[largest].key > h->nodes[right].key) {
	    largest = right;
	}
	if (largest == index)
	    break;
	heap_swap(h, index, largest);
	index = largest;
    }
}

int heap_decrease_key(struct heap *h, int value, int key)
{
    int index = h->Vtoidx[value];
    if (h->nodes[index].key < key)
	return -1;
    h->nodes[index].key = key;
    for ( ; index > 1 && h->nodes[index].key < h->nodes[index / 2].key; index = index / 2) {
	heap_swap(h, index, index / 2);
    }
    h->Vtoidx[value] = index;
    return 0;
}
