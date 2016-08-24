#include <stdio.h>
#include <stdlib.h>
#include "/home/vagrant/ds-algos/trees/tree.h"
#include "queue.h"

struct BinaryTree *enqueue(struct BinaryTree *pos, struct BinaryTree *tree)
{
    if(head == EMPTY && tail == EMPTY) {
        ++head;
        ++tail;
    } else if(queue_full()) {
        tail = head = EMPTY;
        /* reset pointer position if queue reaches max */
    } else {
        ++tail;
    } 

    *(pos + tail) = *tree;
    return pos;
}

int queue_full(void)
{
    return (tail == (MAX - 1));
}

int queue_empty(void)
{
    if(head > 0 && tail > 0) {
        return head == tail;
    } 
}

struct BinaryTree *dequeue(struct BinaryTree *pos)
{
    return (pos + head++);
}

void traversal(struct BinaryTree *tree, struct BinaryTree *pos)
{
    if(head <= (MAX - 1) && tail <= (MAX - 1)) {
        // Visit node
        printf("%s\n", tree->value);
        if(tree->left != NULL || tree->right != NULL) {
            enqueue(pos, tree->left);
            enqueue(pos, tree->right);
        } 
        traversal(dequeue(pos), pos);
    } 
    return;
}
