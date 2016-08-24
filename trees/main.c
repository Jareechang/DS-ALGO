#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main()
{
    char *s[] = { "A", "B", "C", "D", "E", "F", "G" };
    int size = 7;
    int end = (size - 1);  
    int start = 0;
    struct BinaryTree *letters = create_tree(s, start, end);
    /*bfs_traversal(letters);*/
    /*print_tree(letters);*/
    printf("min: %s\n", min(letters));
    printf("min: %s\n", max(letters));
    free_tree(letters);
    return 0;
}
