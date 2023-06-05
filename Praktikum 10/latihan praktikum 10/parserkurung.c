/**
 * NIM : 13521074
 * Nama : Eugene Yap Jin Quan
 * Tanggal : 2022-11-10
 * Topik praktikum : Queue dan Stack dengan struktur berkait
 * Deskripsi : parserkurung.c
 */

#include <stdio.h>
#include "charmachine.h"
#include "stacklinked.h"

int main() {
	Stack s;
	CreateStack(&s);
	int count[] = {0,0,0,0,0};
	int x;
	int maxlen = 0;
	boolean isValid = true;
	
	START();
	while (!EOP) {
		switch (currentChar) {
			case '[': {
				push(&s, 0);
				count[0]++;
				DisplayStack(s);
				putchar('\n');
				break;
			}
			case '(': {
				push(&s, 1);
				count[1]++;
				DisplayStack(s);
				putchar('\n');
				break;
			}
			case '|': {
				if (isEmpty(s)) {
					push(&s, 2);
					count[2]++;
				} else {
					if (TOP(s) == 2) {
						pop(&s, &x);
					} else {
						push(&s, 2);
						count[2]++;
					}
				}
				
				DisplayStack(s);
				putchar('\n');
				break;
			}
			case '{': {
				push(&s, 3);
				count[3]++;
				DisplayStack(s);
				putchar('\n');
				break;
			}
			case '<': {
				push(&s, 4);
				count[4]++;
				DisplayStack(s);
				putchar('\n');
				break;
			}
			
			case ']': {
				if (!isEmpty(s)) {
					if (TOP(s) == 0) {
						pop(&s, &x);
					} else {
						isValid = false;
					}
				} else {
					isValid = false;
				}
				DisplayStack(s);
				putchar('\n');
				break;
			}
			case ')': {
				if (!isEmpty(s)) {
					if (TOP(s) == 1) {
						pop(&s, &x);
					} else {
						isValid = false;
					}
				} else {
					isValid = false;
				}
				DisplayStack(s);
				putchar('\n');
				break;
			}
			case '}': {
				if (!isEmpty(s)) {
					if (TOP(s) == 3) {
						pop(&s, &x);
					} else {
						isValid = false;
					}
				} else {
					isValid = false;
				}
				DisplayStack(s);
				putchar('\n');
				
				break;
			}
			case '>': {
				if (!isEmpty(s)) {
					if (TOP(s) == 4) {
						pop(&s, &x);
					} else {
						isValid = false;
					}
				} else {
					isValid = false;
				}
				DisplayStack(s);
				putchar('\n');
				break;
			}
			
		}
		int len = length(s);
		if (len > maxlen) {
			maxlen = len;
		}
		ADV();
	}
		
	if (isEmpty(s) && isValid) {
		printf("kurung valid\n");
		printf("[%d] ", count[0]);
		printf("(%d) ", count[1]);
		printf("|%d| ", count[2]);
		printf("{%d} ", count[3]);
		printf("<%d>\n", count[4]);
		printf("MAX %d\n", maxlen);
	} else {
		printf("kurung tidak valid\n");
	}
	
	return 0;
}
