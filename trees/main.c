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

    printf("item found? : %s\n", IS_NULL((search_for("Z", letters))->value) ? "yes" : "no");
    free_tree(letters);
    return 0;
}
