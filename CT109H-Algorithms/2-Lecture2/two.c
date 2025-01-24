#include <stdio.h>
#define None -1

// this algorithm sorts a list A
// do you recognize this algorithm ?
void mysteryAlgorithmTwo(int A[], int n)
{
    int i;
    for (i = 1; i < n; i++)
    {
        int current = A[i];
        int j = i - 1;
        while (j >= 0 && A[j] > current)
        {
            A[j + 1] = A[j];
            j -= 1;
        }
        A[j + 1] = current;

       
    }
}

int main()
{
    int A[] = {5, 3, 4, 1, 6};
    int i;

    mysteryAlgorithmTwo(A, 5);

    printf("After mysteryAlgorithmTwo:\n");
    printf("A = {");
    for (i = 0; i < 5; i++)
        printf("%d ", A[i]);
    printf("}\n");

    return 0;
}