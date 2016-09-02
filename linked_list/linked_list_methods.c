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

/* get node */

struct Node *get_node(char *value, struct Node *list)
{
    if(list == NULL) {
        printf("value not found");
        return list; /* return the null value*/
    }

    if(equal_value(list, value)) {
        return list;
    }

    get_node(value, list->next);
}

/* get_nth: get nth node in the linked-list 
 *  index range: 1 - n */
struct Node *get_nth(int n, struct Node *list)
{
    if(n == 1) {
        return list;
    }
    get_nth((--n), list->next);
}

/* inserts */

void insert_node_after(char *location, char *value, struct Node **node)
{

    if((*node) == NULL) {
        printf("insert node location not found\n");
        return;
    }

    if(equal_value((*node), location)) {
        struct Node *new_node = create_list(value);
        new_node->next = (*node)->next;
        (*node)->next = new_node;
        return;
    }

    insert_node_after(location, value, &((*node)->next));
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

/* removal */

void remove_node(char *value, struct Node *node)
{
    if(equal_value(node, value)) {
        return;
    }
    remove_node(value, node->next);
    node->next = NULL;
}

/* properties */

int length(struct Node *list)
{
    int len;
    if(list == NULL) return 0;
    len = length(list->next) + 1;
    return len;
}

/* helpers */
int equal_value(struct Node *node, char *value)
{
    return (strcmp(node->value, value) == 0);
}

void print_all(struct Node *list)
{
    if(list == NULL) return;
    printf("%s\n", list->value);
    print_all(list->next);
}
