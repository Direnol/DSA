#include "merge.h"

void merge(int *array, int *left_array, int left_count, int *right_array, int right_count)
{
    int i, j, k = 0;

    while (i < left_count && j < right_count) {
        if (left_array[i] < right_array[j])
            array[k++] = left_array[i++];
        else
            array[k++] = right_array[j++];
    }

    while (i < left_count)
        array[k++] = left_array[i++];
    while (j < right_count)
        array[k++] = right_array[j++];
}

void mergeSort(int *array, int size)
{
    int mid, i, *left_array, *right_array;

    if (size < 2)
        return;

    mid = size / 2;

    left_array = (int *) malloc(mid * sizeof(int));
    right_array = (int *) malloc((size - mid) * sizeof(int));

    for (i = 0; i < mid; i++)
        left_array[i] = array[i];
    for (i = mid; i < size; i++)
        right_array[i - mid] = array[i];

    mergeSort(left_array, mid);
    mergeSort(right_array, size - mid);
    merge(array, left_array, mid, right_array, size - mid);

    free(left_array);
    free(right_array);
}
