#include <assert.h>
#include <stdio.h>

#include "bst.h"

void test_bst_creation_successful();
void test_bst_get_node_count();
void test_bst_insert_new_node();
void test_bst_search_for_a_node();
void test_bst_get_min_value();
void test_bst_get_max_value();
void test_get_height_function();
void test_validate_tree_is_bst_function();

int main() {
    printf("==============================================================\n");
    printf("BINARY SEARCH TREE TESTS\n");
    printf("==============================================================\n");

    test_bst_creation_successful();
    test_bst_get_node_count();
    test_bst_insert_new_node();
    test_bst_search_for_a_node();
    test_bst_get_min_value();
    test_bst_get_max_value();
    test_get_height_function();
    test_validate_tree_is_bst_function();

    return 0;
}

void test_bst_creation_successful() {
    printf("test bst creation successful\n");

    BSTree *bst = construct_bst();

    assert(bst->root == NULL);

    destroy_bst(bst);
}

void test_bst_get_node_count() {
    printf("test bst get_node_count function\n");

    BSTree *bst = construct_bst();

    assert(get_node_count(bst) == 0);

    destroy_bst(bst);
}

void test_bst_insert_new_node() {
    printf("test that inserting a new node works as expected\n");

    BSTree *bst = construct_bst();

    insert(bst, 5);
    insert(bst, 3);
    insert(bst, 7);
    insert(bst, 9);
    insert(bst, 6);
    insert(bst, 2);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 8);
    insert(bst, 4);

    assert(bst->root->data == 5);
    assert(bst->root->left->data == 3);
    assert(bst->root->right->data == 7);

    print_values(bst->root); // 1, 2, 3, 4, 5, 6, 7, 8, 9
    printf("\n");

    destroy_bst(bst);
}

void test_bst_search_for_a_node() {
    printf("test that searching for a node works as expected\n");

    BSTree *bst = construct_bst();

    insert(bst, 5);
    insert(bst, 3);
    insert(bst, 7);
    insert(bst, 9);
    insert(bst, 6);
    insert(bst, 2);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 8);
    insert(bst, 4);

    assert(in_tree(bst, 9) == 1);
    assert(in_tree(bst, 15) == 0);
    assert(in_tree(bst, 1) == 1);

    destroy_bst(bst);
}

void test_bst_get_min_value() {
    printf("test that searching for minimum value works as expected\n");

    BSTree *bst = construct_bst();

    insert(bst, 5);
    insert(bst, 3);
    insert(bst, 7);
    insert(bst, 9);
    insert(bst, 6);
    insert(bst, 2);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 8);
    insert(bst, 4);

    assert(get_min(bst) == 1);

    destroy_bst(bst);
}

void test_bst_get_max_value() {
    printf("test that searching for maximum value works as expected\n");

    BSTree *bst = construct_bst();

    insert(bst, 5);
    insert(bst, 3);
    insert(bst, 7);
    insert(bst, 9);
    insert(bst, 6);
    insert(bst, 2);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 8);
    insert(bst, 4);

    assert(get_max(bst) == 9);

    destroy_bst(bst);
}

void test_get_height_function() {
    printf("test that get_height works as expected\n");

    BSTree *bst = construct_bst();

    insert(bst, 5);
    insert(bst, 3);
    insert(bst, 7);
    insert(bst, 9);
    insert(bst, 6);
    insert(bst, 2);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 8);
    insert(bst, 4);

    assert(get_height(bst) == 4);

    destroy_bst(bst);
}

void test_validate_tree_is_bst_function() {
    printf("test that the tree is a bst\n");

    BSTree *bst = construct_bst();

    insert(bst, 5);
    insert(bst, 3);
    insert(bst, 7);
    insert(bst, 9);
    insert(bst, 6);
    insert(bst, 2);
    insert(bst, 1);
    insert(bst, 3);
    insert(bst, 8);
    insert(bst, 4);

    assert(is_bst(bst) == 1);

    BSTree *non_bst = construct_bst();

    non_bst->root = create_node(1);
    non_bst->root->left = create_node(9);
    non_bst->root->right = create_node(0);

    destroy_bst(bst);
}
