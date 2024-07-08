#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef int ElementType;

typedef struct{
	ElementType *Elements;
	int Top;
	int Cap;
}Stack;

void makeNULL(Stack *S){
	S->Elements = (ElementType*)malloc(sizeof(ElementType));
	S->Top = -1;
	S->Cap = 0;
}

int isEmpty(Stack S){
	if(S.Top != -1) return 0;
	return 1;
} 

int isFull(Stack S){
	if(S.Top != S.Cap-1) return 0;
	return 1;
}

void resize(Stack *S, int newCap){
	int i;
	int a[S->Cap];
	for(i = 0; i <= S->Top; i++){
		a[i] = *(S->Elements + i);
	}
	S->Cap = newCap;
	S->Elements = (ElementType*)malloc(newCap*sizeof(ElementType));
	for(i = 0; i <= S->Top; i++){
		*(S->Elements + i) = a[i];
	}
	free(a);
}

void push(ElementType x, Stack *S){
	if(isFull(*S) == 1) resize(S, (S->Cap)*2);
	else{
		S->Top +=1;
		*(S->Elements + S->Top) = x;
	}
}

ElementType pop(Stack *S){
	if(isEmpty(*S) == 1){
		printf("Error Stack.Pop: Stack is empty!");
		return 0;
	}
	else{
	int k = S->Top;
		S->Top -=1;
	return *(S->Elements + k);
	}
}
 
