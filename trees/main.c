#include <stdio.h>
#include "tree.h"

int main()
{
    char *s[] = { "A", "B", "C", "D", "E", "F", "G" };
    int size = 7;
    int end = (size - 1);  
    int start = 0;
    struct BinaryTree *letters = create_tree(s, start, end);
    /*print_tree(letters);*/
    printf("post-order\n");
    postorder_traversal(letters);
    printf("pre-order\n");
    preorder_traversal(letters);
    printf("in-order\n");
    inorder_traversal(letters);
    free_tree(letters);
    return 0;
}
