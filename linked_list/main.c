#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    struct Node *numbers = create_list("A");
    insert_node_end("B", numbers);
    insert_node_end("C", numbers);
    insert_node_end("D", numbers);
    insert_node_after("B", "Z", &numbers);
    print_all(numbers);
    /*printf("length: %d\n", length(numbers));*/
    return 0;
}
