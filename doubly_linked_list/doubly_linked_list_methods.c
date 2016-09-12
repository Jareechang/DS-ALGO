#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"
#define IS_LAST_NODE(target_node) (target_node->prev == NULL && target->next == NULL)

struct DoublyLinkedList *list_alloc(void)
{
    return (struct DoublyLinkedList *) malloc(sizeof(struct DoublyLinkedList));
}

/* node_alloc: allocate memory for doubly linked list structure  */
struct DoublyLinkedNode *node_alloc(void)
{
    return (struct DoublyLinkedNode *) malloc(sizeof(struct DoublyLinkedNode));
}

struct DoublyLinkedNode *find_node(char *value, struct DoublyLinkedNode *node)
{
    if(node == NULL) return node;
    if(equal_value(node, value)) {
        return node;
    }
    find_node(value, node->next);
}

void remove_node_after(char *value, struct DoublyLinkedList **list)
{
    struct DoublyLinkedNode *target_node = find_node(value, (*list)->head);

    if(target_node == NULL) {
        printf("Node not found\n");
        return;
    }

    if(target_node->prev == NULL && target_node->next == NULL) { /* last node in list */
        clear_link(&(*list));
    } else if(target_node->prev == NULL) { /* is head node */
        struct DoublyLinkedNode *next_node = target_node->next;
        next_node->prev = NULL;
        update_head(next_node, &(*list));
    } else if(target_node->next == NULL) {  /* is tail node */
        struct DoublyLinkedNode *prev_node = target_node->prev;
        prev_node->next = NULL;
        update_link(prev_node, prev_node, &(*list));
    } else { /* neither */
        struct DoublyLinkedNode *next_node = target_node->next;
        struct DoublyLinkedNode *prev_node = target_node->prev;
        prev_node->next = next_node;
        next_node->prev = prev_node;
    }
}

int equal_value(struct DoublyLinkedNode *node, char *value)
{
    return (strcmp(node->value, value) == 0);
}


/* LIST operations */
void update_link(struct DoublyLinkedNode *head, struct DoublyLinkedNode *tail, struct DoublyLinkedList **list)
{
    update_head(head, &(*list));
    update_tail(tail, &(*list));
}

void clear_link(struct DoublyLinkedList **list)
{
    (*list)->head = NULL;
    (*list)->tail = NULL;
}

void update_head(struct DoublyLinkedNode *head, struct DoublyLinkedList **list)
{
    (*list)->head = head;
}

void update_tail(struct DoublyLinkedNode *tail, struct DoublyLinkedList **list)
{
    (*list)->tail = tail;
}

/* add_node: create a node with specified value then build the link */
void add_node_before(char *value, struct DoublyLinkedList **list)
{
    struct DoublyLinkedNode *head_node = (*list)->head;
    struct DoublyLinkedNode *new_node = node_new(value);
    head_node->prev = new_node;
    new_node->next = head_node;
    update_head(new_node, &(*list));
}

struct DoublyLinkedNode *node_create(char *value, struct DoublyLinkedList **list)
{
    struct DoublyLinkedNode *new_node = node_new(value);
    update_link(new_node, new_node, &(*list)); 
    return new_node;
}

/* node_create: creates a single node with the given value  */
struct DoublyLinkedNode *node_new(char *value)
{
    struct DoublyLinkedNode *new_node = node_alloc();
    new_node->value = value;
    new_node->prev = NULL; 
    new_node->next = NULL; 
    return new_node;
}

/* print: */
void print(struct DoublyLinkedNode *start_node) 
{
    if(start_node == NULL) return;
    printf("%s\n", start_node->value);
    print(start_node->next);
}

void print_reverse(struct DoublyLinkedNode *start_node)
{
    if(start_node == NULL) return;
    printf("%s\n", start_node->value);
    print_reverse(start_node->prev);
}
