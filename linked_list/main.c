#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    struct Node *numbers = create_list("A");
    add_node("B", numbers);
    remove_node("B", numbers);
    return 0;
}
