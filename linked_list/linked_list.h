#ifndef LINKED_LIST_H
#define LINKED_LIST_H
struct Node {
    char *value;
    struct Node *next;
};

struct Node *create_list(char *s);
struct Node *node_alloc(void);
void insert_node_after(char *location, char *value, struct Node **node);
void insert_node_end(char *value, struct Node *list);
void insert_node_beginning(char *value, struct Node **node);
struct Node *get_node(char *value, struct Node *list);
struct Node *get_nth(int n, struct Node *list);
void remove_node(char *value, struct Node *list);
int equal_value(struct Node *list, char *value);
void print_all(struct Node *list);
int length(struct Node *list);
#endif
