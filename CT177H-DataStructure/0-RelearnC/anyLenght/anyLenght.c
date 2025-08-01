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
    // Read input in chunks for better efficiency
    const int CHUNK_SIZE = 8192;

    // Use a linked list of chunks approach for virtually unlimited input size
    typedef struct ChunkNode
    {
        char data[CHUNK_SIZE];
        int used;            // Number of characters used in this chunk
        struct ChunkNode *next;
    } ChunkNode;

    ChunkNode *head = NULL, *tail = NULL;
    size_t totalSize = 0;

    // Read input in chunks
    while (!feof(stdin))
    {
        ChunkNode *newNode = (ChunkNode *)malloc(sizeof(ChunkNode));
        if (!newNode)
        {
            fprintf(stderr, "Memory allocation failed for input chunk\n");
            exit(1);
        }

        // Read a chunk of data
        size_t bytesRead = fread(newNode->data, 1, CHUNK_SIZE - 1, stdin);
        if (bytesRead == 0)
        {
            free(newNode);
            break;
        }

        // Process the chunk to find newline
        int newlinePos = -1;
        for (int i = 0; i < bytesRead; i++)
        {
            if (newNode->data[i] == '\n')
            {
                newlinePos = i;
                break;
            }
        }

        // If found newline, adjust bytes used
        if (newlinePos != -1)
        {
            newNode->used = newlinePos;
            totalSize += newlinePos;

            // Position file pointer after newline
            long offset = newlinePos + 1 - bytesRead;
            fseek(stdin, offset, SEEK_CUR);
        }
        else
        {
            newNode->used = bytesRead;
            totalSize += bytesRead;
        }

        // Add to linked list
        newNode->next = NULL;
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        // If we found newline, stop reading
        if (newlinePos != -1)
            break;
    }

    // Allocate exactly the right amount of memory for the number
    number->digits = (char *)malloc(totalSize + 1);
    if (!number->digits)
    {
        fprintf(stderr, "Memory allocation failed for final number\n");
        exit(1);
    }

    // Copy all chunks to the final buffer
    char *pos = number->digits;
    ChunkNode *current = head;
    while (current)
    {
        memcpy(pos, current->data, current->used);
        pos += current->used;

        ChunkNode *temp = current;
        current = current->next;
        free(temp);
    }

    // Null terminate and set length
    *pos = '\0';
    number->length = totalSize;

    // Remove trailing newline if present
    if (number->length > 0 && number->digits[number->length - 1] == '\n')
    {
        number->digits[--number->length] = '\0';
    }

    // Validate input - ensure only valid digits and possibly a leading minus sign
    for (int i = 0; i < number->length; i++)
    {
        if (i == 0 && number->digits[i] == '-')
            continue;
        if (number->digits[i] < '0' || number->digits[i] > '9')
        {
            fprintf(stderr, "Invalid character in number: %c\n", number->digits[i]);
            free(number->digits);
            exit(1);
        }
    }
}

void printBigNum(BigInt number)
{
    printf("%s\n", number.digits);
}

void swap(BigInt *a, BigInt *b)
{
    BigInt temp = *a;
    *a = *b;
    *b = temp;
}

int isDifficult(BigInt a, BigInt b)
{
    if ((a.digits[0] == '-' && b.digits[0] != '-') || (a.digits[0] != '-' && b.digits[0] == '-'))
        return 1;
    else
        return 0;
}

BigInt copyBigInt(BigInt a) // handle error BigInt be changed after run a function
{
    BigInt copy;
    copy.digits = (char *)malloc(strlen(a.digits) + 1);
    strcpy(copy.digits, a.digits);
    copy.length = a.length;
    return copy;
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

void convertToPositive(BigInt *a)
{
    if (a->digits[0] == '-')
    {
        reverse(a);
        a->digits[a->length - 1] = '\0';
        a->length--;
        reverse(a);
    }
}

void convertToNegative(BigInt *a)
{
    if (a->digits[0] != '-')
    {
        reverse(a);
        a->digits[a->length] = '-';
        a->digits[a->length + 1] = '\0';
        a->length++;
        reverse(a);
    }
}

BigInt sub(BigInt a, BigInt b);

BigInt sum(BigInt a, BigInt b);

BigInt mul(BigInt a, BigInt b);

BigInt myDiv(BigInt a, int divisor);

int main()
{
    BigInt a;
    scanBigNum(&a, 'a');
    BigInt b;
    scanBigNum(&b, 'b');
    // printf("a + b = ");
    // BigInt sumNum = sum(a, b);
    // printBigNum(sumNum);
    // printf("a - b = ");
    // BigInt subNum = sub(a, b);
    // printBigNum(subNum);
    // printf("a * b = ");
    BigInt mulNum = mul(a, b);
    printBigNum(mulNum);

    //---------------------------//
    // printf("a / 12837129 = ");
    // BigInt divNum = myDiv(a, 12837129);
    // printBigNum(divNum);
}

BigInt sum(BigInt a, BigInt b)
{
    a = copyBigInt(a);
    b = copyBigInt(b);
    if (!isDifficult(a, b))
    {
        int isNegative = 0;
        if (a.digits[0] == '-')
        {
            convertToPositive(&a);
            convertToPositive(&b);
            isNegative = 1;
        }
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
        if (isNegative)
            convertToNegative(&result);
        return result;
    }
    else
    {
        if (a.digits[0] == '-')
        {
            convertToPositive(&a);
            return sub(b, a);
        }
        else
        {
            convertToPositive(&b);
            return sub(a, b);
        }
    }
}

BigInt sub(BigInt a, BigInt b)
{
    a = copyBigInt(a);
    b = copyBigInt(b);
    if (!isDifficult(a, b))
    {
        if (a.digits[0] == '-')
        {
            swap(&a, &b);
            convertToPositive(&a);
            convertToPositive(&b);
        }
        BigInt result;
        result.digits =
            (char *)malloc(sizeof(char) * a.length > b.length ? a.length : b.length);
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
        for (int i = a.length - 1, j = b.length - 1, rsIndex = 0;
             i >= 0 || j >= 0 || carry; i--, j--, rsIndex++)
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
    else
    {
        if (a.digits[0] == '-')
            convertToNegative(&b);
        else
            convertToPositive(&b);
        return sum(a, b);
    }
}

BigInt mul(BigInt a, BigInt b)
{
    a = copyBigInt(a);
    b = copyBigInt(b);

    if ((a.digits[0] == '0' && a.length == 1) || (b.digits[0] == '0' && b.length == 1)) //handle 0 case
    {
        BigInt result;
        result.digits = (char *)malloc(sizeof(char) * 2);
        result.digits[0] = '0';
        result.digits[1] = '\0';
        result.length = 1;
        return result;
    }
    int isNegative = 0;
    if (isDifficult(a, b))
        isNegative = 1;

    if (a.digits[0] == '-')
        convertToPositive(&a);
    if (b.digits[0] == '-')
        convertToPositive(&b);
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
            int sumDigit = result.digits[i + j + 1] - 48 + mulDigit; // i+j+1 is the position of the digit in result,and equals (a.length + b.length -1)
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
    if (isNegative)
        convertToNegative(&result);
    return result;
}

BigInt myDiv(BigInt a, int divisor)
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
