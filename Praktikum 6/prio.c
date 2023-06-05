#include <stdio.h>
#include "prioqueuetime.h"

infotype ingfo(int time, char inf){
    infotype inff;
    Time(inff) = time;
    Info(inff) = inf;
    return inff;
}

int main(){
    PrioQueueTime p;
    MakeEmpty(&p, 10);


    Enqueue(&p, ingfo(1, 'j'));
    Enqueue(&p, ingfo(2, 'd'));
    Enqueue(&p, ingfo(2, 'g'));
    Enqueue(&p, ingfo(4, 'o'));
    // Dequeue(&p, &temp);
    // Dequeue(&p, &temp);
    // Enqueue(&p, temp);
    // Dequeue(&p, &temp);
    // Dequeue(&p, &temp);

    PrintPrioQueueTime(p);

    Enqueue(&p, ingfo(4, 'y'));
    Enqueue(&p, ingfo(2, 'a'));
    PrintPrioQueueTime(p);

    printf("nbelmt=%d\n", NBElmt(p));
    printf("isfull=%d\n", IsFull(p));
    return 0;
}