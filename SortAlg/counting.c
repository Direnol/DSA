#include "counting.h"

void countingSort(int *array, int size)
{
    int i;
    int min = array[0];
    int max = array[0];

    for (i = 1; i < size; i++) {
        if (array[i] < min)
            min = array[i];
        if (array[i] > max)
            max = array[i];
    }

    int range = max - min + 1;

    int *counter_array = (int *) malloc(sizeof(int) * (range + 1));
    int *temp_array = (int *) malloc(sizeof(int) * size);

    for (i = 0; i < range + 1; i++)
        counter_array[i] = 0;

    for (i = 0; i < size; i++) {
        int c = array[i] + 1 - min;
        counter_array[c]++;
    }

    for (i = 1; i < range; i++)
        counter_array[i] += counter_array[i - 1];

    for (i = (size - 1); i >= 0; i--) {
        int c = array[i] - min;
        int s = counter_array[c];
        temp_array[s] = array[i];
        counter_array[c]++;
    }

    for (i = 0; i < size; i++)
        array[i] = temp_array[i];

    free(counter_array);
    free(temp_array);
}
