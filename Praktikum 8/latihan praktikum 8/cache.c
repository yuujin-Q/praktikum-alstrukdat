/*NIM : 13521074
* Nama : Eugene Yap Jin Quan
* Tanggal : 27/10/2022
* Topik praktikum : ADT Linked List
* Deskripsi : cache.c
*/


#include <stdio.h>
#include "listlinier.h"

int main(){
	int hit = 0;
	int miss = 0;
	int cap, opcap;
	
	scanf("%d", &cap);
	scanf("%d", &opcap);
	

	if (opcap == 0){
		printf("hit ratio: 0.00\n");
	}
	else{
		int len = 0;
		List cache;
		CreateList(&cache);
		
		int i, ops, val, idx;
		
		for (i = 0; i<opcap; i++){
			scanf("%d", &ops);
			if (cap==0){
				printf("miss []\n");
				miss++;
			}
			else{
				idx = indexOf(cache, ops);
				if (idx != IDX_UNDEF){
					deleteAt(&cache, idx, &val);
					insertFirst(&cache, val);
					
					printf("hit ");
					displayList(cache);
					putchar('\n');
					hit++;
				}
				else{	/* jika ops tidak ada di cache */
					if (!isEmpty(cache) && len==cap){
						deleteLast(&cache, &val);
					}
					insertFirst(&cache, ops);
					
					printf("miss ");
					displayList(cache);
					putchar('\n');
					miss++;
					
					if (len<cap){
						len++;
					}	
				}
			}
		}
		
		float ratio = (float)hit / (float)(hit + miss);
		printf("hit ratio: %.2f\n", ratio);
	}
	return 0;
}
