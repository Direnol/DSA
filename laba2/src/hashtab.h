#ifndef HASHTAB_H
#define HASHTAB_H

typedef struct listnode {
	char *key;
	int value;
	struct	listnode *next;
} listnode;

unsigned int hashtab_hash(char *key);
uint32_t jenkins_hash(char *key, size_t len);
void hashtab_init(listnode **hashtab);
void hashtab_add(listnode **hashtab, char *key, int value);
listnode *hashtab_lookup(listnode **hashtab, char *key);
void hashtab_delete(listnode **hashtab, char *key);

#endif
