#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct Node {
    char *value;
    struct Node *next;
};

struct Node *create_list(char *s);
struct Node *node_alloc(void);
void add_node(char *value, struct Node *list);
void remove_node(char *value, struct Node *list);
int equal_value(struct Node *list, char *value);
#endif
