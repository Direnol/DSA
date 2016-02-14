# Задание 1. Алгоритмы сортировки

## Описание алгоритмов
| Counting Sort <br>(Сортировка подсчётом) | Bubble Sort <br>(Сортировка пузырьком) | Merge Sort <br>(Сортировка слиянием) |
| :---: | :---: | :---: |
| [Wiki](https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0_%D0%BF%D0%BE%D0%B4%D1%81%D1%87%D1%91%D1%82%D0%BE%D0%BC) \| [Rosetta](http://rosettacode.org/wiki/Sorting_algorithms/Counting_sort#C) \| [GS](http://www.geeksforgeeks.org/counting-sort/) | [Wiki](https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0_%D0%BF%D1%83%D0%B7%D1%8B%D1%80%D1%8C%D0%BA%D0%BE%D0%BC) \| [Rosetta](http://rosettacode.org/wiki/Sorting_algorithms/Bubble_sort#C) \| [GS](http://geeksquiz.com/bubble-sort/) | [Wiki](https://ru.wikipedia.org/wiki/%D0%A1%D0%BE%D1%80%D1%82%D0%B8%D1%80%D0%BE%D0%B2%D0%BA%D0%B0_%D1%81%D0%BB%D0%B8%D1%8F%D0%BD%D0%B8%D0%B5%D0%BC) \| [Rosetta](http://rosettacode.org/wiki/Sorting_algorithms/Merge_sort#C) \| [GS](http://geeksquiz.com/merge-sort/) |

## Организация экспериментов
* CPU: Intel Core i5 2.3GHz
* RAM: 8Gb DDR3
* OS: OS X 10.11
* GCC: 4.2.3

## Полезности

#### Генерация псевдослучайных чисел
```c
#include <stdlib.h>
#include <stdio.h>

/* getrand: Returns random number from [min, max) */
int getrand(int min, int max)
{
    return (double)rand() / (RAND_MAX + 1.0) * (max - min) + min;
}

int main()
{
    int r = getrand(1, 1001); // Псевдослучайное число 1 <= r <= 1000

    return 0;
}
```
#### Измерение времени выполнения кода
```c
#include <sys/time.h>
#include <stdio.h>

double wtime()
{
    struct timeval t;
    gettimeofday(&t, NULL);
    return (double)t.tv_sec + (double)t.tv_usec * 1E-6;
}

int main()
{
    double t;

    t = wtime();
    /* Code */
    t = wtime() - t;

    printf("Elapsed time: %.6f sec.\n", t);  
    return 0;
}
```
