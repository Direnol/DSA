#ifndef HASHTAB_H
#define HASHTAB_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#define HASHTAB_SIZE 13027
#define HASHTAB_MUL 31

struct listnode {
	char *key;
	int value;
	struct listnode *next;
};
struct listnode *hashtab[HASHTAB_SIZE];

    unsigned int hashtab_hash(char *key);
    unsigned int jenkins_hash(char *key, int len);
    void hashtab_init(struct listnode **hashtab);
    void hashtab_add(struct listnode **hashtab, char *key, int value, int f_hash);
    struct listnode *hashtab_lookup(struct listnode **hashtab, char *key, int f_hash);
    void hashtab_delete(struct listnode **hashtab, char *key, int f_hash);
    int list_coliz(struct listnode *node);

#endif
