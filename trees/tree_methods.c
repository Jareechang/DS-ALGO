#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "tree.h"

struct BinaryTree *get_parent(char *value, struct BinaryTree *node, struct BinaryTree *parent)
{
    if(node == NULL) return tree_alloc();
    if(equal(node, value)) {
        return parent;
    }

    greater_than(node, value) ? get_parent(value, node->right, node) : 
                                get_parent(value, node->left, node);

}

struct BinaryTree *get_target_node(char *value, struct BinaryTree *node)
{
    return equal(node->left, value) ? node->left : node->right;
}

void swap_link(struct BinaryTree *target, struct BinaryTree *parent)
{
    if(equal(parent->left, target->value)) {
        // swap Z and G
    } else if(equal(parent->right, target->value)) {

    }

}

/* 
 * trim_leaf: trimming the leaf of the given value a parent node 
 * */
void trim_leaf(char *value, struct BinaryTree *parent)
{
    struct BinaryTree *temp = tree_alloc();
    temp = get_target_node(value, parent);
    temp = NULL;
}

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

int delete_node(char *value, struct BinaryTree *tree)
{
    /* search for target node */
    struct BinaryTree *target = tree_alloc();
    struct BinaryTree *parent = tree_alloc();
    target = search_for(value, tree);

    /* get its parent */
    parent = get_parent(value, tree, tree);

    if(equal(target, value)) {
        /* check the cases */
        switch(check_case(target)) {
            case 0:
                trim_leaf(value, parent);
                return 1;
                break;
            case 1:
                trim_leaf(value, parent);
                break;
            case 2:
                printf("case 2\n");
                break;
            default:
                // do something
                break;
        }
        return 0;
    }
    // for example delete C
    /*greater_than(node, value) ? delete_node(value, node->right, node) : */
                                /*delete_node(value, node->left, node);*/
}

