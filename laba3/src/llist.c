#include "llist.h"

struct listnode *list_createnode(int value)
{
    struct listnode *p;
    p = malloc(sizeof(*p)); // Выделяем память
    if (p != NULL) {
	p->value = value;
	p->next = NULL;
    }
    return p;
}
