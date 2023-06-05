/*
    NIM : 13521074
    Nama : Eugene Yap Jin Quan
    Tanggal: 23/09/2022
    Topik praktikum : ADT Matrix
    Deskripsi: submatrix.c
*/

#include <stdio.h>
#include "matrix.h"

int main(){
	int N,M;
	Matrix mat;
	scanf("%d %d", &N, &M);
	readMatrix(&mat, N, N);
	
	int jumlahdaerah = (N-M+1)*(N-M+1);
	Matrix nonZeroCount;
	createMatrix(1, jumlahdaerah+1, &nonZeroCount);
	int h;
	for (h=0;h<jumlahdaerah+1;h++){
		ELMT(nonZeroCount,0,h)=0;
	}
	
	int i,j;
	int k,l;
	for (i=0; i<N-M+1; i++){
		for (j=0; j<N-M+1;j++){
			// submatrix
			int idxdaerah = ((N-M+1)*i+j+1);
			for (k=0; k<M;k++){
				for (l=0; l<M; l++){
					if (ELMT(mat, i+k, j+l)!=0){
						ELMT(nonZeroCount,0,idxdaerah)++;
					}
				}
			}
		}
	}
	
	int max, min;
	MinMaxRow(nonZeroCount, 0, &max, &min);
	
	for (i=1; i<jumlahdaerah+1; i++){
		if (ELMT(nonZeroCount,0,i)==max){
			printf("%d\n", i);
			break;
		}
	}
	
	
	return 0;
}
