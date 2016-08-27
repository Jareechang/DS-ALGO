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
int insert_node(char *value, struct BinaryTree *node, struct BinaryTree *parent)
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
    greater_than(node, value) ? insert_node(value, node->right, node) : 
                                insert_node(value, node->left, node);
    return 0;
}

int delete_node(char *value, struct BinaryTree *node)
{
    if(equal(node, value)) {
        /* check the cases */
        switch(check_case(node)) {
            case 0:
                printf("case 0\n");
                break;
            case 1:
                printf("case 1\n");
                break;
            case 2:
                printf("case 2\n");
                break;
            default:
                // do something
                break;
        }
        
    }
    // for example delete C
    /*greater_than(node, value) ? delete_node(value, node->right, node) : */
                                /*delete_node(value, node->left, node);*/
}

