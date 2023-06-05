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
    l = konsb(l, 3);
    displayList(l);
    return 0;
}