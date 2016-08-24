#include <stdio.h>
#include <stdlib.h>
#include "/home/vagrant/ds-algos/trees/tree.h"

#define EMPTY (-1)
#define MAX 7

int head, tail;

struct Queue {
    int index; /* position tracker */
    char *item;
};

struct BinaryTree *enqueue(struct BinaryTree *pos, struct BinaryTree *tree);
struct BinaryTree *dequeue(struct BinaryTree *pos);

int queue_full(void);
int queue_empty(void);

void traversal(struct BinaryTree *tree, struct BinaryTree *pos);

int main(void)
{

    head = tail = EMPTY;

    struct BinaryTree *pos = (struct BinaryTree *) malloc(sizeof(struct BinaryTree) * MAX); /* keep position of first reference*/

    char *s[] = { "A", "B", "C", "D", "E", "F", "G" };
    int size = MAX;
    int end = (size - 1);  
    int start = 0;

    struct BinaryTree *letters = create_tree(s, start, end);

    traversal(letters, pos);

    free_tree(letters);
    free(pos);

    return 0;
}

struct BinaryTree *enqueue(struct BinaryTree *pos, struct BinaryTree *tree)
{
    if(head == EMPTY && tail == EMPTY) {
        ++head;
        ++tail;
    } else if(queue_full()) {
        /* reset pointer position if queue reaches max */
        tail = head = EMPTY;
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
