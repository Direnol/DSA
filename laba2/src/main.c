#include <stdlib.h>
#include "bstree.h"
#include "hashtab.h"
#include <stdio.h>
#include <time.h>
#include "fanc.h"
#include <unistd.h> 

#define dictionary 570000
#define exp 100

int main(int argc, char **argv)
{
	
	if (argc < 2) {
		printf("Missing size!\n");
		return EXIT_FAILURE;
	}
	int size = atoi(argv[1]);
	
	FILE *input = fopen("task/dictionary.dat", "r");
	if (input == NULL) {
	    printf("Can't open dictionary file!\n");
	    return EXIT_FAILURE;
	}
	
	
	int i = 0;
	
	int str = dictionary;
	int str_size = 33;
	char **buf = (char **)malloc(str * sizeof(char *));
	if (buf != NULL) {
		for(i = 0; i < str; i++) {
			buf[i] = (char *)malloc(str_size * sizeof(char));
		}
	}
	else {
		printf("Can't create buffer!\n");
	}
	
	for (i = 0; i < dictionary; i++) {
		fscanf(input, "%s\n",buf[i]);
		//printf ("buf(%d): %s\n", i+1, buf[i]);
	}
	
	//построение дерева    
	struct bstree *tree ,*node;
	tree = bstree_create(buf[0],1);
	for (i = 2; i <= size; i++) {
		bstree_add(tree,buf[i-1],i);
	}
	
	//создание таблицы
	int hash_mode = 0;
	struct listnode *hash, *hash_node;
	hashtab_init(hashtab);
	for (i = 1; i <= size; i++) {
		hashtab_add(hashtab,buf[i-1],i,hash_mode);
	}
	
	int coliz = 0;
	for (i = 0; i < HASHTAB_SIZE; i++) {
	    if (hashtab[i] != NULL) {
            hash_node=hashtab[i];
		if (hash_node->next != NULL) {
		    //printf("hashtab %d %s\n",i, hash_node->key);
		    coliz += list_coliz(hash_node);
		}
	    }
	}
	printf ("coliz(KPHash) %d\n",coliz);
	
	int count;
	//test 1 lookup--
	double lookup_time_bstree = 0;
	double lookup_time_hashtab = 0;
	double time_exp;
	int rand_i;
	for (count = 1; count <= exp; count++) {
	    sleep(1);
	    printf("lookup exp № %d\n",count);
	    printf("size %d\n",size);
	    
	    srand(time(NULL));
	    rand_i = getrand(0,size);
	    printf ("rand_word: %s idx: %d\n",buf[rand_i], rand_i+1);	
	    
	    time_exp = wtime();
	    node = bstree_lookup(tree,buf[rand_i]);
	    time_exp = wtime() - time_exp;
	    
	    lookup_time_bstree = lookup_time_bstree + time_exp;
	    if (node != NULL) {
		printf ("BSTree: %s, %d %.8f\n",node->key,node->value, time_exp);
	    }
	    
	    time_exp = wtime();
	    hash = hashtab_lookup(hashtab,buf[rand_i],hash_mode);
	    time_exp = wtime() - time_exp;
	    
	    lookup_time_hashtab = lookup_time_hashtab + time_exp;
	    printf("HashTab (KPHash): %s, %d %.8f\n",hash->key, hash->value, time_exp);
	}
	
	lookup_time_bstree = lookup_time_bstree/exp;
	lookup_time_hashtab = lookup_time_hashtab/exp;
	
	FILE *tb1;
	tb1 = fopen("../test/bstree_lookup.dat", "a");
	fprintf(tb1, "%d %.8f\n", size, lookup_time_bstree);

	FILE *tb2;
	tb2 = fopen("../test/hashtab_lookup_KPHash.dat", "a");
	fprintf(tb2, "%d %.8f %d\n", size, lookup_time_hashtab, coliz);
	//--
	
	//test2 add--
	printf("add\n");
	double add_time_bstree = 0;
	double add_time_hashtab = 0;
	for (count = 1; count <= exp; count++) {
	    time_exp = wtime();
	    bstree_add(tree,buf[size+count],size+1+count);
	    time_exp = wtime() - time_exp;
	    add_time_bstree = add_time_bstree + time_exp;
	    printf("bstree_add %s %d\n",buf[size+count],size+1+count);
	    
	    time_exp = wtime();
	    hashtab_add(hashtab,buf[size+count],size+1+count,hash_mode);
	    time_exp = wtime() - time_exp;
	    add_time_hashtab = add_time_hashtab + time_exp;
	    printf("hashtab(KPHash)_add %s %d\n",buf[size+count],size+1+count);
	}
	add_time_bstree = add_time_bstree/exp;
	FILE *tb3;
	tb3 = fopen("../test/bstree_add.dat", "a");
	fprintf(tb3, "%d %.8f\n", size, add_time_bstree);
	printf ("BSTree: %s, %d %.8f\n",buf[size],size+1, add_time_bstree);	    

	add_time_hashtab = add_time_hashtab/exp;
	FILE *tb4;
	tb4 = fopen("../test/hashtab_add.dat", "a");
	fprintf(tb4, "%d %.8f\n", size, add_time_hashtab);
	printf("HashTab (KPHash): %s, %d %.8f\n",buf[size], size+1, add_time_hashtab);
	//--

	//test3 hash_mode lookup--
	printf("lookup\n");
	double lookup_time_hashtab_JENKINSHash = 0;
	hash_mode = 1;
	struct listnode *hash_tb;
	hashtab_init(hashtab);
	
	for (i = 1; i <= size; i++) {
		hashtab_add(hashtab,buf[i-1],i,hash_mode);
	}
	
	coliz = 0;
	for (i = 0; i < HASHTAB_SIZE; i++) {
	    if (hashtab[i] != NULL) {
		hash_node=hashtab[i];
		if (hash_node->next != NULL) {
		    //printf("hashtab %d %s\n",i, hash_node->key);
		    coliz += list_coliz(hash_node);
		}
	    }
	}
	printf ("coliz(JENKINSHash) %d\n",coliz);
	
	for (count = 1; count <= exp; count++) {
	    sleep(1);
	    printf("lookup exp № %d\n",count);
	    printf("size %d\n",size);
	    
	    srand(time(NULL));
	    rand_i = getrand(0,size);
	    printf ("rand_word: %s idx: %d\n",buf[rand_i], rand_i+1);
	    
	    time_exp = wtime();
	    hash_tb = hashtab_lookup(hashtab,buf[rand_i],hash_mode);
	    time_exp = wtime() - time_exp;
	    printf("HashTab (JENKINSHash): %s, %d %.8f\n",hash_tb->key, hash_tb->value, time_exp);
	    lookup_time_hashtab_JENKINSHash = lookup_time_hashtab_JENKINSHash + time_exp;
	}
	lookup_time_hashtab_JENKINSHash = lookup_time_hashtab_JENKINSHash/exp;
	
	FILE *tb5;
	tb5 = fopen("../test/hashtab_lookup_JENKINSash.dat", "a");
	fprintf(tb5, "%d %.8f %d\n", size, lookup_time_hashtab_JENKINSHash, coliz);
	//--
	return 0;
}
