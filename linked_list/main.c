#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    struct Node *letters = create_list("A");
    insert_node_end("B", letters);
    insert_node_end("C", letters);
    insert_node_end("D", letters);
    insert_node_after("B", "Z", &letters);
    printf("got value: %s\n", get_node("D", letters)->value);
    return 0;
}
