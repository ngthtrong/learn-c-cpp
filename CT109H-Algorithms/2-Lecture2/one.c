#include <stdio.h>
#define None -1

//this algorithm sorts a list A
//do you recognize this algorithm ?
void mysteryAlgorithmOne(int A[], int B[], int n) {
	int i, k;
	for (i = 0; i < n; i++)
		B[i] = None;

    //B is a blank list of the same length as A
    //We can initialize it with a special value (None = -1)
	//iterate through all the elements in A:
	for (k = 0;  k < n; k++) {
 		int x = A[k];
		//right now all of the non-None elements of B are already sorted.
		//step through them, in order, and find the place to insert x so that it stays sorted.
		for (i = 0; i < n; i++) {
			if (B[i] == None || B[i] > x) {
				// x goes in spot i, and we should move everything over (to the right 1 spot)
				int j = n - 1;
 				while (j > i) {
					B[j] = B[j-1];
					j -= 1;
				}
				B[i] = x;
				break; //okay, we are done placing x!  Onto the next one.
			}
		}
	}
}

int main() {
	int A[] = {5, 3, 4, 1, 6};
	int B[5];
	mysteryAlgorithmOne(A, B, 5);
	int i;

	printf("After mysteryAlgorithmOne:\n");
	printf("A = {");
	for (i = 0; i < 5; i++)
		printf("%d, ", A[i]);
	printf("}\n");


	printf("B = {");
	for (i = 0; i < 5; i++)
		printf("%d, ", B[i]);
	printf("}\n");
	
	
	return 0;
}
