#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

struct DoublyLinkedList *list_alloc(void)
{
    return (struct DoublyLinkedList *) malloc(sizeof(struct DoublyLinkedList));
}

/* node_alloc: allocate memory for doubly linked list structure  */
struct DoublyLinkedNode *node_alloc(void)
{
    return (struct DoublyLinkedNode *) malloc(sizeof(struct DoublyLinkedNode));
}

/* add_node: create a node with specified value then build the link */
void add_node(char *value, struct DoublyLinkedNode *node, struct DoublyLinkedList **list)
{
    struct DoublyLinkedNode *new_node = node_create(value);
    node->next = new_node;
    new_node->prev = node;
    update_link(node, new_node, &(*list));
}

void update_link(struct DoublyLinkedNode *head, struct DoublyLinkedNode *tail, struct DoublyLinkedList **list)
{
    (*list)->head = head;
    (*list)->tail = tail;
}

/* node_create: creates a single node with the given value  */
struct DoublyLinkedNode *node_create(char *value)
{
    struct DoublyLinkedNode *new_node = node_alloc();
    new_node->value = value;
    new_node->prev = NULL; 
    new_node->next = NULL; 
    return new_node;
}
