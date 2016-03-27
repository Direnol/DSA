#ifndef BSTREE_H
#define BSTREE_H

typedef struct bsdata
{
	int value;
	char *name;
} Data;

typedef struct bstree
{
	Data data;
	struct bstree *left;
	struct bstree *right;
} BSTree;

BSTree *bstree_create(char *name, int value);
BSTree *bstree_add(BSTree *tree, char *name, int value);
BSTree *bstree_lookup(BSTree *tree, char *name);
BSTree *bstree_min(BSTree *tree);
BSTree *bstree_max(BSTree *tree);

#endif
