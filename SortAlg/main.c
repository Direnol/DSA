#include "util.h"
#include "merge.h"
#include "bubble.h"
#include "counting.h"

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Missing array size!\n");
        return EXIT_FAILURE;
    }

    FILE *ptr_file = fopen("data.dat", "a");
    if (ptr_file == NULL) {
        printf("Cant create data file!\n");
        return EXIT_FAILURE;
    }

    int array_size = atoi(argv[1]);
    int *array = (int *) malloc(sizeof(int) * array_size);
    for (int i = 0; i < array_size; i++)
        array[i] = getrand(1, 100001);

    int *array_counting = (int *) malloc(sizeof(int) * array_size);
    memcpy(array_counting, array, sizeof(int) * array_size);
    int *array_bubble = (int *) malloc(sizeof(int) * array_size);
    memcpy(array_bubble, array, sizeof(int) * array_size);
    int *array_merge = (int *) malloc(sizeof(int) * array_size);
    memcpy(array_merge, array, sizeof(int) * array_size);

    double time;

    time = wtime();
    countingSort(array_counting, array_size);
    fprintf(ptr_file, "%d\t%.6f", array_size, wtime() - time);

    time = wtime();
    bubbleSort(array_bubble, array_size);
    fprintf(ptr_file, "\t%.6f", wtime() - time);

    time = wtime();
    mergeSort(array_merge, array_size);
    fprintf(ptr_file, "\t%.6f\n", wtime() - time);

    free(array);
    free(array_counting);
    free(array_bubble);
    free(array_merge);
    fclose(ptr_file);
    return EXIT_SUCCESS;
}
