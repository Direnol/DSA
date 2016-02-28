#include "counting.h"

void countingSort(int *array, int size)
{
    int i, j, idx = 0;
    int min = array[0];
    int max = array[0];

    for (i = 1; i < size; i++) {
        if (array[i] < min)
            min = array[i];
        if (array[i] > max)
            max = array[i];
    }

    int size_t_array = max - min + 1;
    int t_array[size_t_array];
    for (i = 0; i < size_t_array; i++)
        t_array[i] = 0;

    for (i = 0; i < size; i++)
        t_array[array[i] - min]++;
        
    for (i = min; i <= max; i++)
        for (j = 0; j < t_array[i - min]; j++)
            array[idx++] = i;
}
