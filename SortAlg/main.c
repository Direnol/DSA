#include "util.h"

int main(int argc, char * argv[])
{
    if(argc < 2)
    {
        printf("Missing array size!");
        return EXIT_FAILURE;
    }

    int array_size = atoi(argv[1]);
    int * array = (int *)malloc(sizeof(int)*array_size);
    for(int i=0; i < array_size; i++)
	array[i] = getrand(1, 100001);


    free(array);

    return EXIT_SUCCESS;
}
