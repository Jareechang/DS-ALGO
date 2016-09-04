#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H 
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
void add_node(char *value, struct DoublyLinkedNode **node, struct DoublyLinkedList **list);
struct DoublyLinkedList *list_create(void);
void update_link(struct DoublyLinkedNode *head, struct DoublyLinkedNode *tail, struct DoublyLinkedList **list);

void print(struct DoublyLinkedNode *start_node);
void print_reverse(struct DoublyLinkedNode *start_node);
#endif
