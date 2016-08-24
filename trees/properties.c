#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"

char *min(struct BinaryTree *tree)
{
    if(tree->left == NULL && tree->right == NULL) {
        return strdup(tree->value);
    }
    min(tree->left);
}

char *max(struct BinaryTree *tree)
{
    if(tree->left == NULL && tree->right == NULL) {
        return strdup(tree->value);
    }
    min(tree->right);
}

/*void search_for(char *item, struct BinaryTree *tree)*/
/*{*/
    /*printf("item: %s\n", *item);*/
/*}*/
