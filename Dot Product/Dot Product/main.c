// Author: Barion, Ryan Onil Cruz, Section: S-11

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// C Implementation
int cDotProduct(long unsigned int ARRAY_SIZE,int *a, int *b);
extern int asmDotProduct(long unsigned int ARRAY_SIZE, int* a, int* b);
extern int SIMDDotProduct(long unsigned int ARRAY_SIZE, int* a, int* b);

int main(void) {
	long unsigned int ARRAY_SIZE = 1 << 20; 
	int *a, *b;

	int c_sdot = 0, asm_sdot = 0,SIMD_sdot = 0;

	clock_t tStart = 0, tEnd = 0;
	double tExecution = 0.0;
	double tTaken = 0.0;

	// Allocate memory for input variables
	a = (int*)malloc(sizeof(int) * ARRAY_SIZE);
	b = (int*)malloc(sizeof(int) * ARRAY_SIZE);

	for (long unsigned int i = 0; i < ARRAY_SIZE; ++i) {
		a[i] = i + 1;
		b[i] = i + 2;
	}

	printf("Input Size: %lu\n\n", ARRAY_SIZE);

	// Measure average run for 30 number of runs
	tStart = clock();
	for (int i = 0; i < 30; ++i)
		c_sdot= cDotProduct(ARRAY_SIZE, a, b);
	tEnd = clock();

	tExecution = (((double)tEnd - tStart) * 1e6 / CLOCKS_PER_SEC) / 30.0;
	tTaken = ((double)tEnd - tStart) * 1e6 / CLOCKS_PER_SEC;

	printf("C Program Output: %d\n", c_sdot);
	printf("Runtime (microseconds): %lf\n", tTaken);
	printf("Average runtime (microseconds): %lf\n\n", tExecution);

	tStart = clock();
	for (int i = 0; i < 30; ++i)
		asm_sdot = asmDotProduct(ARRAY_SIZE, a, b);
	tEnd = clock();

	tExecution = (((double)tEnd - tStart) * 1e6 / CLOCKS_PER_SEC) / 30.0;
	tTaken = ((double)tEnd - tStart) * 1e6 / CLOCKS_PER_SEC;
	printf("x64 Program Output: %d\n", asm_sdot);
	printf("Runtime (microseconds): %lf\n", tTaken);
	printf("Average runtime (microseconds): %lf\n\n", tExecution);

	tStart = clock();
	for (int i = 0; i < 30; ++i)
		SIMD_sdot = SIMDDotProduct(ARRAY_SIZE, a, b);
	tEnd = clock();

	tExecution = (((double)tEnd - tStart) * 1e6 / CLOCKS_PER_SEC) / 30.0;
	tTaken = ((double)tEnd - tStart) * 1e6 / CLOCKS_PER_SEC;
	printf("SIMD Program Output: %d\n", SIMD_sdot);
	printf("Runtime (microseconds): %lf\n", tTaken);
	printf("Average runtime (microseconds): %lf\n\n", tExecution);
	
	

	// Free allocated memory
	free(a);
	free(b);
	return 0; 
}

int cDotProduct(long unsigned int ARRAY_SIZE, int* a, int *b) {
	
	int mul_result = 0;
	
	for (long unsigned int i = 0; i < ARRAY_SIZE; ++i) 
		mul_result = mul_result + (a[i] * b[i]);

	return mul_result;
}