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
void inorder_traversal(struct BinaryTree *root);
void preorder_traversal(struct BinaryTree *root);
void postorder_traversal(struct BinaryTree *root);
void bfs_traversal(struct BinaryTree *root);

/* properties */
char *min(struct BinaryTree *tree);
char *max(struct BinaryTree *tree);
struct BinaryTree *search_for(char *item, struct BinaryTree *tree);
void print_children(char *target, struct BinaryTree *node);
#endif
