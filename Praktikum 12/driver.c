#include "bintree.h"
#include <stdio.h>

int main() {
    BinTree b;
    CreateTree(0, NewTree(11, newTreeNode(21), newTreeNode(22)), newTreeNode(12), &b);
    printPreorder(b);
    putchar('\n');
    printInorder(b);
    putchar('\n');
    printPostorder(b);
    putchar('\n');

    return 0;
}