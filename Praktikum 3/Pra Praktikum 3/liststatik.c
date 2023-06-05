/*
NIM : 13521074
Nama : Eugene Yap Jin Quan
Tanggal : 11/09/2022
Topik praktikum : ADT List Statik dan Dinamik
Deskripsi : body ADT list statik (liststatik.c)
*/

#include <stdio.h>
#include "liststatik.h"

/* ********** KONSTRUKTOR ********** */
/* Konstruktor : create List kosong  */
void CreateListStatik(ListStatik *l){
   IdxType i;
   for (i=IDX_MIN;i<CAPACITY;i++){
      ELMT(*l, i) = MARK;
   }
};
/* I.S. l sembarang */
/* F.S. Terbentuk List l kosong dengan kapasitas CAPACITY */
/* Proses: Inisialisasi semua elemen List l dengan MARK */

/* ********** SELEKTOR (TAMBAHAN) ********** */
/* *** Banyaknya elemen *** */
int listLength(ListStatik l){
   int i=0;
   while (ELMT(l,i)!=MARK && i<CAPACITY){
      i++;
   }
   return i;
};
/* Mengirimkan banyaknya elemen efektif List */
/* Mengirimkan nol jika List kosong */  

/* *** Selektor INDEKS *** */
IdxType getFirstIdx(ListStatik l){
   return IDX_MIN;
};
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l pertama */
IdxType getLastIdx(ListStatik l){
   return listLength(l) - 1;
};
/* Prekondisi : List l tidak kosong */
/* Mengirimkan indeks elemen l terakhir */

/* ********** Test Indeks yang valid ********** */
boolean isIdxValid(ListStatik l, IdxType i){
   return (IDX_MIN<=i && i<CAPACITY);
};
/* Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l */
/* yaitu antara indeks yang terdefinisi utk container*/
boolean isIdxEff(ListStatik l, IdxType i){
   return (IDX_MIN<=i && i<listLength(l));
};
/* Mengirimkan true jika i adalah indeks yang terdefinisi utk List l */
/* yaitu antara 0..length(l)-1 */

/* ********** TEST KOSONG/PENUH ********** */
/* *** Test List kosong *** */
boolean isEmpty(ListStatik l){
   return (listLength(l) == 0);
};
/* Mengirimkan true jika List l kosong, mengirimkan false jika tidak */
/* *** Test List penuh *** */
boolean isFull(ListStatik l){
   return (listLength(l) == CAPACITY);
};
/* Mengirimkan true jika List l penuh, mengirimkan false jika tidak */

/* ********** BACA dan TULIS dengan INPUT/OUTPUT device ********** */
/* *** Mendefinisikan isi List dari pembacaan *** */
void readList(ListStatik *l){
   int n;
   do{
      scanf("%d", &n);
   }while (n<0 || n>CAPACITY);
   CreateListStatik(l);
   IdxType i;
   for (i=IDX_MIN;i<n;i++){
      scanf("%d", &ELMT(*l,i));
   }
};
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali: 
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printList(ListStatik l){
   int i;
   int j = getLastIdx(l);
   putchar('[');
   for (i=getFirstIdx(l); i<=j; i++){
      printf("%d", ELMT(l,i));
      if (i<j){
         putchar(',');
      }
   }
   putchar(']');
};
/* Proses : Menuliskan isi List dengan traversal, List ditulis di antara kurung 
   siku; antara dua elemen dipisahkan dengan separator "koma", tanpa tambahan 
   karakter di depan, di tengah, atau di belakang, termasuk spasi dan enter */
/* I.S. l boleh kosong */
/* F.S. Jika l tidak kosong: [e1,e2,...,en] */
/* Contoh : jika ada tiga elemen bernilai 1, 20, 30 akan dicetak: [1,20,30] */
/* Jika List kosong : menulis [] */

/* ********** OPERATOR ARITMATIKA ********** */
/* *** Aritmatika List : Penjumlahan, pengurangan, perkalian, ... *** */
ListStatik plusMinusList(ListStatik l1, ListStatik l2, boolean plus){
   int operand, i;
   operand = (plus == true) ? 1 : -1;
   for (i=IDX_MIN;i<listLength(l1);i++){
      ELMT(l1,i) += (operand * ELMT(l2,i));
   }
   return l1;
};
/* Prekondisi : l1 dan l2 berukuran sama dan tidak kosong */
/* Jika plus = true, mengirimkan  l1+l2, yaitu setiap elemen l1 dan l2 pada 
       indeks yang sama dijumlahkan */
/* Jika plus = false, mengirimkan l1-l2, yaitu setiap elemen l1 dikurangi 
       elemen l2 pada indeks yang sama */

/* ********** OPERATOR RELASIONAL ********** */
/* *** Operasi pembandingan List: *** */
boolean isListEqual(ListStatik l1, ListStatik l2){
   if (listLength(l1) == listLength(l2)){
      int i=IDX_MIN;
      boolean equal = true;
      while (i<listLength(l1) && equal)
      {
         if (ELMT(l1, i) != ELMT(l2,i))
         {
            equal = false;
         }
         i++;
      }
      return equal;
   }
   else{
      return false;
   }
};
/* Mengirimkan true jika l1 sama dengan l2 yaitu jika ukuran l1 = l2 dan semua 
   elemennya sama */

