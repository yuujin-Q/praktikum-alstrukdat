/**
 * NIM : 13521074
 * Nama : Eugene Yap Jin Quan
 * Tanggal : 2022-11-17
 * Topik praktikum : ADT List Rekursif
 * Deskripsi : reverse.c
 */

#include <stdio.h>
#include "listrec.h"

void displayListInline(List l) {
    if (!isEmpty(l)) {
        printf("%d", head(l));
        if (!isEmpty(tail(l))) {
			printf(" ");
		}
        displayListInline(tail(l));
    }
}

List inverseList (List l) {
	if (isEmpty(l)) {
		return l;
	} else {
		List result = konsb(inverseList(tail(l)), head(l));
		if (length(result) != length(l)) {
			return NIL;
		} else {
			return result;
		}
	}
}

void takeKHeads(List l, int K, List *result) {
		if (!isEmpty(l) && K > 0) {
			*result = konsb(*result, head(l));
			takeKHeads(tail(l), K-1, result);
		}
}

void shuffle(List l, int partsize, int idx) {
		if (!isEmpty(l)) {
			if (idx == 0) {
				List partition = NIL;
				List invert = NIL;
				takeKHeads(l, partsize, &partition);
				invert = inverseList(partition);
				
				displayListInline(invert);
				if (length(l) - partsize > 0) {
					printf(" ");
				}
				
				shuffle(tail(l), partsize, partsize-1);
			} else {
				shuffle(tail(l), partsize, idx-1);
			}
		}	
}

int main() {
		/* panjang baris, ukuran partisi */
		int N, K;
		List l = NIL;
		
		scanf("%d %d", &N, &K);
		int i, mhs;
		for (i = 0; i < N; i++) {
			scanf("%d", &mhs);
			l = konsb(l, mhs);
		}
		shuffle(l, K, 0);
		putchar('\n');
		return 0;
}
