#include <stdio.h>

struct DoublyLinkedNode {
    char *value;
    struct DoublyLinkedNode *next;
    struct DoublyLinkedNode *prev;
};

int main(void)
{
    return 0;
}


struct DoublyLinkedNode *node_alloc(void)
{
    return (struct DoublyLinkedNode *) malloc(sizeof(struct DoublyLinkedNode));
}

struct DoublyLinkedNode *node_create(char *value)
{
    struct DoublyLinkedNode *new_node = node_alloc();
    new_node->value = value;
    return new_node;
}
