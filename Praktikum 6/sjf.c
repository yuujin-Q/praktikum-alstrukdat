/*
NIM: 13521074
Nama: Eugene Yap Jin Quan
Tanggal: 13/10/2022
Topik praktikum: ADT Queue
Deskripsi: sjf.c
*/

#include "prioqueuetime.h"
#include <stdio.h>

int main(){
    int n;
    PrioQueueTime process;
    infotype proc;
    
    scanf("%d",&n);
    
    MakeEmpty(&process, n);
    
    //enqueue dan pemrosesan
    int i;
    int timer=0;
    int elapsed=0;
    
    for(i=0;i<n;i++){
        scanf("%d %c", &Time(proc), &Info(proc));
        Enqueue(&process, proc);
        if(timer==0){
            Dequeue(&process,&proc);
            printf("%d %c\n",elapsed,Info(proc));
            timer = Time(proc);
            elapsed += timer;
        }
        timer--;
    }
    
    //dequeue yang tersisa untuk mendapatkan history lengkap
    while(!IsEmpty(process)){
        Dequeue(&process,&proc);
        printf("%d %c\n",elapsed,Info(proc));
        timer = Time(proc);
        elapsed += timer;
    }

    DeAlokasi(&process);
    return 0;
}