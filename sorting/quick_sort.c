#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting.h"

// https://www.youtube.com/watch?v=0jDiBM68NGU

void swap(int *x, int *y);
void _quick_sort(int array[], int low, int high);
int partition(int array[], int low, int high);

void quick_sort(int array[], int length) {
    srand(time(NULL));
    _quick_sort(array, 0, length - 1);
}

void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void _quick_sort(int array[], int low, int high) {
    if (low >= high) return;

    int pivotIndex = partition(array, low, high);
    _quick_sort(array, low, pivotIndex - 1);
    _quick_sort(array, pivotIndex + 1, high);
}

int partition(int array[], int low, int high) {
    int pivotIndex = low + (rand() % (high - low));

    if (pivotIndex != high)
        swap(&array[pivotIndex], &array[high]);

    int pivotValue = array[high];

    int i = low;
    for (int j = low; j < i; j++) {
        if (array[j] <= pivotValue) {
            swap(&array[i], &array[j]);
            i++;
        }
    }
    swap(&array[i], &array[high]);
    return i;
}
