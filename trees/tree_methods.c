#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "tree.h"

/* 
 * insert: 
 *  insert a node into provided tree with the 
 *  given value  
 *
 *  @return: int (signal for success or failure)
 *      successful insertion - 1 
 *      failed insertion - 0 
 * */
int insert(char *value, struct BinaryTree *node, struct BinaryTree *parent)
{
    if(node == NULL) {
        struct BinaryTree *temp = tree_alloc();
        temp->right = temp->left = NULL;
        temp->value = strdup(value);
        if(greater_than(parent, value)) {
            parent->right = temp;
        } else {
            parent->left = temp;
        }
        return 1;
    }
    /* traverse right if greater, 
     *      else must be less than (traverse left) */
    return greater_than(node, value) ? insert(value, node->right, node) : 
                                       insert(value, node->left, node);
}

int greater_than(struct BinaryTree *node, char *value)
{
    return (strcmp(node->value, value) < 0);
}
