#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct
{
	char *numbers;
	int length;
} NewInt;
void scanNewInt(NewInt *a, char c)
{
	char number[1000];
	printf("Type %c: ", c);
	scanf("%s", number);
	a->numbers = (char *)malloc(strlen(number) + 1);
	strcpy(a->numbers, number);
	a->length = strlen(number);
}
void PrintNewInt(NewInt a)
{
	printf("%s \n", a.numbers);
}
void convertToPositive(NewInt *a)
{
	if (a->numbers[0] == '-')
	{
		int i = 0;
		for (i = 0; i < a->length; i++)
		{
			a->numbers[i] = a->numbers[i + 1];
		}
		a->length--;
	}
}
void convertToNegative(NewInt *a)
{
	int i;
	a->length++;
	for (i = a->length; i >= 0; i--)
	{
		a->numbers[i + 1] = a->numbers[i];
	}
	a->numbers[0] = '-';
}
NewInt copyNewInt(NewInt a)
{
	NewInt copy;
	copy.numbers = (char *)malloc(strlen(a.numbers) + 1);
	strcpy(copy.numbers, a.numbers);
	copy.length = a.length;
	return copy;
}
NewInt sum2numbers(NewInt a, NewInt b);
NewInt sub2numbers(NewInt a, NewInt b);
NewInt mul2numbers(NewInt a, NewInt b);
int main()
{
	NewInt a;
	scanNewInt(&a, 'a');
	NewInt b;
	scanNewInt(&b, 'b');
	NewInt mul = mul2numbers(a, b);
	PrintNewInt(mul);
}
NewInt sum2numbers(NewInt a, NewInt b)
{
	a = copyNewInt(a);
	b = copyNewInt(b);
	NewInt sum;
	sum.numbers = (char *)malloc(a.length > b.length ? a.length + 1 : b.length + 1);
	sum.length = a.length > b.length ? a.length + 1 : b.length + 1;
	int i, j, k, c = 0, s;
	i = a.length - 1;
	j = b.length - 1;
	if (a.length > b.length)
	{
		k = a.length;
	}
	else
		k = b.length;
	sum.numbers[k] = '\0';
	k--;
	while (i >= 0 && j >= 0)
	{
		s = (a.numbers[i] - '0') + (b.numbers[j] - '0') + c;
		sum.numbers[k] = s % 10 + '0';
		c = s / 10;
		i--;
		j--;
		k--;
	}
	if (i >= 0)
	{
		while (i >= 0)
		{
			s = (a.numbers[i] - '0') + c;
			sum.numbers[k] = s % 10 + '0';
			c = s / 10;
			i--;
			k--;
		}
	}
	if (j >= 0)
	{
		while (j >= 0)
		{
			s = (b.numbers[j] - '0') + c;
			sum.numbers[k] = s % 10 + '0';
			c = s / 10;
			j--;
			k--;
		}
	}
	if (c > 0)
	{
		for (k = sum.length; k >= 0; k--)
		{
			sum.numbers[k + 1] = sum.numbers[k];
		}
		sum.numbers[0] = c + '0';
	}
	return sum;
}
NewInt sub2numbers(NewInt a, NewInt b)
{
	a = copyNewInt(a);
	b = copyNewInt(b);
	NewInt sub;
	sub.numbers = (char *)malloc(a.length > b.length ? a.length + 1 : b.length + 1);
	sub.length = a.length > b.length ? a.length + 1 : b.length + 1;
	int i, j, k, c = 0, s;
	i = a.length - 1;
	j = b.length - 1;
	if (a.length > b.length)
	{
		k = a.length;
	}
	else
		k = b.length;
	sub.numbers[k] = '\0';
	k--;
	while (i >= 0 && j >= 0)
	{
		s = ((a.numbers[i] - '0') - (b.numbers[j] - '0') - c);
		if (s < 0)
		{
			s = s + 10;
			c = 1;
		}
		else
			c = 0;
		sub.numbers[k] = s + '0';
		i--;
		j--;
		k--;
	}
	if (i >= 0)
	{
		while (i >= 0)
		{
			s = (a.numbers[i] - '0') - c;
			if (s < 0)
			{
				s = s + 10;
				c = 1;
			}
			else
				c = 0;
			sub.numbers[k] = s + '0';
			i--;
			k--;
		}
	}
	if (j >= 0)
	{
		while (j >= 0)
		{
			s = (b.numbers[j] - '0') - c;
			if (s < 0)
			{
				s = s + 10;
				c = 1;
			}
			else
				c = 0;
			sub.numbers[k] = s + '0';
			j--;
			k--;
		}
	}
	return sub;
}
NewInt mul2numbers(NewInt a, NewInt b)
{
	a = copyNewInt(a);
	b = copyNewInt(b);
	NewInt mul;
	char product[100], ans[100];
	int i, j, shift, k, k1, k2, c, pro, sum, n = 0;
	mul.numbers = (char *)malloc(a.length + b.length);
	for (i = 0; i < a.length + b.length; i++)
	{
		ans[i] = 0;
	}
	for (i = 0; i < a.length + b.length; i++)
	{
		mul.numbers[i] = '0';
	}
	mul.numbers[a.length + b.length] = '\0';
	mul.length = a.length + b.length;
	for (j = b.length - 1; j >= 0; j--)
	{
		if (b.numbers[j] == '-')
		{
			break;
		}
		shift = b.length - 1 - j;
		c = 0;
		for (i = 0; i < a.length + b.length; i++)
		{
			product[i] = 0;
		}
		k1 = b.numbers[j] - '0';
		for (i = a.length - 1, k = a.length + b.length - 1 - shift; i >= 0; i--, k--)
		{
			if (a.numbers[i] == '-')
			{
				break;
			}
			k2 = a.numbers[i] - '0';
			pro = k1 * k2 + c;
			if (pro > 10)
			{
				product[k] = pro % 10;
				pro = pro / 10;
				c = pro;
			}
			else
			{
				product[k] = pro;
				c = 0;
			}
		}
		if (c > 0)
		{
			product[k] = c;
		}
		c = 0;
		for (i = a.length + b.length - 1; i >= 0; i--)
		{
			sum = product[i] + ans[i] + c;
			if (sum >= 10)
			{
				ans[i] = (sum % 10);
				sum = sum / 10;
				c = sum;
			}
			else
			{
				ans[i] = sum;
				c = 0;
			}
		}
	}
	i = 0;
	while (ans[i] == 0)
	{
		i++;
	}
	if (a.numbers[0] == '-' && b.numbers[0] != '-')
	{
		mul.numbers[n] = ('-');
		n++;
	}
	else if (a.numbers[0] != '-' && b.numbers[0] == '-')
	{
		mul.numbers[n] = ('-');
		n++;
	}
	
	for (; i < a.length + b.length; i++, n++)
	{
		mul.numbers[n] = ans[i] + '0';
	}
	return mul;
}