/**
 * NIM : 13521074
 * Nama : Eugene Yap Jin Quan
 * Tanggal : 2022-11-10
 * Topik praktikum : Queue dan Stack dengan struktur berkait
 * Deskripsi : butak.c
 */
 
#include <stdio.h>
#include "charmachine.h"
#include "queuelinked.h"

boolean isElHomogen(Queue q) {
	if (length(q) == 1) {
		return true;
	} else {
		Address p = ADDR_HEAD(q);
		boolean isHomo = true;

		while (p != ADDR_TAIL(q) && isHomo) {
			if (INFO(p) != HEAD(q)) {
				isHomo = false;
			} else {
				p =	NEXT(p);
			}
		}
		if (INFO(p) != HEAD(q)) {
			isHomo = false;
		}
		return isHomo;
	}
}


int main() {
	Queue mhs, pref, sand;
	CreateQueue(&mhs);
	CreateQueue(&pref);
	CreateQueue(&sand);
	
	START();
	int i = 1;
	while (currentChar != ',') {
		if (currentChar == 'B') {
			enqueue(&pref, 0);
		} else if (currentChar == 'K') {
			enqueue(&pref, 1);
		}
		enqueue(&mhs, i);
		i++;
		ADV();
	}
	while (currentChar != '.' && !EOP) {
		if (currentChar == 'B') {
			enqueue(&sand, 0);
		} else if (currentChar == 'K') {
			enqueue(&sand, 1);
		}
		ADV();
	}

	int noMhs, noSand, noPref;

	while (!isEmpty(pref) && !(isElHomogen(pref) && isElHomogen(sand) && HEAD(pref) != HEAD(sand)) && !(isElHomogen(pref) && !isElHomogen(sand) && HEAD(pref) != HEAD(sand))) {
		if (HEAD(pref) == HEAD(sand)) {
			dequeue(&mhs, &noMhs);
			dequeue(&sand, &noSand);
			dequeue(&pref, &noPref);
			
			if (noSand == 0) {
				printf("%d -> bulat\n", noMhs);				
			} else {
				printf("%d -> kotak\n", noMhs);				
			}
		} else {
			dequeue(&mhs, &noMhs);
			dequeue(&pref, &noPref);
			
			enqueue(&mhs, noMhs);
			enqueue(&pref, noPref);
		}
	}
	printf("%d\n", length(sand));

	return 0;
}
