#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "plistlib.h"

int a[] = {32, 51, 27, 83, 66, 11, 45, 75};

// a.ham nhap theo thu tu nhap
void appendList(int a[], int n, List *L)
{
	makeNull(L);
	for (int i = n - 1; i >= 0; i--)
		insertFirst(a[i], L);
}
// ham tao danh sach dao
void reverseList(int a[], int n, List *L)
{
	for (int i = n - 1, j = 0; i >= 0 && j < n; i--, j++)
		setAt(j, a[i], L);
}

// ham sap xep bubble sort
void bubbleSort(List *L)
{
	PNode tempNode = *L;

	for (Position i = 1; getPosition(i, *L) != end(*L); i++)
	{

		for (Position j = len(*L); getPosition(j, *L) != first(*L) && i > 1; j--)
		{
			if (getAt(j, *L) < getAt(j - 1, *L))
			{
				ElementType temp = getAt(j, *L);
				setAt(j, getAt(j - 1, *L), L);
				setAt(j - 1, temp, L);
			}
		}
	}
}

// h�m chinh de chay chuong trinh
int main()
{
	List L1;
	appendList(a, sizeof(a) / sizeof(int), &L1);
	print(L1);
	reverseList(a, sizeof(a) / sizeof(int), &L1);
	print(L1);
	insertAt(3, 22, &L1);
	print(L1);
	bubbleSort(&L1);
	print(L1);
}
