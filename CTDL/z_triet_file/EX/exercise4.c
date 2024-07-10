#include"astacklib.h"

int Fibo(int n) {
	int i, k; 
    Stack S;
    makeNULL(&S);
	int tong = 0;
	
	push(n, &S); 
    while(isEmpty(S) == 0){
    	k = pop(&S);	
		if(k == 1 || k == 2){
			tong +=1;
		}
		else{
			push(k-1, &S);
			push(k-2, &S);
		}
	} 

    return tong;
}


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
	
	int k, n, c = 0;
	printf("To hop chap k cua n\n");
	printf("k = ");
	scanf("%d", &k);
	printf("n = ");
	scanf("%d", &n);
	c = C(k , n);
	printf("To hop chap %d cua %d la: %d\n", k, n, c);
	
	printf("\n");
	
	int x, f = 0;
	printf("x = ");
	scanf("%d", &x);
	f = Fibo(x);
	printf("Fibo cua %d la: %d", x, f);
	
	return 0; 
}


 
