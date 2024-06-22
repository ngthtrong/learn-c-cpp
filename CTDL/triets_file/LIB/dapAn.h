#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 100
#define ERROR -10000

typedef int ElementType;
typedef int Position;

typedef struct{
	ElementType Elements[MAXSIZE];
	int size;
}List;

void makeNull(List *L){
	L->size = 0;
}

void build(int A[], int n, List *pL)
{
	int i;
    pL->size=0;
    for (i=0; i<n; i++){	
        pL->Elements[pL->size] = A[i];
        pL->size++;
    }
}

void print_List(List L)
{
    int i;
    for (i = 0; i < L.size; i++)
        printf ("%d ", L.Elements[i]);
    printf ("\n");
}

ElementType getAt(int p, List L)
{
    if (1 <= p && p <= L.size)
    	return L.Elements[p-1];    
    return ERROR;
}

void setAt(int p, ElementType x, List *pL)
{
    if (1 <= p && p <= pL->size)
	    pL->Elements[p-1] = x; // O(1)
	else
	    printf("Vi tri khong hop le\n");
}

void insertAt(int p, ElementType x, List *pL)
{
	if (pL->size == MAXSIZE)
		printf("Danh sach day");	
  	else if (p < 1 || p > pL->size + 1)
	    printf("Vi tri khong hop le");
	else{
		int q;
		for(q = pL->size; q >= p; q--)
			pL->Elements[q] = pL->Elements[q-1];
		pL->size++;
		pL->Elements[p-1] = x;
	}
}

ElementType delete_at(int p, List *pL)
{
	if (p<0 || p>=pL->size)
	    return ERROR;
  	else{
    	int q;
    	ElementType x = pL->Elements[p-1];
     	for(q = p; q < pL->size; q++)
		   pL->Elements[q-1] = pL->Elements[q];
		pL->size--;
		return x;
	}
}

void insertFirst(ElementType x, List *pL)
{
	insertAt(1, x, pL); //O(n)
}

ElementType delete_first(List *pL)
{
	return delete_at(1, pL); //O(n)
}

ElementType delete_last(List *pL)//O(1)
{
	// return deleteAt(pL->size-1, pL)
	ElementType e = pL->Elements[pL->size-1]; 
	pL->size--;
	return e;
}

void append(ElementType x, List *pL)
{
	//insertAt(x, pL->size, pL);
	if (pL->size == MAXSIZE)
		printf("Danh sach day\n");
	else{
		pL->Elements[pL->size] = x; 
		pL->size++;
	}
}

int first(List L){
	return 1;
}

int endList(List L){
	return L.size + 1;
}

int next(int p, List L){
	return p+1;
}

void print(List L){
	int i;
	for(i = 0; i < L.size; i++){
		printf("%d ", L.Elements[i]);
	}
	printf("\n");
}
