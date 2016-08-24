#include <stdio.h>
#include <stdlib.h>
#include "/home/vagrant/ds-algos/trees/tree.h"
#include "queue.h"

#define EMPTY (-1) /* initial queue position */
/* 
 * definfitions: define maximum queue size 
 * */
#define MAX 7

int main(void)
{
    head = tail = EMPTY;

    struct BinaryTree *pos = (struct BinaryTree *) malloc(sizeof(struct BinaryTree) * MAX); /* keep position of first reference*/

    char *s[] = { "A", "B", "C", "D", "E", "F", "G" };
    int size = MAX;
    int end = (size - 1);  
    int start = 0;

    struct BinaryTree *letters = create_tree(s, start, end);

    traversal(letters, pos);

    free_tree(letters);
    free(pos);

    return 0;
}

