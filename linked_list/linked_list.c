#include <stdio.h>
#include <stdlib.h>

struct Node {
    char *value;
    struct Node *next;
};

struct Node *create_list(void);
struct Node *node_alloc(void);
void add_value(char *value, struct Node *list);

int main(void)
{
    struct Node *numbers = create_list();
    add_value("A", numbers);
    return 0;
}

struct Node *create_list(void)
{
    struct Node *temp = node_alloc();
    temp->next = NULL;
    return temp;
}

struct Node *node_alloc(void)
{
    return (struct Node *) malloc(sizeof(struct Node));
}

void add_value(char *value, struct Node *list)
{
    if(list->next == NULL) {
        struct Node *new_node = create_list();
        new_node->value = value;
        list->next = new_node;
        return;
    }
    add_value(value, list);
}
