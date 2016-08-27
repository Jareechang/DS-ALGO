#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "/home/vagrant/ds-algos/queues/queue.h"

#define IS_NULL(item) item == NULL

int MAX = 7;
int EMPTY = (-1);

int main()
{
    head = tail = EMPTY;
    char *s[] = { "A", "B", "C", "D", "E", "F", "G" };
    int size = MAX;
    int end = (size - 1);  
    int start = 0;
    struct BinaryTree *letters = create_tree(s, start, end);
    insert_node("Y", letters, letters);
    insert_node("Z", letters, letters);
    /*struct BinaryTree *target = (struct BinaryTree *) malloc(sizeof(struct BinaryTree));*/
    /*target = search_for("A", letters);*/
    printf("status: %d\n", delete_node("G", letters));
    print_tree(letters);
    free_tree(letters);
    return 0;
}
