#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <sys/time.h>

void countingsort (uint32_t *mass, int size);
void quicksort (uint32_t *mas, int first, int last);
void bubblesort (uint32_t mass[], int size);
int getrand (int min, int max);
double wtime();

int main (int argc, char * argv[])
{
    int i;
    double t;
    FILE * ptr;

    if (argc < 2){
        printf ("Missing array size!");
        return EXIT_FAILURE;
    }

    if (argc < 3){
        printf ("Not number sort!");
        return EXIT_FAILURE;
    }

    int array_size = atoi(argv[1]), s = atoi(argv[2]);

    if ((s != 1) && (s != 2) && (s !=3 )){
        printf ("No correct number sort!");
        return EXIT_FAILURE;
    }

    uint32_t * array = malloc(sizeof(uint32_t) * array_size);

    if (array == NULL){
        printf ("Error of memory allocation!\n");
        return EXIT_FAILURE;
    }

    for(i = 0; i < array_size; i++){
        array[i] = getrand(1, 100001);
        //printf("array[%d] = %d\n",i,array[i]);
    }

    if (s == 1){
        t = wtime();
        quicksort(array,0,array_size-1);
        t = wtime() - t;
        ptr = fopen("qsort.dat","a");
    } else if (s == 2){
        t = wtime();
        bubblesort(array,array_size);
        t = wtime() - t;
        ptr = fopen("bsort.dat","a");
    } else if (s == 3){
        t = wtime();
        countingsort(array,array_size);
        t = wtime()- t;
        ptr = fopen("csort.dat","a");
    }

    fprintf (ptr, "%d\t%.6f\n", array_size, t);
    fclose (ptr);

    /*for (i = 0; i < array_size; i++)
        printf("a[%d] = %d\n",i,array[i]);*/

    free(array);
    return EXIT_SUCCESS;
}


void countingsort(uint32_t *A, int n)
{
    int i, min = A[0], max = A[0];

    for (i = 1; i < n; i++){
        if (A[i] < min)
            min = A[i];
        else
        if (A[i] > max)
            max = A[i];
    }

    uint32_t *C = (uint32_t*)malloc(sizeof(uint32_t)*(max-min+1));
    uint32_t *B = (uint32_t*)malloc(sizeof(uint32_t)*n);

    for (i = 0; i < (max-min+1); i++)
        C[i] = 0;

    for (i = 0; i<n; i++)
        C[ A[i]-min ]++;

    for (i = 1; i < (max-min+1); i++)
        C[i] += C[i-1];

    for (i = 0; i < n; i++)
        B[ C[ A[i]-min ]-- -1 ] = A[i];

    for (i = 0; i < n; i++)
        A[i] = B[i];

    free (B);
    free (C);
}
void quicksort(uint32_t *mas, int first, int last)
{
    int mid, count;
    int f = first, l = last;
    mid = mas[(f+l) / 2]; //вычисление опорного элемента
    do
    {
        while (mas[f] < mid)
            f++;
        while (mas[l] > mid)
            l--;
        if (f <= l){ //перестановка элементов
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    } while (f < l);
    if (first < l)
        quicksort(mas, first, l);
    if (f < last)
        quicksort(mas, f, last);
}

void bubblesort(uint32_t arr[], int size)
{
    int tmp, i, j;

    for(i = 0; i < size - 1; ++i) // i - номер прохода
    {
        for(j = 0; j < size - 1; ++j) // внутренний цикл прохода
        {
            if (arr[j + 1] < arr[j])
            {
                tmp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}
