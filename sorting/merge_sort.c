#include "sorting.h"

// https://www.youtube.com/watch?v=LeWuki7AQLo

void _merge_sort(int array[], int left, int right);
void _merge(int array[], int left, int mid, int right);

void merge_sort(int array[], int length) {
    _merge_sort(array, 0, length - 1);
}

void _merge_sort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        _merge_sort(array, left, mid);
        _merge_sort(array, mid + 1, right);

        _merge(array, left, mid, right);
    }
}

void _merge(int array[], int left, int mid, int right) {
    int left_length = mid - left + 1;
    int right_length = right - mid;

    int temp_left[left_length];
    int temp_right[right_length];

    int i, j, k;

    for (i = 0; i < left_length; i++)
        temp_left[i] = array[left + i];
    
    for (i = 0; i < right_length; i++)
        temp_right[i] = array[mid + 1 + i];
    
    for (i = 0, j = 0, k = left; k <= right; k++) {
        if ((i < left_length) &&
            (j >= right_length || temp_left[i] <= temp_right[j])) {
                array[k] = temp_left[i];
                i++;
            } else {
                array[k] = temp_right[j];
                j++;
            }
    }
}
