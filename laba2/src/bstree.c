#include "bstree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Create tree */
BSTree *bstree_create(char *name, int value)
{
	
	BSTree *tr;

	tr = malloc(sizeof(*tr));
	if (tr == NULL) {
		return tr;
	}
	
	tr->data.name = name;
	tr->data.value = value;
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
	
	int cmp = strcmp(name, tree->data.name);
	BSTree *tr, *parent;
	tr = bstree_create(name, value);
	for (parent = tree; tree != NULL;) {
		parent = tree;
		if (cmp < 0)
			tree = tree->left;
		else if (cmp > 0)
			tree = tree->right;
		else 
			return tree;
	}
}

/* Lookup *name in tree */
BSTree *bstree_lookup(BSTree *tree, char *name)
{
	/* if tree is empty */
	if (tree == NULL) {
		return NULL;
	}
	
    int cmp = strcmp(name, tree->data.name);
   
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
	if (tree == NULL)
		return NULL;

    while (tree->left != NULL)
		tree = tree->left;
	return tree;
}

BSTree *bstree_max(BSTree *tree)
{
	if (tree == NULL)
		return NULL;
		
    while (tree->right != NULL)
		tree = tree->right;
	return tree;   
}
