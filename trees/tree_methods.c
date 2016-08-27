#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define NOT_NULL(item) item != NULL

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
                break;
            case 1:
                break;
            case 2:
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

int check_case(struct BinaryTree *node)
{
    int n = 0;
    if(NOT_NULL(node->left) || NOT_NULL(node->right)) {
        if(NOT_NULL(node->left) && NOT_NULL(node->right)) {
            return (n + 2);
        }
        return (++n);
    } 
    return n;
}

int equal(struct BinaryTree *node, char *value)
{
   return (strcmp(node->value, value) == 0);
}

int greater_than(struct BinaryTree *node, char *value)
{
    return (strcmp(node->value, value) < 0);
}
