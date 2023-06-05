#include "listlinier.h"
#include <stdio.h>

int main(){
    List l1, l2, l3;
    int val;
    CreateList(&l1);
    CreateList(&l2);
    CreateList(&l3);
    displayList(l1);
    insertFirst(&l1, 2);
    displayList(l1);

    putchar('\n');
    displayList(l2);
    insertFirst(&l2, 1);
    insertFirst(&l2, 3);
    insertFirst(&l2, 5);
    displayList(l2);


    putchar('\n');
    l3 = concat(l1,l2);
    displayList(l3);
    printf("\nL1=%d", length(l1));
    printf("\nL2=%d", length(l2));
    printf("\nL3=%d", length(l3));
    return 0;
}