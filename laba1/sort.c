#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

void CountingSort(int *array, int size);
void QuickSort(uint32_t * mas, int first, int last);
void BubbleSort(uint32_t mass[], int size);
int getrand(int min, int max);
double wtime();

int main(int argc, char *argv[])
{
    int i;
    double t;
    FILE *ptr;

    if (argc < 2) {
        printf("Missing array size!");
        return EXIT_FAILURE;
    }

    if (argc < 3) {
        printf("Not number sort!");
        return EXIT_FAILURE;
    }

    int array_size = atoi(argv[1]);
    int s = atoi(argv[2]);

    if ((s != 1) && (s != 2) && (s != 3)) {
        printf("No correct number sort!");
        return EXIT_FAILURE;
    }

    uint32_t *array = malloc(sizeof(uint32_t) * array_size);

    if (array == NULL) {
        printf("Error of memory allocation!\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < array_size; i++) {
        array[i] = getrand(1, 100001);
        // printf("array[%d] = %d\n", i, array[i]);
    }

    if (s == 1) {
        t = wtime();
        QuickSort(array, 0, array_size - 1);
        t = wtime() - t;
        ptr = fopen("qsort.dat", "a");
    } else if (s == 2) {
        t = wtime();
        BubbleSort(array, array_size);
        t = wtime() - t;
        ptr = fopen("bsort.dat", "a");
    } else if (s == 3) {
        t = wtime();
        CountingSort(array, array_size);
        t = wtime() - t;
        ptr = fopen("csort.dat", "a");
    }

    fprintf(ptr, "%d\t%.6f\n", array_size, t);
    fclose(ptr);

    /* for (i = 0; i < array_size; i++)
       printf("a[%d] = %d\n", i, array[i]); */

    free(array);
    return EXIT_SUCCESS;
}


void CountingSort(int *array, int size)
{
    int i;
    int max = array[0];

    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
    }

    int K = max;

    int *C = (int *) malloc(sizeof(int) * (K + 1));
    int *B = (int *) malloc(sizeof(int) * size);

    for (i = 0; i <= K; i++)
        C[i] = 0;

    for (i = 0; i < size; i++) {
        C[array[i]]++;
    }

    for (i = 1; i <= K; i++)
        C[i] += C[i - 1];

    for (i = (size - 1); i >= 0; i--) {
        C[array[i]]--;
        B[C[array[i]]] = array[i];
    }

    for (i = 0; i < size; i++)
        array[i] = B[i];

    free(C);
    free(B);
}

void QuickSort(uint32_t * mas, int first, int last)
{
    int mid, tmp;
    int f = first, l = last;
    mid = mas[(f + l) / 2];     // вычисление опорного элемента
    do {
        while (mas[f] < mid)
            f++;
        while (mas[l] > mid)
            l--;
        if (f <= l) {           // перестановка элементов
            tmp = mas[f];
            mas[f] = mas[l];
            mas[l] = tmp;
            f++;
            l--;
        }
    } while (f <= l);
    if (first < l)
        QuickSort(mas, first, l);
    if (f < last)
        QuickSort(mas, f, last);
}

void BubbleSort(uint32_t arr[], int size)
{
    int tmp, i, j;

    for (i = 0; i < size - 1; i++)      // i - номер прохода
    {
        for (j = 0; j < size - 1; j++)  // внутренний цикл прохода
        {
            if (arr[j] > arr[j + 1]) {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }
}

int getrand(int min, int max)
{
    return (double) rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double) t.tv_sec + (double) t.tv_usec * 1E-6;
}