/* ********** SEARCHING ********** */
/* ***  Perhatian : List boleh kosong!! *** */
int indexOf(ListStatik l, ElType val){
   if (isEmpty(l))
   {
      return IDX_UNDEF;
   }
   else{
      int i = IDX_MIN;
      while (ELMT(l,i) != val && i<=getLastIdx(l)){
         i++;
      }
      if (i>getLastIdx(l)){
         return IDX_UNDEF;
      }
      else{
         return i;
      }
   }
   
};
/* Search apakah ada elemen List l yang bernilai val */
/* Jika ada, menghasilkan indeks i terkecil, dengan ELMT(l,i) = val */
/* Jika tidak ada atau jika l kosong, mengirimkan IDX_UNDEF */
/* Skema Searching yang digunakan bebas */

/* ********** NILAI EKSTREM ********** */
void extremeValues(ListStatik l, ElType *max, ElType *min){
   *max = ELMT(l, getFirstIdx(l));
   *min = ELMT(l, getFirstIdx(l));
   int i;
   for (i = IDX_MIN; i <= getLastIdx(l); i++)
   {
      if (ELMT(l,i) < *min)
      {
         *min = ELMT(l,i);
      }
      if (ELMT(l,i) > *max)
      {
         *max = ELMT(l,i);
      }  
   }  
};
/* I.S. List l tidak kosong */
/* F.S. Max berisi nilai terbesar dalam l;
        Min berisi nilai terkecil dalam l */

/* ********** MENAMBAH ELEMEN ********** */
/* *** Menambahkan elemen terakhir *** */
void insertFirst(ListStatik *l, ElType val){
   if (isEmpty(*l)){
      ELMT(*l, IDX_MIN) = val;
   }
   else if (!isFull(*l)){
      int i;
      for (i = getLastIdx(*l) + 1; i>IDX_MIN; i--)
      {
         ELMT(*l, i) = ELMT(*l, i-1);
      }
      ELMT(*l, IDX_MIN) = val;
   }
};
/* Proses: Menambahkan val sebagai elemen pertama List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen pertama l yang baru */
/* *** Menambahkan elemen pada index tertentu *** */
void insertAt(ListStatik *l, ElType val, IdxType idx){
   if (!isFull(*l) && !isEmpty(*l)) {
      int i;
      for (i = getLastIdx(*l) + 1; i>idx; i--)
      {
         ELMT(*l, i) = ELMT(*l, i-1);
      }
      ELMT(*l, idx) = val;
   }
};
/* Proses: Menambahkan val sebagai elemen pada index idx List */
/* I.S. List l tidak kosong dan tidak penuh, idx merupakan index yang valid di l */
/* F.S. val adalah elemen yang disisipkan pada index idx l */
/* *** Menambahkan elemen terakhir *** */
void insertLast(ListStatik *l, ElType val){
   if (isEmpty(*l)) {
      ELMT(*l, IDX_MIN) = val;
   }
   else if (!isFull(*l)) {
      ELMT(*l, getLastIdx(*l)+1) = val;
   }
};
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

/* ********** MENGHAPUS ELEMEN ********** */
/* *** Menghapus elemen pertama *** */
void deleteFirst(ListStatik *l, ElType *val){
   int len = listLength(*l);
   *val = ELMT(*l, getFirstIdx(*l));
   ELMT(*l, getFirstIdx(*l)) = MARK;
   if (len-1>0){
      IdxType i;
      for (i = IDX_MIN; i < len-1; i++)
      {
         ELMT(*l, i) = ELMT(*l, i+1);
      }
      ELMT(*l, len-1) = MARK;
   }
};
/* Proses : Menghapus elemen pertama List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen pertama l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen pada index tertentu *** */
void deleteAt(ListStatik *l, ElType *val, IdxType idx){
   int len = listLength(*l);
   *val = ELMT(*l, idx);
   ELMT(*l, idx) = MARK;
   if (len-1>0){
      IdxType i;
      for (i = idx; i < len-1; i++)
      {
         ELMT(*l, i) = ELMT(*l, i+1);
      }
      ELMT(*l, len-1) = MARK;
   }
};
/* Proses : Menghapus elemen pada index idx List */
/* I.S. List tidak kosong, idx adalah index yang valid di l */
/* F.S. val adalah nilai elemen pada index idx l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */
/* *** Menghapus elemen terakhir *** */
void deleteLast(ListStatik *l, ElType *val){
   *val = ELMT(*l, getLastIdx(*l));
   ELMT(*l, getLastIdx(*l)) = MARK;
};
/* Proses : Menghapus elemen terakhir List */
/* I.S. List tidak kosong */
/* F.S. val adalah nilai elemen terakhir l sebelum penghapusan, */
/*      Banyaknya elemen List berkurang satu */
/*      List l mungkin menjadi kosong */

/* ********** SORTING ********** */
void sortList(ListStatik *l, boolean asc){
   int len = listLength(*l);
   if (len > 1){
      int i,j;
      ElType temp;
      IdxType sortidx;
      for (i = IDX_MIN; i < len; i++)
      {
         sortidx = i;
         for (j = i+1; j < len; j++){
            if (ELMT(*l, j)<ELMT(*l, sortidx)){
               sortidx = j;
            }
         }
         if(sortidx != i){
            temp = ELMT(*l,i);
            ELMT(*l,i) = ELMT(*l,sortidx);
            ELMT(*l,sortidx) = temp;
         }
      }

      if (asc == false){
         for (i = IDX_MIN; i < len/2; i++)
         {
            temp = ELMT(*l,i);
            ELMT(*l,i) = ELMT(*l,(len-1)-i);
            ELMT(*l,(len-1)-i) = temp;
         }  
      }
   }
};
/* I.S. l boleh kosong */
/* F.S. Jika asc = true, l terurut membesar */
/*      Jika asc = false, l terurut mengecil */
/* Proses : Mengurutkan l dengan salah satu algoritma sorting,
   algoritma bebas */
