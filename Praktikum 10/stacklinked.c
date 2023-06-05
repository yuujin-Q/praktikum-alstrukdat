/**
 * NIM : 13521074
 * Nama : Eugene Yap Jin Quan
 * Tanggal : 2022-11-06
 * Topik praktikum : Queue dan Stack dengan struktur berkait
 * Deskripsi : stacklinked.c
 */

#include <stdio.h>
#include "stacklinked.h"

/*
#define NIL NULL
typedef int ElType;
typedef struct node* Address;
typedef struct node { 
    ElType info;
    Address next; 
} Node; 
typedef struct { 
    Address addrTop;    alamat Top: elemen puncak
} Stack;
*/

/* Selektor */
/*
#define     NEXT(p) (p)->next
#define     INFO(p) (p)->info
#define ADDR_TOP(s) (s).addrTop
#define      TOP(s) (s).addrTop->info 
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
   atau 
   NULL jika alokasi gagal */   

/* ********* PROTOTYPE REPRESENTASI LOJIK STACK ***************/
boolean isEmpty(Stack s) {
    return ADDR_TOP(s) == NIL;
}
/* Mengirim true jika Stack kosong: TOP(s) = NIL */

int length(Stack s) {
    if (isEmpty(s)) {
        return 0;
    } else {
        Address p = ADDR_TOP(s);
        int len = 0;
        while (p != NIL) {
            p = NEXT(p);
            len++;
        }
        return len;
    }
}
/* Mengirimkan banyaknya elemen stack. Mengirimkan 0 jika Stack s kosong */

void CreateStack(Stack *s) {
    ADDR_TOP(*s) = NIL;
}
/* I.S. sembarang */ 
/* F.S. Membuat sebuah stack s yang kosong */

void DisplayStack(Stack s) {
    putchar('[');
    if (!isEmpty(s)) {
        Address p = ADDR_TOP(s);
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
/* Proses : Menuliskan isi Stack, ditulis di antara kurung siku; antara dua elemen 
    dipisahkan dengan separator "koma", tanpa tambahan karakter di depan, di tengah, 
    atau di belakang, termasuk spasi dan enter */
/* I.S. s boleh kosong */
/* F.S. Jika s tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika Stack kosong : menulis [] */

void push(Stack *s, ElType x) {
    Address p = newNode(x);
    if (p != NIL) {
        NEXT(p) = ADDR_TOP(*s);
        ADDR_TOP(*s) = p;
    }
}
/* Menambahkan x sebagai elemen Stack s */
/* I.S. s mungkin kosong, x terdefinisi */
/* F.S. x menjadi Top yang baru jika alokasi x berhasil, */
/*      jika tidak, s tetap */
/* Pada dasarnya adalah operasi insertFirst pada list linier */

void pop(Stack *s, ElType *x) {
    *x = TOP(*s);
    Address p = ADDR_TOP(*s);
    ADDR_TOP(*s) = NEXT(ADDR_TOP(*s));
    NEXT(p) = NIL;
    free(p);
}
/* Menghapus Top dari Stack s */
/* I.S. s tidak kosong */
/* F.S. x adalah nilai elemen Top yang lama, */
/*      elemen Top yang lama didealokasi */
/* Pada dasarnya adalah operasi deleteFirst pada list linier */
