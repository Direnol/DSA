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
