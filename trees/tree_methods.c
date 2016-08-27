#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include "tree.h"

#define NOT_NULL(item) item != NULL

/* get_parent:
 *
 *      returns the parent for the node with the given value on the tree 
 *          
 *          @arguments 
 *
 *          (char)                value: target value
 *          (struct BinaryTree)    node: starting node
 *          (struct BinaryTree)  parent: reference to parent
 *
 *          @return
 *
 *          (struct BinaryTree)  parent node of the target node (with the given value) 
 * */
struct BinaryTree *get_parent(char *value, struct BinaryTree *node, struct BinaryTree *parent)
{
    if(node == NULL) return tree_alloc();
    if(equal(node, value)) {
        return parent;
    }

    greater_than(node, value) ? get_parent(value, node->right, node) : 
                                get_parent(value, node->left, node);

}

/* get_target_node: 
 *
 *          given a value and a tree, it returns the node corresponding to 
 *          the value in he tree.  
 *          
 *          (char)                  value: target value
 *          (struct binaryTree)      node: starting point (at a given node)  
 *
 *          @return 
 *
 *          (struct BinaryTree)  target node (with the given value) 
 **/
struct BinaryTree *get_target_node(char *value, struct BinaryTree *node)
{
    return equal(node->left, value) ? node->left : node->right;
}

/* get_single_leaf: given a node it returns it's leaf (assuming only one leaf) */
struct BinaryTree *get_single_leaf(struct BinaryTree *node)
{
    if(NOT_NULL(node->left)) {
        return node->left;
    } else if(NOT_NULL(node->right)) {
        return node->right;
    } else {
        printf("Error: single leaf in '%s' is NULL... please \
                check case statement in delete_node()", node->value);
    }
}

/* get_min_node: provided with the right sub-tree, recursively
 * looks up the minimum node (note: should be a right node) */
struct BinaryTree *get_min_node(struct BinaryTree *node, struct BinaryTree *parent)
{
    if(node == NULL) {
        return parent;
    }
    get_min_node(node->left, node);
}

/* swap_link: swapping the link between the leaf and the deleted node on the given 
 *             parent node  */
void swap_link(struct BinaryTree *deleted_node, struct BinaryTree *parent, struct BinaryTree *leaf)
{
    /* checking which side of the parent the deleted node is on */
    if(greater_than(parent, deleted_node->value)) {
        parent->right = leaf;
    } else {
        parent->left = leaf;
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
    struct BinaryTree *target = tree_alloc();
    struct BinaryTree *parent = tree_alloc();
    struct BinaryTree *leaf = tree_alloc();

    /* search for target node */
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
                leaf = get_single_leaf(target);
                swap_link(target, parent, leaf);
                return 1;
                break;
            case 2:
                leaf = get_min_node(target->right, target);
                swap_link(target, parent, leaf);
                return 1;
                break;
            default:
                break;
        }
        return 0;
    }
}

