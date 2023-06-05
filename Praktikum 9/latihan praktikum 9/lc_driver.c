#include <stdio.h>
#include "list_circular.h"

int main(){
    List lc;
    CreateList(&lc);

    if (isEmpty(lc)){
        printf("LC is empty\n");
    }

    printf("insert first(2), last(3), first(1), last(4)\n");  /* 1,2,3,4 */
    insertFirst(&lc, 2);
    displayList(lc);
    putchar('\n');

    insertLast(&lc, 3);
    displayList(lc);
    putchar('\n');

    insertFirst(&lc, 1);
    displayList(lc);
    putchar('\n');

    insertLast(&lc, 4);
    displayList(lc);
    putchar('\n');

    ElType val;
    printf("delete first, last\n");  /* 2,3 */
    deleteFirst(&lc, &val);
    displayList(lc);
    putchar('\n');

    deleteLast(&lc, &val);
    displayList(lc);
    putchar('\n');
}