/*
NIM : 13521074
Nama : Eugene Yap Jin Quan
Tanggal : 03/10/2022
Topik praktikum : ADT Mesin Kata
Deskripsi : str2num.c
*/

#include <stdio.h>
#include "wordmachine.h"

boolean sameString(char word[],int lenword, char comparator[], int lencomp){
    int minlen = (lenword<lencomp)? lenword : lencomp;
    int i;
    boolean isSame= (lenword==lencomp);
    if (isSame){
        for (i=0;i<minlen;i++){
            isSame = (word[i]==comparator[i]);
            if (!isSame){
                break;
            }
        }
    }
    return isSame;
};

int main(){
    int digit=0;
    int num=0;
    int len;
    boolean isNum; 
    boolean adaNol=false;
    STARTWORD();
    do {
        len = currentWord.Length;
        if (sameString(currentWord.TabWord, len, "satu", 4)){
            isNum = true;
            digit = 1;
        }
        else if (sameString(currentWord.TabWord, len, "dua", 3)){
            isNum = true;
            digit = 2;
        }
        else if (sameString(currentWord.TabWord, len, "tiga", 4)){
            isNum = true;
            digit = 3;
        }
        else if (sameString(currentWord.TabWord, len, "empat", 5)){
            isNum = true;
            digit = 4;
        }
        else if (sameString(currentWord.TabWord, len, "lima", 4)){
            isNum = true;
            digit = 5;
        }
        else if (sameString(currentWord.TabWord, len, "enam", 4)){
            isNum = true;
            digit = 6;
        }
        else if (sameString(currentWord.TabWord, len, "tujuh", 5)){
            isNum = true;
            digit = 7;
        }
        else if (sameString(currentWord.TabWord, len, "delapan", 7)){
            isNum = true;
            digit = 8;
        }
        else if (sameString(currentWord.TabWord, len, "sembilan", 8)){
            isNum = true;
            digit = 9;
        }
        else if (sameString(currentWord.TabWord, len, "puluh", 5)){
            isNum = true;
            num += digit*10;
            digit =0;
        }
        else if (sameString(currentWord.TabWord, len, "belas", 5)){
            isNum = true;
            num += digit+10;
            digit=0;
        }
        else if (sameString(currentWord.TabWord, len, "sepuluh", 7)){
            isNum = true;
            num += 10;
            digit = 0;
        }
        else if (sameString(currentWord.TabWord, len, "sebelas", 7)){
            isNum = true;
            num += 11;
            digit = 0;
        }
        else if (sameString(currentWord.TabWord, len, "ratus", 5)){
            isNum = true;
            num += digit*100;
            digit =0;
        }
        else if (sameString(currentWord.TabWord, len, "seratus", 7)){
            isNum = true;
            num += 100;
            digit = 0;
        }
        else if (isNum){
            num += digit;
            digit=0;
            printf("%d ", num);
            num = 0;
            isNum = false;
            int i;

            if (sameString(currentWord.TabWord, len, "nol", 3)){
                printf("0");
            }
            else{
                for(i=0;i<currentWord.Length;i++){
                    printf("%c", currentWord.TabWord[i]);
                }
            }
        }
        else{
            int i;
            num=0;
            digit=0;
            if (sameString(currentWord.TabWord, len, "nol", 3)){
                printf("0");
            }
            else{
                for(i=0;i<currentWord.Length;i++){
                    printf("%c", currentWord.TabWord[i]);
                }
            }
        }

        if(currentChar!=MARK && !isNum){
            putchar(' ');
        }

        ADVWORD();
    } while(!endWord);
    if (num!=0){
        printf("%d", num);
    }
    else if(digit!=0){
        printf("%d", digit);
    }
    
    putchar('\n');

    return 0;
}