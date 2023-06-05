#include <stdio.h>
#include "queuelinked.h"

boolean isElHomogen(Queue q){
	if(length(q) == 1){
		return true;
	}else{
		boolean sama;
		sama = true;
		Address p;
		p = ADDR_HEAD(q);
		while(p != ADDR_TAIL(q)){
			if(INFO(p) != HEAD(q)){
				sama = false;
			}
			p = NEXT(p);
		}
		if(INFO(p) != HEAD(q)){
			sama = false;
		}
		return sama;
	}
} 


int main(){
	Queue q1,q2,nm;
	char c;
	int i;
	
	CreateQueue(&q1);
	CreateQueue(&q2);
	CreateQueue(&nm);
	
	i = 0;
	scanf("%c", &c);
	while(c != ','){ // bulat 0, kotak 1
		if(c == 'K'){
			enqueue(&q1, 1);
		}else if(c == 'B'){
			enqueue(&q1, 0);
		}
		enqueue(&nm, i+1);
		scanf("%c", &c);
		i++;
	}
	
	scanf("%c", &c);
	while(c != '.'){ // bulat 0, kotak 1
		if(c == 'K'){
			enqueue(&q2, 1);
		}else if(c == 'B'){
			enqueue(&q2, 0);
		}
		scanf("%c", &c);
	}
	
	while(!isEmpty(q1) && !(isElHomogen(q1) && !isElHomogen(q2) && HEAD(q1) != HEAD(q2)) && !(isElHomogen(q1) && isElHomogen(q2) && HEAD(q1) != HEAD(q2))){	
		if(HEAD(q1) == HEAD(q2)){
			int no, val;
			dequeue(&q1, &val);
			dequeue(&q2, &val);
			dequeue(&nm, &no);
			if(val == 1){
				printf("%d -> kotak\n", no);
			}else{
				printf("%d -> bulat\n", no);
			}
		}else{
			int no, val;
			dequeue(&q1, &val);
			dequeue(&nm, &no);
			enqueue(&q1, val);
			enqueue(&nm, no);
		}
	}
	printf("%d\n", length(q1));
	return 0;
}
