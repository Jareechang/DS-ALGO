#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "/home/vagrant/ds-algos/queues/queue.h"

#define EMPTY (-1) /* initial queue position */
/* 
 * definfitions: define maximum queue size 
 * */
#define MAX 7

int main()
{
    head = tail = EMPTY;
    char *s[] = { "A", "B", "C", "D", "E", "F", "G" };
    int size = 7;
    int end = (size - 1);  
    int start = 0;
    struct BinaryTree *letters = create_tree(s, start, end);
    struct BinaryTree *target = (struct BinaryTree *) malloc(sizeof(struct BinaryTree));
    /*bfs_traversal(letters);*/
    /*print_tree(letters);*/
    /*printf("min: %s\n", min(letters));*/
    /*printf("min: %s\n", max(letters));*/
    target = search_for("A", letters);
    printf("target: %s\n", target->value);
    free_tree(letters);
    return 0;
}
