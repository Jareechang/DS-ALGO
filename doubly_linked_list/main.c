#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

int main(void)
{
    struct DoublyLinkedList *list = list_alloc();
    struct DoublyLinkedNode *letters = node_create("A");
    add_node("B", letters, &list);
    return 0;
}
