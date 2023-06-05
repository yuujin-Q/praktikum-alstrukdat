/*
NIM: 13521074
Nama: Eugene Yap Jin Quan 
Tanggal: 20/10/2022
Topik praktikum: ADT Stack
Deskripsi: ekspresi.c
*/

#include <stdio.h>
#include <math.h>
#include "stack.h"
#include "wordmachine.h"
#include "charmachine.h"

int toDigit(char c){
	return (int)c - 48;
}

int op(char cur, char ops){
	return !((int)cur - (int)ops);
}

int main(){
	STARTWORD();
	Stack result;
	CreateEmpty(&result);
	if(endWord){
		printf("Ekspresi kosong\n");
	}
	else{
		int i;
		int x=0, x1=0, x2=0;
		char cur;
		while(!endWord){
			cur = currentWord.TabWord[0];
			if (cur=='+' || cur=='-' || cur=='*' || cur=='/' || cur=='^'){
				Pop(&result, &x2);
				Pop(&result, &x1);
				x = (x1+x2)*op(cur,'+') + (x1-x2)*op(cur,'-') + (x1*x2)*op(cur,'*') + (x1/x2)*op(cur,'/') + ((int)pow(x1,x2))*op(cur,'^');
				printf("%d %c %d\n", x1, cur, x2);
				printf("%d\n", x);
				Push(&result, x);
				x=0;
			}
			else if(cur!=MARK){
				int len =currentWord.Length;
				for(i=0; i<len; i++){
					x+= (int)pow(10,(len-1)-i)*toDigit(currentWord.TabWord[i]);
				}
				printf("%d\n", x);
				Push(&result, x);
				x=0;
			}
			ADVWORD();
		}
			
		Pop(&result, &x);
		printf("Hasil=%d\n", x);
	}
		
	return 0;
}
