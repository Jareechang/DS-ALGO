#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include <string.h>

struct BinaryTree *create_tree(char **s, int start, int end)
{
    int mid = ((end + start)/2);
    int i = 0;
    struct BinaryTree *Tree = tree_alloc(); /* allocate memory for tree */

    Tree->value = str_dup(s, mid);

    if(start > end) {
        return NULL;
    }

    Tree->left =  create_tree(s, start, (mid - 1));
    Tree->right =  create_tree(s, (mid + 1), end);
    return Tree;
}

struct BinaryTree *tree_alloc(void)
{
    return (struct BinaryTree *) malloc(sizeof(struct BinaryTree));
}

void print_tree(struct BinaryTree *root)
{
    if(root != NULL) {
        printf("%s\n", root->value);
        print_tree(root->left);
        print_tree(root->right);
    }
}

void free_tree(struct BinaryTree *root) 
{
    if (root != NULL) {
        free(root->value);
        free_tree(root->left);
        free_tree(root->right);
        free(root);
    }
}

char *str_dup(char **s, int mid)
{
    char *p;
    p = (char *) malloc(strlen(s[mid]) + 1);
    strcpy(p, s[mid]);
    return p;
}
