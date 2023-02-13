#include <stdio.h>
#include <assert.h>

#include "binary_search.h"

void test_bsearch_returns_correct_result();
void test_bsearch_recursive_returns_correct_result();


int main() {
    printf("==============================================================\n");
    printf("BINARY SEARCH TESTS\n");
    printf("==============================================================\n");
    test_bsearch_returns_correct_result();
    test_bsearch_recursive_returns_correct_result();

    return 0;
}

void test_bsearch_returns_correct_result() {
    printf("test bsearch function returns correct results\n");

    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    assert(bsearch(array, 3, 0, 10) == 3);
    assert(bsearch(array, 8, 0, 10) == 8);
    assert(bsearch(array, 15, 0, 10) == -1);
}

void test_bsearch_recursive_returns_correct_result() {
    printf("test bsearch_recursive function returns correct results\n");

    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    assert(bsearch_recursive(array, 3, 0, 10) == 3);
    assert(bsearch_recursive(array, 8, 0, 10) == 8);
    assert(bsearch_recursive(array, 15, 0, 10) == -1);
}
