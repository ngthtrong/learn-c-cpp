#include"astacklib.h"

int C(int k, int n){
	Stack K, N;
	int a, b, c = 0;
	makeNULL(&K);
	makeNULL(&N);
	push(k, &K);
	push(n, &N);
	
	while(isEmpty(K) == 0 && isEmpty(N) == 0){
		a = pop(&K); 
		b = pop(&N);
		
		if(a == b || a == 0){
			c = c + 1;
		}
		else if(a == 1){
			c = c + b;
		}
		else{
			push(a-1, &K);
			push(b-1, &N);
			
			push(a, &K);
			push(b-1, &N);
		} 
	}
	return c;
}

int main(){
	int k, n, c;
	printf("To hop chap k cua n\n");
	printf("k = ");
	scanf("%d", &k);
	printf("n = ");
	scanf("%d", &n);
	c = C(k , n);
	printf("To hop chap %d cua %d la: %d", k, n, c);
	return 0; 
}


 
