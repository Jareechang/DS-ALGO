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

void add_node(char *value, struct Node *node)
{
    if(node->next == NULL) {
        struct Node *new_node = create_list(value);
        node->next = new_node;
        return;
    }
    add_node(value, node->next);
}

int equal_value(struct Node *node, char *value)
{
    return (strcmp(node->value, value) == 0);
}

void remove_node(char *value, struct Node *node)
{
    if(equal_value(node, value)) {
        return;
    }
    remove_node(value, node->next);
    node->next = NULL;
}
