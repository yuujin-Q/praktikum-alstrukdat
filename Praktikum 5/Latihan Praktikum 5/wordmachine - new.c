/*
NIM : 13521074
Nama : Eugene Yap Jin Quan
Tanggal : 26/09/2022
Topik praktikum : ADT Mesin Kata
Deskripsi : wordmachine.c
*/

#include <stdio.h>
#include "wordmachine.h"

boolean endWord;
Word currentWord;

void IgnoreBlanks(){
    while (currentChar == BLANK && currentChar != MARK){
        ADV();
    }
}
/* Mengabaikan satu atau beberapa BLANK
   I.S. : currentChar sembarang
   F.S. : currentChar ≠ BLANK atau currentChar = MARK */

void STARTWORD(){
    START();
    IgnoreBlanks();
    if (currentChar == MARK){
        endWord = true;
    }
    else{
        endWord = false;
        CopyWord();
    }
}
/* I.S. : currentChar sembarang
   F.S. : EndWord = true, dan currentChar = MARK;
          atau EndWord = false, currentWord adalah kata yang sudah diakuisisi,
          currentChar karakter pertama sesudah karakter terakhir kata */

void ADVWORD(){
    IgnoreBlanks();
    if (currentChar == MARK){
        endWord = true;
    }
    else{
        CopyWord();
        IgnoreBlanks();
    }
}
/* I.S. : currentChar adalah karakter pertama kata yang akan diakuisisi
   F.S. : currentWord adalah kata terakhir yang sudah diakuisisi,
          currentChar adalah karakter pertama dari kata berikutnya, mungkin MARK
          Jika currentChar = MARK, EndWord = true.
   Proses : Akuisisi kata menggunakan procedure SalinWord */

void CopyWord(){
    int i = 0;
    while (currentChar != BLANK && currentChar != MARK && i<NMax){
        currentWord.TabWord[i] = currentChar;
        ADV();
        i++;
    }
    currentWord.Length = i;
}
/* Mengakuisisi kata, menyimpan dalam currentWord
   I.S. : currentChar adalah karakter pertama dari kata
   F.S. : currentWord berisi kata yang sudah diakuisisi;
          currentChar = BLANK atau currentChar = MARK;
          currentChar adalah karakter sesudah karakter terakhir yang diakuisisi.
          Jika panjang kata melebihi NMax, maka sisa kata "dipotong" */



// LATIHAN PRAKTIKUM 03/10/2022
void LowerCase(){
    int i;
    for (i=0; i<currentWord.Length; i++){
        if ('A' <= currentWord.TabWord[i] && currentWord.TabWord[i] <= 'Z'){
            currentWord.TabWord[i] += ('a' - 'A');
        }
    }
};

/* I.S. currentword terdefinisi sembarang tetapi tidak kosong */

/* F.S. currentword menjadi lowercase di setiap karakternya */