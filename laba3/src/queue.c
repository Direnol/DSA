#include "queue.h"

struct queue *queue_create()
{
    struct queue *q = malloc(sizeof(*q));
    if (q != NULL) {
	q->size = 0;
	q->head = NULL;
	q->tail = NULL;
    }
    return q;
}

void queue_free(struct queue *q)
{
    while (q->size > 0)
	queue_dequeue(q);
    free(q);
}

int queue_size(struct queue *q)
{
    return q->size;
}

void queue_enqueue(struct queue *q, int value)
{
    struct listnode *oldtail = q->tail;
    
    /* Create new node */
    q->tail = list_createnode(value);
    
    if (q->head == NULL) {
	/* List is empty */
	q->head = q->tail;
    } else {
	/* Add new node to the end of list */
	oldtail->next = q->tail;
    }
    q->size++;
}

int queue_dequeue(struct queue *q)
{
    int value;
    struct listnode *p;
    
    if (q->size == 0)
	return -1;
    
    /* Delete first node */
    value = q->head->value;
    p = q->head->next;
    free(q->head);
    q->head = p;
    q->size--;
    return value;
}

