<<<<<<< HEAD
#include <stdio.h>
#include "bstree.h"
#include "hashtab.h"

#define MAX_WORD 33

int main()
{
	BSTree *tree = NULL, *look_node = NULL;
	listnode *hashtab[HASH_SIZE];
	
	hashtab_init(hashtab);
	
	FILE *ptr;
	ptr = fopen("../task/wap.txt", "r");
	
	char buf[MAX_WORD];
	
	while (!feof(ptr)) {
		buf = fscanf(ptr, "%s\n", buf);
	}
	
	return 0;
}
=======
#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>

char *input(char *name, int *size);

int main() 
{
	BSTree *tree, *look;
	char *name;
	int n;
	
	name = input(name, &n);
	tree = bstree_create(name, n);
	printf("Name = %s, value = %d\n", tree->data.name, tree->data.value);
	
	name = input(name, &n);
	bstree_add(tree, name, n);
	printf("Name = %s, value = %d\n", tree->right->data.name, tree->right->data.value);
	
	name = input(name, &n);
	bstree_add(tree, name, n);
	printf("Name = %s, value = %d\n", tree->right->right->data.name, tree->right->right->data.value);
	
	printf("Input key\n");
	name = input(name, &n);
	look = bstree_lookup(tree, name);
	printf("Founded: name = %s, value = %d\n",look->data.name, look->data.value);
	return 0;
}

char *input(char *name, int *size)
{
	printf("Enter size of string\n");
	scanf("%d%*c", size);
	name = malloc(*size * sizeof(char));
	printf("Input the string\n");
	fgets(name, *size, stdin);
	return name;
}
>>>>>>> 655ac7fb1f0ec3a01f19fbc99b9b1f887aab074b
