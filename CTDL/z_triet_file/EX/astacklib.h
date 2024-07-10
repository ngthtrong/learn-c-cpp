#include<stdio.h>
#include<string.h>

#define MAXSIZE 100

typedef int ElementType;

typedef struct{
	ElementType Element[MAXSIZE];
	int Top;
}Stack;

void makeNULL(Stack *S){
	S->Top = -1;
}

int isEmpty(Stack S){
	if(S.Top != -1) return 0;
	return 1;
} 

int isFull(Stack S){
	if(S.Top != MAXSIZE-1) return 0;
	return 1;
}

void push(ElementType x, Stack *S){
	if(isFull(*S) == 1) printf("Error Stack.Push: Stack is full!");
	else{
		S->Top +=1;
		S->Element[S->Top] = x;
	}
}

ElementType pop(Stack *S){
	if(isEmpty(*S) == 1) printf("Error Stack.Pop: Stack is empty!");
	else{
	int k = S->Top;
		S->Top -=1;
	return S->Element[k];
	}
}
 
