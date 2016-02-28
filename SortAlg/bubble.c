#include "bubble.h"

void bubbleSort(int *array, int size)
{
    int i, temp;
    int flag = 1;
    
    while (flag) {
        flag = 0;
        for (i = 1; i < size; i++) {
            if (array[i] < array[i - 1]) {
                temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                flag = 1;
            }
        }
    }
}
