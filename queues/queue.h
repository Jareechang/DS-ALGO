#ifndef QUEUE_H
#define QUEUE_H
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
#endif
