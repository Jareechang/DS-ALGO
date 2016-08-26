#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "/home/vagrant/ds-algos/queues/queue.h"

#define F_MAX(x,y) (((x) > (y)) ? (x) : (y))

/* min: returns smallest item in the tree (furthest left leaf) */
char *min(struct BinaryTree *tree)
{
    if(tree->left == NULL && tree->right == NULL) {
        return strdup(tree->value);
    }
    min(tree->left);
}
/* max: returns largest item in the tree (furthest right leaf) */
char *max(struct BinaryTree *tree)
{
    if(tree->left == NULL && tree->right == NULL) {
        return strdup(tree->value);
    }
    min(tree->right);
}

/* search_for:
 * using BFS traversal search it returns BinaryTree struct or NOT FOUND(-1) 
 * if item request exists in tree */
struct BinaryTree *search_for(char *item, struct BinaryTree *tree)
{
    struct BinaryTree *pos = (struct BinaryTree *) malloc(sizeof(struct BinaryTree) * MAX); /* keep position of first reference*/
    return bfs_search(tree, pos, item);
}

/* visit_leaves: given a start node, it recursively visits the leaves 
 * (excluding the given node) */
void visit_leaves(char *node_value, struct BinaryTree *node)
{
    if(node == NULL) return;
    visit_leaves(node_value, node->left);
    visit_leaves(node_value, node->right);
    printf("%s\n", node->value);
    if(strcmp(node_value, node->value) == 0) return; /* ignore the target node */
}

/* print_leaves: given a node (sub-tree), print it's leaves (or children) */
void print_leaves(char *target, struct BinaryTree *node)
{
    struct BinaryTree *temp = search_for(target, node);
    visit_leaves(target, temp);
}

/* max_depth: number of edges from current node to the tree's root node */
int max_depth(struct BinaryTree *node)
{
    if(node == NULL) return 0;
    int left_depth = 1 + max_depth(node->left);
    int right_depth = 1 + max_depth(node->right);
    return F_MAX(left_depth, right_depth);
}

/* Height: number of edges on longest path from the node to leaf (leaf having height = 0)
 * 
 * NOTE: this function makes use of max_depth function call to make a clear distinction between 
 * 'depth' and 'height'*/
int height(struct BinaryTree *tree)
{
    if(tree == NULL) return 0;
    int left_depth = 1 + max_depth(tree->left);
    int right_depth = 1 + max_depth(tree->right);
    return F_MAX(left_depth, right_depth);
}
