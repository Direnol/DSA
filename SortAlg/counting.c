#include "counting.h"

void countingSort(int *a, int n)
{
    int i, j, idx = 0;
    int min = a[0];
    int max = a[0];

    for (i = 1; i < n; i++) {
        if (a[i] < min)
            min = a[i];
        if (a[i] > max)
            max = a[i];
    }

    int k = max - min + 1;
    int b[k];
    for (i = 0; i < k; i++)
        b[i] = 0;

    for (i = 0; i < n; i++)
        b[a[i] - min]++;
    for (i = min; i <= max; i++)
        for (j = 0; j < b[i - min]; j++)
            a[idx++] = i;
}
