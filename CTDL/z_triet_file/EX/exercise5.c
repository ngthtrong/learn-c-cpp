#include "astacklib.h"
#include "aCqueuelib.h"

int main()
{
	int i, n;
	Stack S;
	Queue Q;
	makeNULL(&S);
	makeNull(&Q);
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	int a[n];
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("\n");

	printf("Ex 5.1:\n");
	for (i = 0; i < n; i++)
	{
		push(a[i], &S);
	}
	while (!isEmpty(S))
	{
		int element = pop(&S);
		enQueue(&Q, element);
	}
	while (!isEmptyQ(Q))
	{
		printf("%d ", deQueue(&Q));
	}
	printf("\n");
	printf("Ex 5.2:\n");
	for (i = 0; i < n; i++)
	{
		enQueue(&Q, a[i]);
	}
	while (!isEmptyQ(Q))
	{
		push(deQueue(&Q), &S);
	}
	while (!isEmpty(S))
	{
		printf("%d ", pop(&S));
	}
	printf("\n");

	// printf("Ex 5.3:\n")

	return 0;
}
