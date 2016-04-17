#include "hashtab.h"

unsigned int jenkins_hash(char *key, int len) 
{
	unsigned int hash, i = 0;
	for (hash = i; i < len; ++i) {
        hash += key[i];
        hash += (hash << 10);
        hash ^= (hash >> 6);
    }
        hash += (hash << 3);
        hash ^= (hash >> 11);
        hash += (hash << 15);
	return hash % HASHTAB_SIZE;
}

unsigned int hashtab_hash(char *key)
{
	unsigned int h = 0;
	char *p;
    
	for (p = key; *p != '\0'; p++) {
		h = h * HASHTAB_MUL + (unsigned int) * p;
	}
    
	return h % HASHTAB_SIZE;
}

void hashtab_init(struct listnode **hashtab)
{
	int i;
	for (i = 0; i < HASHTAB_SIZE; i++) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(struct listnode **hashtab, char *key, int value, int f_hash)
{
	struct listnode *node;
	int index;
	if (f_hash == 0) {
		index = hashtab_hash(key);
	}
	else {
		index = jenkins_hash(key, strlen(key) );
	}
	// Вставка в начало списка
	node = malloc(sizeof(*node));
	if (node != NULL) {
		node->key = key;
		node->value = value;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
}

struct listnode *hashtab_lookup(struct listnode **hashtab, char *key, int f_hash)
{
	int index;
	struct listnode *node;
	
	if (f_hash == 0) {
		index = hashtab_hash(key);
	}
	else {
		index =jenkins_hash(key, strlen(key) );
	} 
	for (node = hashtab[index]; node != NULL; node = node->next) {
		if (strcmp(node->key, key) == 0)
			return node;
	}
	return NULL;
}

void hashtab_delete(struct listnode **hashtab, char *key, int f_hash)
{
	int index;
	struct listnode *p, *prev = NULL;
	if (f_hash == 0) {
		index = hashtab_hash(key);
	}
	else {
		index = jenkins_hash(key, strlen(key)); 
	}
	for (p = hashtab[index]; p != NULL; p = p->next) {
		if (strcmp(p->key, key) == 0) {
			if (prev == NULL)
				hashtab[index] = p->next;
			else
				prev->next = p->next;
			free(p);
			return;
		}
		prev = p;
	}
}
