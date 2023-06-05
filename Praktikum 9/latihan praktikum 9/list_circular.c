/**
 * NIM : 13521074
 * Nama : Eugene Yap Jin Quan
 * Tanggal : 2022-10-30
 * Topik praktikum : ADT Variasi List Linier
 * Deskripsi : list_circular.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "list_circular.h"

/* ADT List Sirkuler dengan elemen terakhir menunjuk pada elemen pertama */
/* Representasi berkait dengan Address adalah pointer */
/* ElType adalah integer */

/* ********* DEFINISI ADT **********
typedef int ElType;
typedef struct node *Address;
typedef struct node { 
	ElType info;
	Address next;
} ElmtList;
typedef struct {
	Address first;
} List;
*/

/* Definisi List Circular : */
/* List kosong : FIRST(l) = NULL */
/* Setiap elemen dengan Address P dapat diacu INFO(P), NEXT(P) */
/* Elemen terakhir list: jika Addressnya Last, maka NEXT(Last)=FIRST(l) */

/* Selektor */
#define INFO(P) (P)->info
#define NEXT(P) (P)->next
#define FIRST(l) ((l).first)

/* PROTOTYPE */
/****************** TEST LIST KOSONG ******************/
boolean isEmpty(List l){
    return (FIRST(l) == NULL);
}
/* Mengirim true jika list kosong. Lihat definisi di atas. */

/****************** PEMBUATAN LIST KOSONG ******************/
void CreateList(List *l){
    FIRST(*l) = NULL;
}
/* I.S. l sembarang             */
/* F.S. Terbentuk list kosong. Lihat definisi di atas. */

/****************** Manajemen Memori ******************/
Address allocate(ElType val){
    Address p = malloc(sizeof(ElmtList));
    if (p != NULL){
        INFO(p) = val;
        NEXT(p) = NULL;
    }
    return p;
}
/* Mengirimkan Address hasil alokasi sebuah elemen */
/* Jika alokasi berhasil, maka Address tidak NULL, dan misalnya */
/* menghasilkan P, maka INFO(P)=val, NEXT(P)=NULL */
/* Jika alokasi gagal, mengirimkan NULL */
void deallocate(Address P){
    free(P);
}
/* I.S. P terdefinisi */
/* F.S. P dikembalikan ke sistem */
/* Melakukan dealokasi/pengembalian Address P */

/****************** PENCARIAN SEBUAH ELEMEN LIST ******************/
Address search(List l, ElType val){
    if (isEmpty(l)){
        return NULL;
    }
    else{
        Address p = FIRST(l);
        while (NEXT(p) != FIRST(l) && INFO(p) != val){
            p = NEXT(p);
        }
        if (INFO(p) == val){
            return p;
        }
        else{
            return NULL;
        }
    }
}
/* Mencari apakah ada elemen list dengan INFO(P)= val */
/* Jika ada, mengirimkan Address elemen tersebut. */
/* Jika tidak ada, mengirimkan NULL */

boolean addrSearch(List l, Address p){
    if (isEmpty(l)){
        return false;
    }
    else{
        Address pt = FIRST(l);
        while (NEXT(pt) != FIRST(l) && (pt != p)){
            pt = NEXT(pt);
        } /* next == first or pt == p */
        return pt == p;
    }   
}
/* Mencari apakah ada elemen list l yang beralamat p */
/* Mengirimkan true jika ada, false jika tidak ada */

/****************** PRIMITIF BERDASARKAN NILAI ******************/
/*** PENAMBAHAN ELEMEN ***/
void insertFirst(List *l, ElType val){
    Address new = allocate(val);
    if (new != NULL){
        if (isEmpty(*l)){
            NEXT(new) = new;
        }
        else{
            Address last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)){    /* advance last to end of list */
                last = NEXT(last);
            } /* next(last) == first(*l) */
            NEXT(new) = FIRST(*l);
            NEXT(last) = new;
        }
        FIRST(*l) = new;
    }
}
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen pertama dengan nilai val jika alokasi berhasil */
/* Elemen terakhir list menunjuk ke address dari elemen pertama baru list */
void insertLast(List *l, ElType val){
    if (isEmpty(*l)){
        insertFirst(l, val);
    }
    else{
        Address new = allocate(val);
        if (new != NULL){
            Address last = FIRST(*l);
            while (NEXT(last) != FIRST(*l)){    /* advance last to end of list */
                last = NEXT(last);
            } /* next(last) == first(*l) */
            NEXT(last) = new;
            NEXT(new) = FIRST(*l);
        }
    }
}
/* I.S. List l terdefinisi, mungkin kosong */
/* F.S. Melakukan alokasi sebuah elemen dan */
/* menambahkan elemen list di akhir: elemen terakhir yang baru */
/* bernilai val jika alokasi berhasil. Jika alokasi gagal: I.S.= F.S. */
/* Elemen terakhir baru list menunjuk ke address dari elemen pertama list */

/*** PENGHAPUSAN ELEMEN ***/
void deleteFirst(List *l, ElType * val){
    *val = INFO(FIRST(*l));
    Address p = FIRST(*l);
    if (NEXT(FIRST(*l)) == FIRST(*l)){ /* len == 1 */
        FIRST(*l) = NULL;
    }
    else{
        Address last = FIRST(*l);
        while (NEXT(last) != FIRST(*l)){    /* advance last to end of list*/
            last = NEXT(last);
        } /* last points to end of list */
        FIRST(*l) = NEXT(FIRST(*l));
        NEXT(last) = FIRST(*l);
    }
    deallocate(p);
}
/* I.S. List l tidak kosong  */
/* F.S. val adalah elemen pertama List l sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      First element yg baru adalah suksesor elemen pertama yang lama */
/*      Jika list baru tidak kosong, Last element menunjuk ke First element baru */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen pertama list lama di-dealokasi */
void deleteLast(List *l, ElType * val){
    Address last = FIRST(*l);
    Address before_last = NULL;
    while (NEXT(last) != FIRST(*l)){    /* advance last to end of list*/
        before_last = last;
        last = NEXT(last);
    }   /* last points to end of list, before_last points to one element before end of list, or null */

    if (before_last == NULL){
        FIRST(*l) = NULL;
    }
    else{
        NEXT(before_last) = FIRST(*l);
    }
    *val = INFO(last);
    deallocate(last);
}
/* I.S. List l tidak kosong */
/* F.S. val adalah elemen terakhir list sebelum penghapusan */
/*      Elemen list berkurang satu (mungkin menjadi kosong) */
/*      Last element baru adalah predesesor elemen terakhir yg lama, jika ada */
/*      Jika list baru tidak kosong, Last element baru menunjuk ke First element */
/*      Jika list baru kosong, maka FIRST(*l) = NULL */
/*      Alamat elemen terakhir list lama di-dealokasi */

/****************** PROSES SEMUA ELEMEN LIST ******************/
void displayList(List l){
    putchar('[');
    if (!isEmpty(l)){
        Address p = FIRST(l);
        printf("%d", INFO(p));
        while (NEXT(p) != FIRST(l)){
            p = NEXT(p);
            printf(",%d", INFO(p));
        }
        
    }
    putchar(']');
}
/* I.S. List l mungkin kosong */
/* F.S. Jika list tidak kosong, nilai list dicetak ke kanan: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika list kosong : menulis [] */
/* Tidak ada tambahan karakter apa pun di awal, akhir, atau di tengah */
