#include "queue.h"
#include <stdio.h>

int main(){
    Queue q;
    CreateQueue(&q);
    int i;
    ElType val;
    scanf("%d", &i);
    for (int j=0;j<i;j++){
        scanf("%d", &val);
        enqueue(&q, val);
    }
    dequeue(&q, &val);
    dequeue(&q, &val);
    dequeue(&q, &val);
    enqueue(&q, val);
    displayQueue(q);
    return 0;
}