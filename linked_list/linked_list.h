#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct Node {
    char *value;
    struct Node *next;
};

struct Node *create_list(char *s);
struct Node *node_alloc(void);
void insert_node_end(char *value, struct Node *list);
void insert_node_beginning(char *value, struct Node **node);
void remove_node(char *value, struct Node *list);
int equal_value(struct Node *list, char *value);
#endif
