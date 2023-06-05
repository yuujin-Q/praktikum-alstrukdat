/*NIM : 13521074
* Nama : Eugene Yap Jin Quan
* Tanggal : 23/10/2022
* Topik praktikum : ADT Linked List
* Deskripsi : listlinier.c
*/

#include <stdio.h>
#include <stdlib.h>
#include "listlinier.h"


// /* Definisi Node : */
// typedef int ElType;
// typedef struct node* Address;
// typedef struct node {
//     ElType info;
//     Address next;
// } Node;

// #define INFO(p) (p)->info
// #define NEXT(p) (p)->next

Address newNode(ElType val){
    Address p = malloc(sizeof(Node));
    if (p != NULL){
        INFO(p)=val;
        NEXT(p)=NULL;
    }
    return p;
};

// /* Definisi List : */
// /* List kosong : FIRST(l) = NULL */
// /* Setiap elemen dengan Address p dapat diacu INFO(p), NEXT(p) */
// /* Elemen terakhir list: jika addressnya Last, maka NEXT(Last)=NULL */

// typedef Address List;

// #define IDX_UNDEF (-1)
// #define FIRST(l) (l)

/* PROTOTYPE */
/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    *l = NULL;
};
/* I.S. sembarang             */
/* F.S. Terbentuk list kosong */

/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return (FIRST(l)==NULL);
};
/* Mengirim true jika list kosong */

/****************** GETTER SETTER ******************/
ElType getElmt(List l, int idx){
    int current = 0;
    Address p = l;
    while (current<idx){
        current++;
        p = NEXT(p);
    }
    return INFO(p);
};
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengembalikan nilai elemen l pada indeks idx */

void setElmt(List *l, int idx, ElType val){
    int current = 0;
    Address p = *l;
    while (current<idx){
        current++;
        p = NEXT(p);
    }
    INFO(p)=val;
};
/* I.S. l terdefinisi, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Mengubah elemen l pada indeks ke-idx menjadi val */

int indexOf(List l, ElType val){
    int foundIn = IDX_UNDEF;
    Address p = l;
    int idx = 0;
    while (foundIn==IDX_UNDEF && p!=NULL){
        if (INFO(p)==val){
            foundIn = idx; 
        }
        else{
            idx++;
            p = NEXT(p);
        }
    }
    return foundIn;
};
/* I.S. l, val terdefinisi */
/* F.S. Mencari apakah ada elemen list l yang bernilai val */
/* Jika ada, mengembalikan indeks elemen pertama l yang bernilai val */
/* Mengembalikan IDX_UNDEF jika tidak ditemukan */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address p = newNode(val);
    if (p!=NULL){
        NEXT(p) = *l;
        *l = p;
    }
};
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil. */
/* Jika alokasi gagal: I.S.= F.S. */

void insertLast(List *l, ElType val){
    if (isEmpty(*l)){
        insertFirst(l, val);
    }
    else{
        Address new = newNode(val);
        if (new!=NULL){
            Address last = *l;
            while (NEXT(last)!=NULL){
                last = NEXT(last);
            }
            NEXT(last) = new;
        }
    }
};
/* I.S. l mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

void insertAt(List *l, ElType val, int idx){
    if (idx==0){
        insertFirst(l, val);
    }
    else{
        Address new = newNode(val);
        if (new!=NULL){
            int current=0;
            Address insert = *l;
            while (current<idx-1){
                current++;
                insert = NEXT(insert);
            }
            NEXT(new) = NEXT(insert);
            NEXT(insert) = new;
        }
    }
};



/* I.S. l tidak mungkin kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menyisipkan elemen dalam list pada indeks ke-idx (bukan menimpa elemen di i) */
/* yang bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType *val){
    Address p = *l;
    *val = INFO(p);
    *l = NEXT(p);
    free(p);
};
/* I.S. List l tidak kosong  */
/* F.S. Elemen pertama list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen pertama di-dealokasi */
void deleteLast(List *l, ElType *val){
    Address last = *l;
    Address beforeLast = NULL;
    while (NEXT(last)!=NULL){   /*set last to correct position*/
        beforeLast = last;
        last = NEXT(last);
    }

    if (beforeLast == NULL){
        *l = NULL;
    }
    else{
        NEXT(beforeLast)=NULL;
    }
    *val = INFO(last);
    free(last);
};
/* I.S. list tidak kosong */
/* F.S. Elemen terakhir list dihapus: nilai info disimpan pada x */
/*      dan alamat elemen terakhir di-dealokasi */

void deleteAt(List *l, int idx, ElType *val){
    if (idx==0){
        deleteFirst(l,val);
    }
    else{
        int currentpos=0;
        Address at = *l;
        Address beforeAt = NULL;
        while (currentpos<idx){ /*set "at" to correct idx*/
            currentpos++;
            beforeAt = at;
            at = NEXT(at);
        }
        *val = INFO(at);
        NEXT(beforeAt) = NEXT(at);
        free(at);
    }
};
/* I.S. list tidak kosong, idx indeks yang valid dalam l, yaitu 0..length(l) */
/* F.S. val diset dengan elemen l pada indeks ke-idx. */
/*      Elemen l pada indeks ke-idx dihapus dari l */


/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    Address p = l;
    putchar('[');
    while (p!=NULL){
        printf("%d", INFO(p));
        p = NEXT(p);
        if (p!=NULL){
            putchar(',');
        }
    }
    putchar(']');
};
// void printInfo(List l);
/* I.S. List mungkin kosong */
/* F.S. Jika list tidak kosong, iai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */

int length(List l){
    int count=0;
    Address p=l;
    while (p!=NULL){
        count++;
        p = NEXT(p);
    }
    return count;
};
/* Mengirimkan banyaknya elemen list; mengirimkan 0 jika list kosong */

/****************** PROSES TERHADAP LIST ******************/
List concat(List l1, List l2){
    List l3;
    CreateList(&l3);
    Address p;
    int val;
    p = l1;
    while (p!=NULL){
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    p = l2;
    while (p!=NULL){
        insertLast(&l3,INFO(p));
        p = NEXT(p);
    }
    return l3;
};
/* I.S. l1 dan l2 sembarang */
/* F.S. l1 dan l2 kosong, l3 adalah hasil konkatenasi l1 & l2 */
/* Konkatenasi dua buah list : l1 dan l2    */
/* menghasilkan l3 yang baru (dengan elemen list l1 dan l2 secara beurutan). */
/* Tidak ada alokasi/dealokasi pada prosedur ini */