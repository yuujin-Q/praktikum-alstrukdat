/**
 * NIM : 13521074
 * Nama : Eugene Yap Jin Quan
 * Tanggal : 2022-11-06
 * Topik praktikum : Queue dan Stack dengan struktur berkait
 * Deskripsi : queuelinked.c
 */

#include <stdio.h>
#include "queuelinked.h"


/*
#define NIL NULL
typedef int ElType;
typedef struct node* Address;
typedef struct node { 
    ElType info;
    Address next; 
} Node; 
typedef struct {
    Address addrHead;  alamat penghapusan 
    Address addrTail;  alamat penambahan 
} Queue;
*/


/* Selektor */
/*
#define NEXT(p) (p)->next
#define INFO(p) (p)->info

#define ADDR_HEAD(q) (q).addrHead
#define ADDR_TAIL(q) (q).addrTail
#define      HEAD(q) (q).addrHead->info
*/



/* Prototype manajemen memori */
Address newNode(ElType x) {
    Address new = (Address) malloc(sizeof(Node));
    if (new != NIL) {
        INFO(new) = x;
        NEXT(new) = NIL;
    }
    return new;
}
/* Mengembalikan alamat sebuah Node hasil alokasi dengan info = x, 
   atau NIL jika alokasi gagal */
boolean isEmpty(Queue q) {
    return ADDR_HEAD(q) == NIL && ADDR_TAIL(q) == NIL;
}
/* Mengirim true jika q kosong: ADDR_HEAD(q)=NULL and ADDR_TAIL(q)=NULL */
int length(Queue q) {
    if (isEmpty(q)) {
        return 0;
    } else {
        int len = 0;
        Address p = ADDR_HEAD(q);
        while (p != NIL) {
            p = NEXT(p);
            len++;
        }
        return len;
    }
}
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika q kosong */

/*** Kreator ***/
void CreateQueue(Queue *q) {
    ADDR_HEAD(*q) = NIL;
    ADDR_TAIL(*q) = NIL;
}
/* I.S. sembarang */
/* F.S. Sebuah q kosong terbentuk */
void DisplayQueue(Queue q) {
    putchar('[');
    if (!isEmpty(q)) {
        Address p = ADDR_HEAD(q);
        while (p != NIL) {
            printf("%d", INFO(p));
            if (NEXT(p) != NIL) {
                putchar(',');
            }
            p = NEXT(p);
        }
    }
    putchar(']');
}
/* Proses : Menuliskan isi Queue, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. q boleh kosong */
/* F.S. Jika q tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Queue kosong : menulis [] */

/*** Primitif Enqueue/Dequeue ***/
void enqueue(Queue *q, ElType x) {
    Address p= newNode(x);
    if (p != NIL) {
        if (isEmpty(*q)) {
            ADDR_HEAD(*q) = p;
        } else {
            NEXT(ADDR_TAIL(*q)) = p;
        }
        ADDR_TAIL(*q) = p;
    }
}
/* Proses: Mengalokasi x dan menambahkan x pada bagian Tail dari q
           jika alokasi berhasil; jika alokasi gagal q tetap */
/* Pada dasarnya adalah proses insertLast */
/* I.S. q mungkin kosong */
/* F.S. x menjadi Tail, Tail "maju" */
void dequeue(Queue *q, ElType *x) {
    *x = HEAD(*q);
    Address p = ADDR_HEAD(*q);
    ADDR_HEAD(*q) = NEXT(ADDR_HEAD(*q));
    if (ADDR_HEAD(*q) == NIL) {
        ADDR_TAIL(*q) = NIL;
    }
    NEXT(p) = NIL;
    free(p);
}
/* Proses: Menghapus x pada bagian HEAD dari q dan mendealokasi elemen HEAD */
/* Pada dasarnya operasi deleteFirst */
/* I.S. q tidak mungkin kosong */
/* F.S. x = nilai elemen HEAD pd I.S., HEAD "mundur" */