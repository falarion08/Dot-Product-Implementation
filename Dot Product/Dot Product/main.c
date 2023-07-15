// Author: Barion, Ryan Onil Cruz, Section: S-11

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// C Implementation
long int cDotProduct(long unsigned int ARRAY_SIZE,long int *a, long int *b);

int main(void) {
	long unsigned int ARRAY_SIZE = 1 << 28; 
	long int *a, *b;

	long int c_sdot = 0;

	// Allocate memory for input variables
	a = (long int*)malloc(sizeof(long int) * ARRAY_SIZE);
	b = (long int*)malloc(sizeof(long int) * ARRAY_SIZE);

	for (long unsigned int i = 0; i < ARRAY_SIZE; ++i) {
		a[i] = i + 1;
		b[i] = i + 2;
	}
	
	c_sdot = cDotProduct(ARRAY_SIZE, a, b);

	
	printf("%ld", c_sdot);

	// Free allocated memory
	free(a);
	free(b);
	return 0; 
}

long int cDotProduct(long unsigned int ARRAY_SIZE, long int* a, long int *b) {
	
	long int mul_result = 0;
	
	for (long unsigned int i = 0; i < ARRAY_SIZE; ++i) 
		mul_result = mul_result + (a[i] * b[i]);

	return mul_result;
}