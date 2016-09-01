#include <stdio.h>
#include "linked_list.h"

int main(void)
{
    struct Node *numbers = create_list("A");
    remove_node("B", numbers);
    printf("first value: %s\n", numbers->next->value);
    return 0;
}
