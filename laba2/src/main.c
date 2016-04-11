#include "bstree.h"
#include "hashtab.h"
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <time.h>

char *input(char *name, int *size);

int main(int argc, char *argv[]) 
{
    if (argc < 2) {
        fprintf(stderr, "Missing table size!\n");
        return EXIT_FAILURE;
    }
    
    FILE *out1 = fopen("dataex1.dat", "a");
    if (out1 == NULL) {
        fprintf(stderr, "Cant create \"dataex1.dat\" file!\n");
        return EXIT_FAILURE;
    }
    
    FILE *out2 = fopen("dataex2.dat", "a");
    if (out2 == NULL) {
        fprintf(stderr, "Cant create \"dataex2.dat\" file!\n");
        return EXIT_FAILURE;
    }
    
    FILE *dictionary = fopen("../task/dictionary.dat", "r");
    if (dictionary == NULL) {
        fprintf(stderr, "Can't open data file...\n");
        return EXIT_FAILURE;
    }

    int size = atoi(argv[1]);
    int i;
    
    hashtab_init(hashtab);
    BSTree *tree = NULL;
    char *words[size];
    
    for (i = 0; i < size; i++) {
		fscanf(dictionary, "%s\n", words[i]);
		bstree_add(tree, words[i], i);
		hashtab_add(hashtab, words[i], i);
	}
	
	srand(time(NULL));
    int rand_node = rand() % size;
    char rand_data = words[rand_node];
    char *add_node = "САОД";
    double time;
    
    

    /* Task 1 */
    BSTree *lkt = NULL;
    time = wtime();
    lkt = bstree_lookup(tree, rand_data);
    time = wtime() - time;
    fprintf(out1, "%d\t%.8f", size, time);
    printf("%s %d\n", lkt->data.name, lkt->data.value);
    
    listnode *lkh = NULL;
    time = wtime();
    lkh = hashtab_lookup(hashtab, rand_data);
    time = wtime() - time;
    fprintf(out1, "\t%.8f\n", time);
    printf("%s %d\n", lkh->key, lkh->value);
    
     /* Task 2 */
    time = wtime();
    bstree_add(tree, add_node, size + 1);
    time = wtime() - time;
    fprintf(out2, "%d\t%.8f", size, time);
    
    time = wtime();
    hashtab_add(hashtab, add_node, size + 1);
    time = wtime() - time;
    fprintf(out2, "\t%.8f\n", time);
    
    fclose(out1);
    fclose(out2);
    fclose(dictionary);
    
    return 0;

}
