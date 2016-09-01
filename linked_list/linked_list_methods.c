#include <stdio.h>
#include <stdlib.h>
#include "linked_list.h"

#define IS_NULL(x) x == NULL

struct Node *create_list(char *s)
{
    struct Node *temp = node_alloc();
    temp->value = s;
    temp->next = NULL;
    return temp;
}

struct Node *node_alloc(void)
{
    return (struct Node *) malloc(sizeof(struct Node));
}

void insert_node_beginning(char *value, struct Node **node)
{
    struct Node *new_node = create_list(value);
    new_node->next = *node;
    *node = new_node;
}

void insert_node_end(char *value, struct Node *node)
{
    if(node->next == NULL) {
        struct Node *new_node = create_list(value);
        node->next = new_node;
        return;
    }
    insert_node_end(value, node->next);
}

void remove_node(char *value, struct Node *node)
{
    if(equal_value(node, value)) {
        return;
    }
    remove_node(value, node->next);
    node->next = NULL;
}

void print_all(struct Node *list)
{
   if(list == NULL) return;
   printf("%s\n", list->value);
   print_all(list->next);
}

/* helpers */
int equal_value(struct Node *node, char *value)
{
    return (strcmp(node->value, value) == 0);
}
