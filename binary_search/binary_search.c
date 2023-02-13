#include "binary_search.h"

int bsearch(int array[], int key, int start, int end) {
    while (start < end) {
        int mid = start + (end - start) / 2;

        if (array[mid] > key)
            end = mid - 1;
        
        else if (array[mid] < key)
            start = mid + 1;
        
        else
            return array[mid];
    }

    return -1;
}

int bsearch_recursive(int array[], int key, int start, int end) {
    if (start > end)
        return -1;
    
    int mid = start + (end - start) / 2;
    if (array[mid] > key) {
        return bsearch_recursive(
            array,
            key,
            start,
            mid - 1
        );
    } else if (array[mid] < key) {
        return bsearch_recursive(
            array,
            key,
            mid + 1,
            end
        );
    } else
        return array[mid];
}
