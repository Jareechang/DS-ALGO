#include <stdio.h>
#include "tree.h"

#define NOT_NULL(item) item != NULL

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
