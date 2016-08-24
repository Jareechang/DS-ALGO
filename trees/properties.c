#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "/home/vagrant/ds-algos/queues/queue.h"

#define EMPTY (-1) /* initial queue position */
/* 
 * definfitions: define maximum queue size 
 * */
#define MAX 7

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
    return bfs_search(tree, pos, "A");
}
