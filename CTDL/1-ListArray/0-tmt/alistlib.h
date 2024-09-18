#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100

typedef int Position;
typedef int ElementType;
typedef struct
{
	ElementType elements[MAXSIZE];
	Position size;
} List;
List L;
/*
Initialize an empty list
*/
void makeNull(List *L)
{
	L->elements[0] = '\0';
	L->size = 0;
}

/*
return Number of elements
*/
int len(List L)
{
	return L.size;
}

/*
Check whether the list is empty?
*/
int empty(List L)
{
	return (L.size == 0);
}

/*
Check whether the list is full?
*/
int fullList(List L)
{
	return (L.size == MAXSIZE);
}

/*
Traverse the list to print out all elements
*/
void print(List L)
{
	Position i;
	for (i = 1; i <= L.size; ++i)
		printf("%d ", L.elements[i - 1]);
	printf("\n");
}

/*
Return the element at position p
*/
ElementType getAt(Position p, List L)
{
	if (p >= 1 && p <= L.size)
		return L.elements[p - 1];
	printf("Error Position not found!\n");
	exit(EXIT_FAILURE);
}

/*
Return the first position in L
*/
Position first(List L)
{
	return 1;
}

/*
Return the end position in L
*/
Position endList(List L)
{
	if (empty(L))
		return 1;
	else
		return L.size + 1;
}

/*
Update the element at position p by a new value
*/
void setAt(Position p, ElementType x, List *L)
{
	if (p >= 1 && p <= L->size)
		L->elements[p - 1] = x;
	else
	{
		printf("Error Position not found!\n");
		exit(EXIT_FAILURE);
	}
}

/*
Insert x at position p
*/
void insertAt(Position p, ElementType x, List *L)
{
	if (p >= 1 && p <= L->size + 1)
	{
		for (Position i = L->size; i >= p; i--)
			L->elements[i] = L->elements[i - 1];
		L->elements[p - 1] = x;
		L->size++;
	}
	else
	{
		printf("Error Position not found!\n");
		exit(EXIT_FAILURE);
	}
}
/*
Remove and return the element at position p
*/
ElementType popAt(Position p, List *L) // delete
{
	if (p >= 1 && p <= L->size)
	{
		ElementType x = L->elements[p - 1];
		for (Position i = p; i < endList(*L); i++)
			L->elements[i - 1] = L->elements[i];
		L->size--;
		return x;
	}
	else
	{
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}
}

/*
Insert x to the first position
*/
void insertFirst(ElementType x, List *L)
{
	if (empty(*L))
	{
		L->elements[0] = x;
		L->size++;
	}
	else
		insertAt(first(*L), x, L);
}

/*
Append a new element to the list
*/
void append(ElementType x, List *L)
{
	insertAt(endList(*L), x, L);
}
/*
Remove and return the first element
*/
ElementType popFirst(List *L)
{
	return popAt(first(*L), L);
}

/*
Remove and return the last element
*/
ElementType popLast(List *L)
{
	return popAt(endList(*L) - 1, L);
}

/*
Return the position of the first appearance of x in the list
*/
Position locate(ElementType x, List L)
{
	Position p;
	int found = 0;
	for (p = first(L); p < endList(L) && !found; p++)
		if (L.elements[p - 1] == x)
			found = 1;
	return p;
}

/*
Return the next position of p in L
*/
Position next(Position p, List L)
{
	if (p >= 1 && p < L.size )

		return p + 1;
	else
	{
		printf("p is end of list\n");
		exit(EXIT_FAILURE);
	}
}

/*
Return the previous position of p in L
*/
Position previous(Position p, List L)
{
	if (p >= 1 && p <= L.size && p != 1)
	{
		return p - 1;
	}
	else
	{
		printf("Position Error! Exit....\n");
		exit(EXIT_FAILURE);
	}
}
void bubbleSort(List *L)
{
	for (Position i = 0; i < L->size - 1; i++)
	{
		for (int j = L->size - 1; j > i; j--)
		{
			if (L->elements[j] < L->elements[j - 1])
			{
				ElementType temp = L->elements[j];
				L->elements[j] = L->elements[j - 1];
				L->elements[j - 1] = temp;
			}
		}
	}
}
void delete_duplicate(List *L)
{
	for (Position i = 1; i != endList(*L) && i != endList(*L); i++)
	{
		ElementType nowPosition = getAt(i, *L);
		for (Position j = i + 1; j != endList(*L); j++)
		{
			ElementType temp = getAt(j, *L);
			if (nowPosition == temp)
			{
				popAt(j, L);
			}
		}
	}
}
