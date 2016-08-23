#include <stdio.h>
#include <stdlib.h>
#include "/home/vagrant/ds-algos/trees/tree.h"

struct Queue {
    int index; /* position tracker */
    char *item;
};

struct BinaryTree * enqueue(struct BinaryTree *ptr, struct BinaryTree *tree)
{
    *ptr++ = *tree;
    return ptr;
}

char *dequeue(struct BinaryTree *tree)
{
    static int i = 0;
    return (tree + i++)->value;
}

int main(void)
{

    struct BinaryTree *tree = (struct BinaryTree *) malloc(sizeof(struct BinaryTree)); 
    struct BinaryTree *tree_second = (struct BinaryTree *) malloc(sizeof(struct BinaryTree)); 

    tree->value = "abc";
    tree_second->value = "def";

    struct BinaryTree *ptr = (struct BinaryTree *) malloc(sizeof(struct BinaryTree)); /* ptr to store the link to trees */
    struct BinaryTree *pos = (struct BinaryTree *) malloc(sizeof(struct BinaryTree)); /* keep position of first reference*/

    pos = ptr;

    ptr = enqueue(ptr, tree);
    ptr = enqueue(ptr, tree_second);

    printf("tree value: %s\n", dequeue(pos));
    printf("tree value: %s\n", dequeue(pos));

    return 0;
}
