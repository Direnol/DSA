#include "util.h"
#include "merge.h"
#include "bubble.h"
#include "counting.h"

int main(int argc, char * argv[])
{
    if (argc < 2) {
        printf("Missing array size!\n");
        return EXIT_FAILURE;
    }

    int array_size = atoi(argv[1]);
    int * array = (int *)malloc(sizeof(int)*array_size);
    for (int i=0; i < array_size; i++)
		array[i] = getrand(1, 10001);

	double time = wtime();
	
	countingSort(array, array_size);
	
	for (int i=0; i < array_size; i++)
	{
        printf("%d ", array[i]);
	}

	printf("Time: %d\n", (int)(wtime() - time));

    free(array);

    return EXIT_SUCCESS;
}
