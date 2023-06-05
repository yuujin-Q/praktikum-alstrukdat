/*
NIM = 13521074
Nama = Eugene Yap Jin Quan
Tanggal = 08/09/2022
Topik praktikum = ADT Sederhana
Deskripsi = mtime.c (program problem menggunakan ADT Time)
*/

#include <stdio.h>
#include "time.h"

int main(){
    int record, i;
    long detikawal = 86400, detikakhir = 0;
    TIME T1, T2, temp;

    scanf("%d", &record);
    for (i = 1; i<=record; i++){
        printf("[%d]\n", i);
        BacaTIME(&T1);
        BacaTIME(&T2);

        if (TGT(T1, T2)){
            temp = T1;
            T1 = T2;
            T2 = temp;
        }

        printf("%d\n", Durasi(T1, T2));
        detikawal = (TIMEToDetik(T1) < detikawal) ? TIMEToDetik(T1) : detikawal;
        detikakhir = (TIMEToDetik(T2) > detikakhir) ? TIMEToDetik(T2) : detikakhir;

    }

    T1 = DetikToTIME(detikawal);
    T2 = DetikToTIME(detikakhir);
    TulisTIME(T1);
    putchar('\n');
    TulisTIME(T2);
    putchar('\n');
    return 0;
}