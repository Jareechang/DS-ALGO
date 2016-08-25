#include <stdio.h>
#include <stdlib.h>
#include "tree.h"
#include "/home/vagrant/ds-algos/queues/queue.h"

#define EMPTY (-1) /* initial queue position */
/* 
 * definfitions: define maximum queue size 
 * */
#define MAX 10 

int main()
{
    head = tail = EMPTY;
    char *s[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K" };
    int size = 11;
    int end = (size - 1);  
    int start = 0;
    struct BinaryTree *letters = create_tree(s, start, end);
    print_tree(letters);

    /*print_leaves("D", letters);*/
    printf("height of tree: %d\n", height(letters));
    free_tree(letters);
    return 0;
}
