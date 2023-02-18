/*
IMPLEMENT BINARY SEARCH TREE
 -  insert // insert value into tree
 -  get_node_count // get count of values stored
 -  print_values // prints the values in the tree, from min to max
 -  delete_tree
 -  is_in_tree // returns true if given value exists in the tree
 -  get_height // returns the height in nodes (single node's height is 1)
 -  get_min // returns the minimum value stored in the tree
 -  get_max // returns the maximum value stored in the tree
 -  is_binary_search_tree
 -  delete_value
 -  get_successor // returns next-highest value in tree after given value, -1 if none
*/
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#include "bst.h"

BSTree *construct_bst() {
    BSTree *bst = malloc(sizeof(BSTree));
    bst->size = 0;
    bst->root = NULL;

    return bst;
}

void _delete_all_nodes(BSTreeNode *node) {
    if (node == NULL) return;
    
    _delete_all_nodes(node->left);
    _delete_all_nodes(node->right);

    free(node);
}

void destroy_bst(BSTree *bst) {
    _delete_all_nodes(bst->root);
    free(bst);
}

int _get_node_count(BSTreeNode *root) {
    if (root == NULL) return 0;

    return 1 + _get_node_count(root->left) + _get_node_count(root->right);
}

int get_node_count(BSTree *bst) {
    return bst->size;
}

void print_values(BSTreeNode *root) {
    if (root == NULL) return;

    print_values(root->left);
    printf("%d,", root->data);
    print_values(root->right);
}

BSTreeNode *_in_tree(BSTreeNode *root, int data) {
    if (root == NULL) return NULL;

    if (root->data > data)
        return _in_tree(root->left, data);

    if (root->data < data)
        return _in_tree(root->right, data);

    return root;
}

int in_tree(BSTree *bst, int data) {
    if (_in_tree(bst->root, data) == NULL)
        return 0;
    return 1;
}

BSTreeNode *_get_min(BSTreeNode *root) {
    while (root->left != NULL)
        root = root->left;

    return root;
}

int get_min(BSTree *bst) {
    BSTreeNode *root = bst->root;

    if (root == NULL)
        return 0;

    return _get_min(root)->data;
}

int get_max(BSTree *bst) {
    BSTreeNode *root = bst->root;

    if (root == NULL)
        return 0;

    while (root->right != NULL)
        root = root->right;

    return root->data;
}

BSTreeNode *create_node(int data) {
    BSTreeNode *new_node = (BSTreeNode *) malloc(sizeof(BSTreeNode));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}

void _insert_in_subtree(BSTreeNode *node, int data) {
    if (data < node->data) {
        if (node->left != NULL)
            return _insert_in_subtree(node->left, data);
        else
            node->left = create_node(data);
    } else if (data > node->data) {
        if (node->right != NULL)
            return _insert_in_subtree(node->right, data);
        else
            node->right = create_node(data);
    }
}

void insert(BSTree *bst, int data) {
    if (bst->root == NULL)
        bst->root = create_node(data);
    else {
        _insert_in_subtree(bst->root, data);
    }
    bst->size++;
}

int _max(int a, int b) {
    return (a > b) ? a : b;
}

int _get_height(BSTreeNode *root) {
    if (root == NULL) return 0;

    return 1 + _max(_get_height(root->left), _get_height(root->right));
}

int get_height(BSTree *bst) {
    return _get_height(bst->root);
}

int _is_bst(BSTreeNode *root, int min, int max) {
    if (root == NULL) return 1;

    return root->data > min
        && root->data < max
        && _is_bst(root->left, min, root->data)
        && _is_bst(root->right, root->data, max);
}

// Another way to solve is to traverse in dfs in-order
// keep track of the previously read node and ensuring
// that the current node is greater than the previously
// read node because in-order traversal traverses in 
// sorted order.
int is_bst(BSTree *bst) {
    // https://www.youtube.com/watch?v=yEwSGhSsT0U
    return _is_bst(bst->root, INT_MIN, INT_MAX);
}

void print_pre_order(BSTreeNode *root) {
    if (root == NULL) return;

    printf("%d,", root->data);
    print_pre_order(root->left);
    print_pre_order(root->right);
}

void print_post_order(BSTreeNode *root) {
    if (root == NULL) return;

    print_post_order(root->left);
    print_post_order(root->right);
    printf("%d,", root->data);
}

BSTreeNode *_delete_data(BSTreeNode *root, int data) {
    if (root == NULL) return root;
    else if (root->data > data) root->left = _delete_data(root->left, data);
    else if (root->data < data) root->right = _delete_data(root->right, data);
    else {
        // Case 1: No child
        if (root->left == NULL && root->right == NULL){
            free(root);
            root = NULL;
        }

        // Case 2: One child
        else if (root->left == NULL) {
            BSTreeNode *temp = root;
            root = root->right;
            free(temp);
        }

        else if (root->right == NULL) {
            BSTreeNode *temp = root;
            root = root->left;
            free(temp);
        }

        // Case 3: Two children
        else {
            BSTreeNode *temp = _get_min(root->right);
            root->data = temp->data;
            root->right = _delete_data(root->right, temp->data);
        }
    }

    return root;
}

// TODO: test this function
void delete_data(BSTree *bst, int data) {
    // https://www.youtube.com/watch?v=gcULXE7ViZw
    bst->root = _delete_data(bst->root, data);
}

int _successor(BSTreeNode *root, int data) {
    BSTreeNode *current = _in_tree(root, data);
    if (current == NULL) return -1;

    // Case 1: node has right subtree
    if (current->right != NULL) {
        BSTreeNode *smallest = _get_min(current->right);
        return smallest->data;
    }
    // Case 2: no right subtree
    else {
        BSTreeNode *successor = NULL;
        BSTreeNode *ancestor = root;

        while (ancestor != current) {
            if (current->data < ancestor->data) {
                // successor is the deepest node for which the current
                // node is on it's left branch
                successor = ancestor;
                ancestor = ancestor->left;
            } else
                ancestor = ancestor->right;
        }

        return (successor != NULL) ? successor->data : -1;
    }
}

int successor(BSTree *bst, int data) {
    // https://www.youtube.com/watch?v=5cPbNCrdotA
    return _successor(bst->root, data);
}
