#include "hashtab.h"
#include <stdlib.h>
#include <string.h>

int hashtab_hash(char *key)
{
	unsigned int h = 0;
	char *p;
	
	for (p = key; *p != '\0'; p++) {
		h = h * HASH_MUL + (unsigned int)*p;
	}
	
	return h % HASH_SIZE;
}

int jenkins_hash(char *key, int len)
{
	unsigned int hash, i; 
		
	for (hash = i = 0; i < len; ++i) { 
		hash += key[i]; 
		hash += (hash << 10); 
		hash ^= (hash >> 6); 
	} 
	
		hash += (hash << 3); 
		hash ^= (hash >> 11); 
		hash += (hash << 15); 
	return hash % HASH_SIZE; 
} 

void hashtab_init(listnode **hashtab)
{
	int i;
	for (i = 0; i < HASH_SIZE; i++) {
		hashtab[i] = NULL;
	}
}

void hashtab_add(listnode **hashtab, char *key, int value)
{
	listnode *node;
	
	int index = hashtab_hash(key);
	
	node = malloc(sizeof(*node));
	if (node != NULL) {
		node->key = key;
		node->value = value;
		node->next = hashtab[index];
		hashtab[index] = node;
	}
}

listnode *hashtab_lookup(listnode **hashtab, char *key)
{
	int index = hashtab_hash(key);
	listnode *node;
	
	for (node = hashtab[index]; node != NULL; node = node->next) {
		if (strcmp(node->key, key) == 0) {
			return node;
		}
	}
	
	return NULL;
}

void hashtab_delete(listnode **hashtab, char *key)
{
	int index = hashtab_hash(key);
	listnode *p, *prev = NULL;
	
	for (p = hashtab[index]; p != NULL; p = p->next) {
		if (strcmp(p->key, key) == 0) {
			if (prev == NULL)
				hashtab[index] = p->next;
			else
				prev->next = p->next;
			free(p);
			return;
		}
	}
		prev = p;
}

