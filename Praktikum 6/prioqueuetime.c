/*
NIM: 13521074
Nama: Eugene Yap Jin Quan
Tanggal: 07/10/2022
Topik praktikum: ADT Queue
Deskripsi: prioqueuetime.c
*/

#include "prioqueuetime.h"
#include <stdio.h>
#include <stdlib.h>

/* File : prioqueuetime.h */
/* Definisi ADT Priority Queue Time dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

// #define Nil -1
/* Konstanta untuk mendefinisikan address tak terdefinisi */

/* Definisi elemen dan address */
// typedef struct {
//     int time;  /* [1..100], waktu dengan nilai 1..100 (1 adalah waktu adalah terendah) */
//     char info;  /* elemen karakter */
// } infotype;

// typedef int address;   /* indeks tabel */

// /* Contoh deklarasi variabel bertype PrioQueueTime : */
// /* Versi I : tabel dinamik, Head dan Tail eksplisit, ukuran disimpan */
// typedef struct {
//     infotype * T;   /* tabel penyimpan elemen */
//     address HEAD;  /* alamat penghapusan */
//     address TAIL;  /* alamat penambahan */
//     int MaxEl;     /* Max elemen queue */
// } PrioQueueTime;
// /* Definisi PrioQueueTime kosong: HEAD=Nil; TAIL=Nil. */
// /* Catatan implementasi: T[0] tidak pernah dipakai */

// /* ********* AKSES (Selektor) ********* */
// /* Jika e adalah infotype dan Q adalah PrioQueueTime, maka akses elemen : */
// #define Time(e)     (e).time
// #define Info(e)     (e).info
// #define Head(Q)     (Q).HEAD
// #define Tail(Q)     (Q).TAIL
// #define InfoHead(Q) (Q).T[(Q).HEAD]
// #define InfoTail(Q) (Q).T[(Q).TAIL]
// #define MaxEl(Q)    (Q).MaxEl
// #define Elmt(Q,i)   (Q).T[(i)]

/* ********* Prototype ********* */
boolean IsEmpty (PrioQueueTime Q){
    return (Head(Q)==Nil && Tail(Q)==Nil);
};
/* Mengirim true jika Q kosong: lihat definisi di atas */
boolean IsFull (PrioQueueTime Q){
    return (NBElmt(Q)==MaxEl(Q));
};
/* Mengirim true jika tabel penampung elemen Q sudah penuh */
/* yaitu mengandung elemen sebanyak MaxEl */
int NBElmt (PrioQueueTime Q){
    if (IsEmpty(Q)){
        return 0;
    }
    else if (Head(Q)<=Tail(Q)){
        return (Tail(Q)-Head(Q)+1);
    }
    else{
        return (MaxEl(Q)+(Tail(Q)-Head(Q))+1);
    }
};
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/* *** Kreator *** */
void MakeEmpty (PrioQueueTime * Q, int Max){
    (Q)->T = (infotype *) malloc((Max+1)*sizeof(infotype));
    if((Q)->T == NULL){
        MaxEl(*Q) = 0;
    }
    else{
        MaxEl(*Q) = Max;
    }
    Head(*Q) = Nil;
    Tail(*Q) = Nil;
};
/* I.S. sembarang */
/* F.S. Sebuah Q kosong terbentuk dan salah satu kondisi sbb: */
/* Jika alokasi berhasil, Tabel memori dialokasi berukuran Max+1 */
/* atau : jika alokasi gagal, Q kosong dg MaxEl=0 */
/* Proses : Melakukan alokasi, membuat sebuah Q kosong */

/* *** Destruktor *** */
void DeAlokasi(PrioQueueTime * Q){
    Head(*Q)=Nil;
    Tail(*Q)=Nil;
    MaxEl(*Q)=0;
    free((Q)->T);
};
/* Proses: Mengembalikan memori Q */
/* I.S. Q pernah dialokasi */
/* F.S. Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/* *** Primitif Add/Delete *** */
void Enqueue (PrioQueueTime * Q, infotype X){
    if (IsEmpty(*Q)){
        Head(*Q)=0;
        Tail(*Q)=0;
        InfoHead(*Q)=X;
    }
    else{
        Tail(*Q) = (Tail(*Q)+1)%MaxEl(*Q);
        InfoTail(*Q)=X;

        //sort
        int len=NBElmt(*Q);
        int i;
        int current, next;
        infotype temp;
        for(i=0;i<len-1;i++){
            current = Tail(*Q) - i;
            current = (current<0)? current+MaxEl(*Q) : current;

            next = current - 1;
            next = (next<0)? next+MaxEl(*Q) : next;

            if(Time(Elmt(*Q,current)) < Time(Elmt(*Q,next))){
                temp = Elmt(*Q,current);
                Elmt(*Q,current) = Elmt(*Q,next);
                Elmt(*Q,next) = temp;
            }
        }
    }
};
/* Proses: Menambahkan X pada Q dengan aturan priority queue, terurut membesar berdasarkan time */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X disisipkan pada posisi yang tepat sesuai dengan prioritas,
        TAIL "maju" dengan mekanisme circular buffer; */
void Dequeue (PrioQueueTime * Q, infotype * X){
    *X = InfoHead(*Q);
    if(NBElmt(*Q)==1){
        Head(*Q)=Nil;
        Tail(*Q)=Nil;
    }
    else{
        Head(*Q) = (Head(*Q)+1)%(MaxEl(*Q));
    }
};
/* Proses: Menghapus X pada Q dengan aturan FIFO */
/* I.S. Q tidak mungkin kosong */
/* F.S. X = nilai elemen HEAD pd I.S., HEAD "maju" dengan mekanisme circular buffer;
        Q mungkin kosong */

/* Operasi Tambahan */
void PrintPrioQueueTime (PrioQueueTime Q){
    if(!IsEmpty(Q)){
        int i;
        if(Head(Q)<=Tail(Q)){
            i=Head(Q);
            while(i<=Tail(Q)){
                printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
                i++;
            }
        }
        else{
            i=Head(Q);
            while(i<MaxEl(Q)){
                printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
                i++;
            }
            i=0;
            while(i<=Tail(Q)){
                printf("%d %c\n", Time(Elmt(Q,i)), Info(Elmt(Q,i)));
                i++;
            }
        }
    }
    printf("#\n");
};
/* Mencetak isi queue Q ke layar */
/* I.S. Q terdefinisi, mungkin kosong */
/* F.S. Q tercetak ke layar dengan format:
<time-1> <elemen-1>
...
<time-n> <elemen-n>
#
*/
