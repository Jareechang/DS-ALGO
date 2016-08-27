#ifndef TREE_H
#define TREE_H
extern int MAX;
extern int EMPTY;
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
int check_case(struct BinaryTree *node);
int greater_than(struct BinaryTree *node, char *value);
int equal(struct BinaryTree *node, char *value);

/* Traversal methods */
void inorder_traversal(struct BinaryTree *root);
void preorder_traversal(struct BinaryTree *root);
void postorder_traversal(struct BinaryTree *root);
void bfs_traversal(struct BinaryTree *root);

/* Tree specific methods */
struct BinaryTree *get_parent(char *value, struct BinaryTree *node, struct BinaryTree *parent);
struct BinaryTree *get_single_leaf(struct BinaryTree *node);
int insert_node(char *value, struct BinaryTree *node, struct BinaryTree *parent);
int delete_node(char *value, struct BinaryTree *node);
struct BinaryTree *get_min_node(struct BinaryTree *node, struct BinaryTree *parent);
void swap_link(struct BinaryTree *deleted_node, struct BinaryTree *parent, struct BinaryTree *leaf);
void trim_leaf(char *value, struct BinaryTree *parent);

/* properties */
char *min(struct BinaryTree *tree);
char *max(struct BinaryTree *tree);
struct BinaryTree *search_for(char *item, struct BinaryTree *tree);
void print_children(char *target, struct BinaryTree *node);
void visit_leaves(char *node_value, struct BinaryTree *node);
int height(struct BinaryTree *tree);
#endif
