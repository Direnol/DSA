#ifndef HASHTAB_H
#define HASHTAB_H

#define HASH_MUL 31
#define HASH_SIZE 127

typedef struct listnode {
	char *key;
	int value;
	struct	listnode *next;
} listnode;

listnode *hashtab[HASH_SIZE];

int hashtab_hash(char *key);
int jenkins_hash(char *key, int len);
void hashtab_init(listnode **hashtab);
void hashtab_add(listnode **hashtab, char *key, int value);
listnode *hashtab_lookup(listnode **hashtab, char *key);
void hashtab_delete(listnode **hashtab, char *key);

#endif
