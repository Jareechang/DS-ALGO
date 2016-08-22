#ifndef TREE_H
#define TREE_H
/* Tree Structure  */
struct BinaryTree {
    char *value;
    struct BinaryTree *right;
    struct BinaryTree *left;
};

/* Generic Methods  */
struct BinaryTree *create_tree(char **s, int start, int end);
void print_tree(struct BinaryTree *root);
/* Memory specific */
struct BinaryTree *tree_alloc(void);
void free_tree(struct BinaryTree *root);
/* Helper methods */
char *str_dup(char **s, int mid);

/* Traversal methods */
void traverse(struct BinaryTree *root);
#endif
