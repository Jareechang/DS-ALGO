#include <stdio.h>
#include <stdlib.h>

/* structure of individual doubly linked nodes  */
struct DoublyLinkedNode {
    char *value;
    struct DoublyLinkedNode *next;
    struct DoublyLinkedNode *prev;
};

/* structure for Doubly Linked list - holding reference to head and tail
 * of the list  */
struct DoublyLinkedList {
    struct DoublyLinkedNode *head;
    struct DoublyLinkedNode *tail;
};

struct DoublyLinkedNode *node_alloc(void);
struct DoublyLinkedList *list_alloc(void);
struct DoublyLinkedNode *node_create(char *value);
void add_node(char *value, struct DoublyLinkedNode *node, struct DoublyLinkedList **list);
struct DoublyLinkedList *list_create(void);
void update_link(struct DoublyLinkedNode *head, struct DoublyLinkedNode *tail, struct DoublyLinkedList **list);

int main(void)
{
    struct DoublyLinkedList *list = list_alloc();
    struct DoublyLinkedNode *letters = node_create("A");
    add_node("B", letters, &list);
    return 0;
}

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
