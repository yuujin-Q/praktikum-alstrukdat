/**
 * NIM : 13521074
 * Nama : Eugene Yap Jin Quan
 * Tanggal : 2022-11-03
 * Topik praktikum : ADT Variasi List Linier
 * Deskripsi : pemainterakhir.c
 */

#include <stdio.h>
#include "list_circular.h"

int main() {
	int n, k;
	scanf("%d", &n);
	scanf("%d", &k);
	
	List players, elim_order;
	CreateList(&players);
	CreateList(&elim_order);
	
	int i;
	for (i = 1; i <= n; i++) {
		insertLast(&players, i);
	}
	
	Address p = FIRST(players);
	int counter = 0;
	int j = 0;
	ElType check;
	while (j < n) {
		check = INFO(p);
		
		if (search(elim_order, check) == NULL) {	/* Jika belum tereliminasi */ 
			
			counter++;
			if (counter == k) {
				insertLast(&elim_order, INFO(p));
				
				counter = 0;
				j++;
			}
		}
		
		p = NEXT(p); 
	}
	
	ElType val;
	while (!isEmpty(elim_order)) {
		deleteFirst(&elim_order, &val);
		if (isEmpty(elim_order)) {
			printf("Pemenang %d\n", val);
		} else {
			printf("%d\n", val);
		}
	}
	return 0;
}
