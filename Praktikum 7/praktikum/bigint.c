/*
NIM: 13521074
Nama: Eugene Yap Jin Quan 
Tanggal: 20/10/2022
Topik praktikum: ADT Stack
Deskripsi: bigint.c
*/

#include <stdio.h>
#include "stack.h"

int toDigit(char c){
	return (int)c - 48;
}

void digitSubs(Stack * S1, Stack * S2, Stack * result){	//S1-S2
	int x, x1, x2;
	int carry=0;
	while(!IsEmpty(*S1) && !IsEmpty(*S2)){
		Pop(S1, &x1);
		Pop(S2, &x2);
		x = x1-x2-carry;
		if(x<0){
			carry=1;
			x+=10;
		}
		else{
			carry=0;
		}
		Push(result,x);
	}
	while (!IsEmpty(*S1)){
		Pop(S1, &x1);
		x = x1-carry;
		if(x<0){
			carry=1;
			x+=10;
		}
		else{
			carry=0;
		}
		Push(result,x);
	}
}

void inputBigNum(Stack * S, int * count){
	char c;
	*count=0;
	scanf("%c", &c);
	boolean leadzero=true;
	while (c!='\n'){
		if (c>='0' && c<='9'){
			if (leadzero && c!='0'){
				leadzero=false;
			}
			if (!leadzero){
				Push(S, toDigit(c));
				*count += 1;
			}
		}
		scanf("%c", &c);
	}
	if (*count==0 && c=='\n'){
		Push(S, 0);
		*count += 1;
	}
}

boolean isLarger(Stack revS1, Stack revS2){
	boolean gt=true; //S1>=S2
	int x1,x2;
	Stack S1,S2;
	CreateEmpty(&S1);
	CreateEmpty(&S2);
	while(!IsEmpty(revS1)){
		Pop(&revS1,&x1);
		Push(&S1, x1);
	}
	while(!IsEmpty(revS2)){
		Pop(&revS2,&x2);
		Push(&S2, x2);
	}

	while(!IsEmpty(S1) && !IsEmpty(S2)){
		Pop(&S1,&x1);
		Pop(&S2,&x2);

		if(x1==x2){
			continue;
		}
		else if(x1>x2){
			gt=true;
			break;
		}
		else{
			gt=false;
			break;
		}
	}
	return gt;
}

int main(){
	Stack S1, S2, result;
	CreateEmpty(&S1);
	CreateEmpty(&S2);
	CreateEmpty(&result);
	
	int count1, count2;
	int signn;
	boolean gt;	//s1>=s2
	inputBigNum(&S1, &count1);
	inputBigNum(&S2, &count2);

	// find larger
	if(count1<count2){
		gt=false;
	}
	else if(count1>count2){
		gt=true;
	}
	else{
		gt = isLarger(S1,S2);
	}


	if(!gt){	//s1<s2 then -1* (s2-s1)
		signn=-1;
		digitSubs(&S2,&S1,&result);
	}
	else{		//s1>=s2 then s1-s2
		signn=1;
		digitSubs(&S1,&S2,&result);
	}

	int res=0;
	while(!IsEmpty(result) && res==0){	//remove leading zero
		Pop(&result, &res);
	}
	printf("%d", signn*res);	// add signn (+/-)
	while(!IsEmpty(result)){
		Pop(&result, &res);
		printf("%d", res);
	}
	printf("\n");
	
	return 0;
}
