#include "bstree.h"
#include <string.h>

/* Create tree */
BSTree *bstree_create(char *name, int value)
{
	
	BSTree *tr;
	tr = malloc(sizeof(BSTree));
	if (tr == NULL) {
		return tr;
	}
	
	tr->Data.name = name;
	tr->Data.value = value;
	tr->left = NULL;
	tr->right = NULL;
	
	return tr;	
}

/* Add new element(name, value) in tree */
BSTree *bstree_add(BSTree *tree, char *name, int value)
{	
	/*if the node is empty, then create the node */
	if (tree == NULL) {
		tree = bstree_create(name, value);
		return tree;
	}
	
	int cmp = strcmp(name, tree->Data.name);
	BSTree *tr;
	tr = bstree_create(name, value);
	
	/* if the node already exsist */
	if (cmp == 0) {
		tree->Data.value = value;
		return tree;
	} else if (cmp < 0) {
		tree->left = bstree_add(tree->left, name, value);
	} else {
		tree->right = bstree_add(tree->right, name, value);
	}
	return tree;
}

/* Lookup *name in tree */
BSTree *bstree_lookup(BSTree *tree, char *name)
{
	/* if tree is empty */
	if (tree == NULL) {
		return NULL;
	}
	
    int cmp = strcmp(name, tree->Data.name);
   
	if (cmp == 0) {
		return tree;
	} else if (cmp < 0) {
		return bstree_lookup(tree->left, name);
	} else {
		return bstree_lookup(tree->right, name);
	}
}

BSTree *bstree_min(BSTree *tree)
{
    
}

BSTree *bstree_max(BSTree *tree)
{
    
}
