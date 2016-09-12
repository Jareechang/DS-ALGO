#include <stdio.h>
#include <stdlib.h>
#include "doubly_linked_list.h"

#define IS_NULL(x) (x == NULL ? "yes" : "no")

int main(void)
{
    struct DoublyLinkedList *list = list_alloc();
    node_create("A", &list);
    add_node_before("B", &list); 
    add_node_before("C", &list); 
    add_node_before("D", &list); 

    /*print(list->head);*/
    remove_node_after("B", &list);
    print_reverse(list->tail);
    return 0;
}
