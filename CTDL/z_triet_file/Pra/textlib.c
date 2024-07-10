#include"linkedlist.h"

int main(){
	int i;
	int p, x;
	List L = NULL;
	for(i = 1; i<6; i++){
		pushFront(&L, i);
	}
	int k = locate(3, L);
	printf("%d \n", k); 
	print(L);
	return 0; 
} 
