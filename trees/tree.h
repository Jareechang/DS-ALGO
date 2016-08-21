#ifndef TREE_H
#define TREE_H
struct BinaryTree {
    char *value;
    struct BinaryTree *right;
    struct BinaryTree *left;
};

struct BinaryTree *create_tree(char **s, int start, int end);
struct BinaryTree *tree_alloc(void);
void print_tree(struct BinaryTree *root);
void free_tree(struct BinaryTree *root);
char *str_dup(char **s, int mid);
#endif
