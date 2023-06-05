#include "bintree.h"
#include <stdio.h>

int main() {
    BinTree b, b1;
    
    CreateTree(3, NewTree(4, newTreeNode(6), newTreeNode(8)), NewTree(6, newTreeNode(5), NULL), &b);
    printTree(b, 4);
    printf("rob2 : %d\n", rob2(b));

	CreateTree(3, NewTree(2, NULL, newTreeNode(3)), NewTree(3, newTreeNode(1), NULL), &b1);
	printTree(b1, 4);
	printf("rob2 : %d\n", rob2(b1));

	BinTree b2, b21, b22;
	BinTree b31, b32, b33, b34;
	CreateTree(6, newTreeNode(4), newTreeNode(9), &b31);
	CreateTree(7, newTreeNode(1), newTreeNode(3), &b32);
	CreateTree(9, newTreeNode(2), newTreeNode(4), &b33);
	CreateTree(1, newTreeNode(2), newTreeNode(7), &b34);
	
	CreateTree(4, b31, b32, &b21);
	CreateTree(5, b33, b34, &b22);
	CreateTree(3, b21, b22, &b2);
	printTree(b2, 4);
	printf("rob2 : %d\n", rob2(b2));

    return 0;
}
