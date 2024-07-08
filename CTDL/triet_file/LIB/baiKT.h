#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int Position;
typedef int ElementType;
typedef struct{
  ElementType elements[MAXSIZE];
  Position size;
}List;
List L;
/*
Initialize an empty list
*/
void makeNull(List *L){
	L->size = 0; 
}

/*
return Number of elements
*/
int len(List L){
	return L.size;
}

/*
Check whether the list is empty?
*/
int empty(List L){
	return (L.size==0);
}

/*
Check whether the list is full?
*/
int fullList(List L){
	return (L.size==MAXSIZE);
	
}

/*
Traverse the list to print out all elements
*/
void print(List L){
	Position i;
	for(i=1; i<=L.size;++i) printf("%d ", L.elements[i-1]);
	printf("\n");
}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L){
	int count = 0;
	while(count != p){
		count +=1;
		return L.elements[count];
	}
}

/*
Return the first position in L
*/
Position first(List L){
	return 1;
}

/*
Return the end position in L
*/
Position endList(List L){
	return L.size; 
}

/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x,List *L){
	int count = 0;
	while(count != p){
		count +=1;
		L->elements[count] = x; 
	}
}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L){
	int i;
	L->size +=1;
	for(i = L->size; i>p; i--){
		L->elements[i] = L->elements[i-1];
	} 
	L->elements[p] = x;
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L){
	ElementType x;
	if(p>=1 && p<=L->size){
		x= L->elements[p-1];
		Position q;	
		for(q=p;q<endList(*L);q++)
			L->elements[q-1]=L->elements[q];	
		L->size--;
		return x;
	}
	else{ 
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}	
}

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L){
		int i;
	L->size +=1;
	for(i = L->size; i>0; i--){
		L->elements[i] = L->elements[i-1];
	} 
	L->elements[0] = x;
}

/*
Remove and return the first element
*/
ElementType popFirst(List *L){
	return popAt(first(*L), L);
	
}
/*
Append a new element to the list
*/
void append(ElementType x,List *L){
	L->elements[L->size] = x;
	L->size++;
}

/*
Remove and return the last element
*/
ElementType popLast(List *L){
	return popAt(endList(*L), L);
}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L){
	Position p;
	int found=0;
	for(p=first(L);p<endList(L) && !found;p++)
			if (L.elements[p-1]==x) found=1;
		return p;
}

/*
Return the next position of p in L
*/
Position next(Position p,List L){
		if(p>=1 && p<=L.size){
		return p+1;
	}
	else{ 
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}	
}

/*
Return the previous position of p in L
*/
Position previous(Position p,List L){
	if(p>=1 && p<=L.size){
		return p-1;
	}
	else{ 
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}	
}

