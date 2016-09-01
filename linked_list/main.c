#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    struct Node *numbers = create_list("A");
    insert_node_end("B", numbers);
    insert_node_end("C", numbers);
    insert_node_end("D", numbers);
    print_all(numbers);
    return 0;
}
