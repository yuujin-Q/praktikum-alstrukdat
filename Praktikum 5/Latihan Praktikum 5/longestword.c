/*
NIM : 13521074
Nama : Eugene Yap Jin Quan
Tanggal : 03/10/2022
Topik praktikum : ADT Mesin Kata
Deskripsi : longestword.c
*/

#include "wordmachine.h"
#include <stdio.h>

int main(){
    STARTWORD();
    if (endWord){
        printf("%d\n", 0);
    }
    else{
        int max = currentWord.Length;
        while (!endWord)
        {
            ADVWORD();
            max = (currentWord.Length>max)? currentWord.Length : max;
        }
        printf("%d\n", max);
    }
    return 0;
}