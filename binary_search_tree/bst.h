#ifndef ASCII_BST
#define ASCII_BST

typedef struct BSTreeNode {
    int data;
    struct BSTreeNode *parent;
    struct BSTreeNode *left;
    struct BSTreeNode *right;
} BSTreeNode;

// TODO: work on retiring the BSTree struct and only use BSTreeNode
typedef struct BSTree {
    int size;
    struct BSTreeNode *root;
} BSTree;

BSTree *construct_bst();
void destroy_bst(BSTree *bst);
int get_node_count(BSTree *bst);
void print_values(BSTreeNode *root);
int in_tree(BSTree *bst, int data);
int get_min(BSTree *bst);
int get_max(BSTree *bst);
void insert(BSTree *bst, int data);
int get_height(BSTree *bst);
int is_bst(BSTree *bst);
BSTreeNode *create_node(int data);
void delete_data(BSTree *bst, int data);
int successor(BSTree *bst, int data);

#endif
