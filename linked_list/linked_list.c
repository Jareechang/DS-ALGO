#include <stdio.h>
#include <stdlib.h>

#define IS_NULL(x) x == NULL

struct Node {
    char *value;
    struct Node *next;
};

struct Node *create_list(char *s);
struct Node *node_alloc(void);
void add_node(char *value, struct Node *list);
void remove_node(char *value, struct Node *list);

int equal_value(struct Node *list, char *value);

int main(void)
{
    struct Node *numbers = create_list("A");
    add_node("B", numbers);
    remove_node("B", numbers);
    return 0;
}

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
