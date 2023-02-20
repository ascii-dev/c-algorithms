#include <stdio.h>
#include <assert.h>

#include "sorting.h"

void test_merge_sort_works_correctly();

int main() {
    printf("==============================================================\n");
    printf("SORTING TESTS\n");
    printf("==============================================================\n");
    test_merge_sort_works_correctly();

    return 0;
}

void test_merge_sort_works_correctly() {
    int array[] = {9, 2, 4, 6, 5, 1, 7, 8, 0, 3};
    int length = 10;

    merge_sort(array, length);

    for (int i = 0; i < length; i++)
        assert(array[i] == i);
}
