#include "bstree.h"
#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include <time.h>

char *input(char *name, int *size);

int main() 
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
    
    FILE *dictionary = fopen("task/dictionary.dat", "r");
    if (dictionary == NULL) {
        fprintf(stderr, "Can't open data file...\n");
        return EXIT_FAILURE;
    }

    int size = atoi(argv[1]);
    
    srand(time(NULL));
    int rand_node = rand() % size;

    double time;
    
    hashtab_init(hashtab);
    BSTree *tree = NULL;

    /* Task 1 */
    BSTree *lkt = NULL;
    time = wtime();
    lkt = bstree_lookup(tree, rand_data);
    time = wtime() - time;
    fprintf(outex1, "%d\t%.8f", table_size, time);
    printf("%s %d\n", lkt->data.key, lkt->data.value);
    
    ListNode *lks = NULL;
    time = wtime();
    lks = hashtab_lookup(hashtab, rand_data);
    time = wtime() - time;
    fprintf(outex1, "\t%.8f\n", time);
    printf("%s %d\n", lks->data.key, lks->data.value);
    
     /* Task 2 */
    time = wtime();
    bstree_add(tree, test, table_size + 1);
    time = wtime() - time;
    fprintf(outex2, "%d\t%.8f", table_size, time);
    
    time = wtime();
    hashtab_add(hashtab, test, table_size + 1);
    time = wtime() - time;
    fprintf(outex2, "\t%.8f\n", time);
    
    fclose(outex1);
    fclose(outex2);
    fclose(dictionary);
    return 0;

}
