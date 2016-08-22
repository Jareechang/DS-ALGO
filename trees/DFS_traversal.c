#include <stdio.h>
#include "tree.h"

/* Inorder Traversal: <left> <root> <right> */
void inorder_traversal(struct BinaryTree *root)
{
    if(root == NULL) return; /* Base case */
    inorder_traversal(root->left);
    printf("%s\n", root->value);
    inorder_traversal(root->right);
}

/* Preorder Traversal: <root> <left> <right> */
void preorder_traversal(struct BinaryTree *root)
{
    if(root == NULL) return;
    printf("%s\n", root->value);
    preorder_traversal(root->left);
    preorder_traversal(root->right);
}

/* Postorder Traversal: <left> <right> <root> */
void postorder_traversal(struct BinaryTree *root)
{
    if(root == NULL) return; /* Base case */
    postorder_traversal(root->left);
    postorder_traversal(root->right);
    printf("%s\n", root->value);
}
