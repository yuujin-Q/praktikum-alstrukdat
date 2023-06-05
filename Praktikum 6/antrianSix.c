/*
NIM:13521074
Nama:Eugene Yap Jin Quan
Tanggal:07/10/2022
Topik praktikum:ADT Queue
Deskripsi: latihan praktikum antrianSix
*/

#include "queue.h"
#include <stdio.h>

int main(){
    int choice;
    int terlayani=0;
    int minmhs=0, maxmhs=0, summhs=0;
    int waktu;
    Queue antrian;
    CreateQueue(&antrian);
    while(true){
        scanf("%d", &choice);
        if(choice==1){
            scanf("%d", &waktu);
            if(length(antrian)+1<=CAPACITY){
                enqueue(&antrian, waktu);
            }
            else{
                printf("Queue penuh\n");
            }
        }
        else if (choice==2){
            if(length(antrian)>0){
                dequeue(&antrian, &waktu);
                summhs+=waktu;
                terlayani++;
                if(waktu<minmhs || minmhs==0){
                    minmhs = waktu;
                }
                if(waktu>maxmhs || maxmhs==0){
                    maxmhs = waktu;
                }
            }
            else{
                printf("Queue kosong\n");
            }
        }
        else if (choice==0){
            break;
        }
        
    };

    printf("%d\n", terlayani);
    if(terlayani!=0){
        printf("%d\n", minmhs);
        printf("%d\n", maxmhs);
        printf("%.2f\n", (float)summhs/(float)terlayani);
    }
    else{
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
        printf("Tidak bisa dihitung\n");
    }
    return 0;
}

