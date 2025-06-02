#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data; /*A pointer to a memory location of digits*/  
    int size;
} Number;

// Function to read a number character by character from input
void readNumber(Number *num) {
    int capacity = 32; // Initial capacity
    num->data = (int*)malloc(capacity * sizeof(int));
    if (num->data == NULL) {
        num->size = 0;
        return;
    }
    
    int ch, i = 0;
    while ((ch = getchar()) != '\n' && ch != EOF) {
        // Skip whitespace
        if (ch == ' ' || ch == '\t' || ch == '\r')
            continue;
            
        if (i >= capacity) {
            capacity *= 2;
            int *temp = (int*)realloc(num->data, capacity * sizeof(int));
            if (temp == NULL) {
                free(num->data);
                num->data = NULL;
                num->size = 0;
                return;
            }
            num->data = temp;
        }
        
        // Store in reverse order - least significant digit first
        num->data[i++] = ch - '0';
    }
    
    // Reverse to store least significant digit at index 0
    num->size = i;
    for (int j = 0; j < i / 2; j++) {
        int temp = num->data[j];
        num->data[j] = num->data[i - 1 - j];
        num->data[i - 1 - j] = temp;
    }
}

// Function to print a number
void printNumber(Number *num) {
    if (num->size == 0) {
        printf("0");
        return;
    }
    
    for (int i = num->size - 1; i >= 0; i--) {
        printf("%d", num->data[i]);
    }
}

// Function to free memory allocated for a number
void freeNumber(Number *num) {
    if (num->data != NULL) {
        free(num->data);
        num->data = NULL;
    }
    num->size = 0;
}

// Function to multiply two big integers
void multiplyNumbers(Number *num1, Number *num2, Number *result) {
    int len1 = num1->size;
    int len2 = num2->size;
    
    // Maximum possible length of result is len1 + len2
    int max_len = len1 + len2;
    result->data = (int*)calloc(max_len, sizeof(int));
    if (result->data == NULL) {
        result->size = 0;
        return;
    }
    
    // Perform multiplication
    for (int i = 0; i < len1; i++) {
        for (int j = 0; j < len2; j++) {
            result->data[i + j] += num1->data[i] * num2->data[j];
        }
    }
    
    // Process carries
    for (int i = 0; i < max_len - 1; i++) {
        result->data[i + 1] += result->data[i] / 10;
        result->data[i] %= 10;
    }
    
    // Determine actual size by removing leading zeros
    result->size = max_len;
    while (result->size > 1 && result->data[result->size - 1] == 0) {
        result->size--;
    }
}

int main() {
    Number n1 = {NULL, 0};
    Number n2 = {NULL, 0};
    Number result = {NULL, 0};
    
    readNumber(&n1);
    readNumber(&n2);
    
    multiplyNumbers(&n1, &n2, &result);
    
    printNumber(&result);
    
    freeNumber(&n1);
    freeNumber(&n2);
    freeNumber(&result);
    
    return 0;
}
