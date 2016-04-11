#include "bstree.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

/* Create tree */
BSTree *bstree_create(char *name, int value)
{
	
	BSTree *tr;
<<<<<<< HEAD
	tr = malloc(sizeof(BSTree));
=======
	tr = malloc(sizeof(*tr));
>>>>>>> 655ac7fb1f0ec3a01f19fbc99b9b1f887aab074b
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
<<<<<<< HEAD
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
	
	/* Add new node */
	cmp = strcmp(name, parent->data.name);
	
	if (cmp < 0)
		parent->left = tr;
	else
		parent->right = tr;
	
	return tree;
=======
	BSTree *tr, *root;
	tr = bstree_create(name, value);
	root = tree;
	
	/* if the node already exsist */
	if (cmp == 0) {
		tree->data.value = value;
		return tree;
	} else if (cmp < 0) {
		tree->left = bstree_add(tree->left, name, value);
	} else {
		tree->right = bstree_add(tree->right, name, value);
	}
	return root;
>>>>>>> 655ac7fb1f0ec3a01f19fbc99b9b1f887aab074b
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
		
<<<<<<< HEAD
    while (tree->left != NULL)
		tree = tree->left;
=======
    while (tree->left != NULL) {
		tree = tree->left;
	}
>>>>>>> 655ac7fb1f0ec3a01f19fbc99b9b1f887aab074b
	return tree;
}

BSTree *bstree_max(BSTree *tree)
<<<<<<< HEAD
{
	if (tree == NULL)
		return NULL;
		
    while (tree->right != NULL)
		tree = tree->right;
	return tree;   
=======
{	
	if (tree == NULL)
		return NULL;
		
    while (tree->left != NULL) {
		tree = tree->right;
	}
	return tree;
>>>>>>> 655ac7fb1f0ec3a01f19fbc99b9b1f887aab074b
}
