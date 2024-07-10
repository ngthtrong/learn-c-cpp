#include"plistlib.h"

void appendList(int a[], int n, List *L){
	int i;
	List temp;
	makeNULL(&temp);
	*L = temp; 
	for(i=0; i<n; i++){
		append(a[i], L);
	} 
}

void reverseList(int a[],int n, List *L){
	int i;
	List temp;
	makeNULL(&temp);
	*L = temp; 
	for(i=n-1; i>=0; i--){
		append(a[i], L);
	} 
}

void bubbleSort(List *L){
	int i, j;
	int n = len(*L);
	for(i=0; i<n; i++){
		for(j=0; j<n-i-1; j++){
			if(getAt(j, *L) > getAt(j+1, *L)){
				ElementType temp = getAt(j, *L);
				setAt(j, getAt(j+1, *L), L);
				setAt(j+1, temp, L);
			}
		}
	}
}

int main(int argc, char *argv[]){
	int  a[] = {32, 51, 1, 27, 83, 66, 11, 45, 75};
	List L1;
	appendList(a, sizeof(a)/sizeof(int), &L1);
	print(L1);
	reverseList(a, sizeof(a)/sizeof(int), &L1);
	print(L1);
	insertAt(3,22,&L1);
	print(L1);
	bubbleSort(&L1);
	print(L1);
	return 0; 
} 
