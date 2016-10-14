#ifndef PREFIX_TREE
#define PREFIX_TREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
struct trie {
	char *value;
	char ch;
	struct trie *sibling;
	struct trie *child;
};

struct trie *trie_create();
char *trie_lookup(struct trie *root, char *key);
struct trie *trie_insert(struct trie *root, char *key, char *value);
struct trie *trie_delete(struct trie *root, char *key);
struct trie *trie_delete_dfs(struct trie *root, struct trie *parent, char *key, int *found);
void trie_print(struct trie *root, int level);

#endif
