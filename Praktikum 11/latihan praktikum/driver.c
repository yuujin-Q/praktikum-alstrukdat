#include "listrec.h"

int main() {
    List l = NIL;
    if (isEmpty(l)) {
        printf("empty\n");
    } else {
        printf("not empty\n");
    }
    displayList(l);
    l = konso(l, 2);
    if (isOneElmt(l)) {
        printf("one\n");
    } else {
        printf("not one\n");
    }
    l = konso(l, 1);
    l = konsb(l, -3);
    l = konsb(l, -8);
    displayList(l);
    printf("max=%d\n", maxList(l));
    printf("min=%d\n", minList(l));
    printf("sum=%d\n", sumList(l));
    
    /*
    List l1 = NIL;
    List l2 = NIL;
    splitOnX(l, -3,  &l1, &l2);
    printf("l1\n");
    displayList(l1);
    printf("l2\n");
    displayList(l2);
    */
    
    List li = inverseList(l);
    displayList(li);
    return 0;
}
