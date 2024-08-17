#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    char *digits; // Pointer to store digits
    int length;   // Length of the number
} BigInt;

void scanBigNum(BigInt *number, char c)
{
    char num[1000];
    printf("Enter %c: ", c);
    fgets(num, 1000, stdin);
    if (num[strlen(num) - 1] == '\n')
        num[strlen(num) - 1] = '\0';
    number->digits = (char *)malloc(strlen(num) + 1);
    strcpy(number->digits, num);
    number->length = strlen(number->digits);
}

void printBigNum(BigInt number)
{
    printf("Number: %s\n", number.digits);
    printf("Length: %d\n", number.length);
}

void swap(BigInt *a, BigInt *b)
{
    BigInt temp = *a;
    *a = *b;
    *b = temp;
}

void reverse(BigInt *num)
{
    for (int i = 0, j = num->length - 1; i < j; i++, j--)
    {
        char temp = num->digits[i];
        num->digits[i] = num->digits[j];
        num->digits[j] = temp;
    }
}

BigInt sum(BigInt a, BigInt b)
{
    BigInt result;
    result.digits = (char *)malloc(sizeof(char) * a.length > b.length ? a.length + 1 : b.length + 1);
    int carry = 0;
    for (int i = a.length - 1, j = b.length - 1, rsIndex = 0; i >= 0 || j >= 0 || carry; i--, j--, rsIndex++)
    {
        int aDigit = i >= 0 ? a.digits[i] - 48 : 0;
        int bDigit = j >= 0 ? b.digits[j] - 48 : 0;
        bDigit += carry ? carry : 0;
        int sumDigit = aDigit + bDigit;
        carry = sumDigit > 9 ? 1 : 0;
        sumDigit = sumDigit % 10;
        result.digits[rsIndex] = sumDigit + 48;
    }
    result.length = strlen(result.digits);
    reverse(&result);
    return result;
}

BigInt sub(BigInt a, BigInt b)
{
    BigInt result;
    result.digits = (char *)malloc(sizeof(char) * a.length > b.length ? a.length : b.length);
    int isNegative = 0;
    if (a.length == b.length) // make a always bigger than b and handle equal case
    {
        if (strcmp(a.digits, b.digits) == 0)
        {
            strcpy(result.digits, "0");
            result.length = 1;
            return result;
        }
        else if (strcmp(a.digits, b.digits) < 0)
        {
            swap(&a, &b);
            isNegative = 1;
        }
    }
    else if (a.length < b.length) // check negative case
    {
        swap(&a, &b);
        isNegative = 1;
    }
    int carry = 0;
    for (int i = a.length - 1, j = b.length - 1, rsIndex = 0; i >= 0 || j >= 0 || carry; i--, j--, rsIndex++)
    {
        int aDigit = i >= 0 ? a.digits[i] - 48 : 0;
        int bDigit = j >= 0 ? b.digits[j] - 48 : 0;
        bDigit += carry ? carry : 0;
        carry = 0;
        if (aDigit < bDigit)
        {
            aDigit += 10;
            carry = 1;
        }
        int subDigit = aDigit - bDigit;
        result.digits[rsIndex] = subDigit + 48;
    }
    while (result.digits[strlen(result.digits) - 1] == '0')
        result.digits[strlen(result.digits) - 1] = '\0';
    if (isNegative)
    {
        result.digits[strlen(result.digits)] = '-';
        result.digits[strlen(result.digits) + 1] = '\0';
    }
    result.length = strlen(result.digits);
    reverse(&result);
    result.length -= isNegative ? 1 : 0;
    return result;
}

BigInt mul(BigInt a, BigInt b)
{
    BigInt result;
    result.digits = (char *)malloc(sizeof(char) * (a.length + b.length));
    for (int i = 0; i < a.length + b.length; i++)
    {
        result.digits[i] = '0';
    }
    result.digits[a.length + b.length] = '\0';
    result.length = a.length + b.length;
    for (int i = a.length - 1; i >= 0; i--)
    {
        for (int j = b.length - 1; j >= 0; j--)
        {
            int mulDigit = (a.digits[i] - 48) * (b.digits[j] - 48);
            int sumDigit = result.digits[i + j + 1] - 48 + mulDigit;
            result.digits[i + j + 1] = sumDigit % 10 + 48;
            result.digits[i + j] += sumDigit / 10;
        }
    }
    if (result.digits[0] == '0')
    {
        for (int i = 0; i < result.length - 1; i++)
        {
            result.digits[i] = result.digits[i + 1];
        }
        result.digits[result.length - 1] = '\0';
        result.length--;
    }
    return result;
}

BigInt longDivision(BigInt a, int divisor)
{
    BigInt result;
    result.digits = (char *)malloc(sizeof(char) * (a.length));
    int idx = 0;
    int temp = a.digits[idx] - '0';
    int rs_idx = 0;
    while (idx < (strlen(a.digits) - 1) && temp < divisor)
    {
        temp = temp * 10 + (a.digits[++idx] - '0');
    }
    while ((strlen(a.digits) - 1) > idx)
    {
        result.digits[rs_idx++] = (temp / divisor) + '0';
        temp = (temp % divisor) * 10 + a.digits[++idx] - '0';
    }

    result.digits[rs_idx++] = (temp / divisor) + '0';
    result.digits[rs_idx] = '\0';

    result.length = strlen(result.digits);
    if (rs_idx == 0)
    {
        strcpy(result.digits, "0");
        return result;
    }

    return result;
}

int main()
{
    BigInt a;
    scanBigNum(&a, 'a');
    BigInt b;
    scanBigNum(&b, 'b');
    printf("-Sum-\n");
    BigInt sumNum = sum(a, b);
    printBigNum(sumNum);
    printf("-Sub-\n");
    BigInt subNum = sub(a, b);
    printBigNum(subNum);
    printf("-Mul-\n");
    BigInt mulNum = mul(a, b);
    printBigNum(mulNum);
    printf("-Div-\n");
    BigInt divNum = longDivision(a, 6);
    printBigNum(divNum);
}