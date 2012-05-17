#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM		8

/*
 *	Merge()
 *  Combines two sorted arrays
 * 	Inputs: pointer to first array; Length of first array
 *  		pointer to second array; length of second array
 *			pointer to destination array; length of destination
 *  Outputs:nothing. Array is sorted in place.
 */
 
void merge(int* a, unsigned int Na, int* b, unsigned int Nb, int* c, unsigned int N) {

	// Basic input checks
	if (!a || !b || !c) return;
	
	// N is just a formality but check to make 
	// sure the lengths are matching. THe last thing I
	// want in a sorting algo is a seg fault.
	if ((Na + Nb) != N) return;
	
	// Begin merge
	//printf("Merging...\n");
	unsigned int i = 0;
	unsigned int j = 0;
	for (unsigned int k = 0; k < N; k++) {
	
		if (i >= Na) {
			c[k] = b[j];
			j++;
		}
		else if (j >= Nb) {
			c[k] = a[i];
			i++;
		}
		else if (i < Na && j < Nb) {
			if ( a[i] <= b[j] ) {
				c[k] = a[i];
				i++;
			}
			else {
				c[k] = b[j];
				j++;
			}
		}
				
		//printf("%d ", c[k]);
	}
	//printf("\n");
}

/*
 *	Merge sort
 *  Simple recursive algorithm to sort a given array
 * 	Inputs: pointer to array; Length of array
 *  Outputs:nothing. Array is sorted in place.
 *	Uses function: merge()
 */
void merge_sort(int* array, unsigned int N) {
	// basic input checking
	if (!array) return;
	if (N == 0) return;
	
	//printf("Merge sort: N=%d\n", N);
	if (N == 1) return;
	
	// Find the splitting point - allocate memory for copies
	unsigned int Na = 0;
	unsigned int Nb = 0;
		
	if (N & 1) {
		// N is odd
		Na = (N/2) + 1;
		Nb = N/2;
	}
	else {
		// N is even
		Na = N/2;
		Nb = N/2;
	}
	
	int* a = (int*) malloc(Na * sizeof(unsigned int));
	int* b = (int*) malloc(Nb * sizeof(unsigned int));
		
	memcpy((void*)a, array, Na*sizeof(unsigned int));
	memcpy((void*)b, array+Na, Nb*sizeof(unsigned int)); 
	
	// Sort each half
	merge_sort(a, Na);
	merge_sort(b, Nb);
	
	// After sorting do the merge
	merge(a, Na, b, Nb, array, N);
	
	free(a);
	free(b);
}


// Program to test and execute merge sort on a given sample array
int main () {
	
	int array[NUM] = {5, 5, 55, -5, 5, 5, 5, 5};
	//int array[NUM] = {5, 4};
	
	// Print
	for (int i = 0; i < NUM; i++) printf("%d ", array[i]);
	printf("\n");
	
	// We are going to sort this array with merge sort
	merge_sort(array, NUM);
	
	// Print
	for (int i = 0; i < NUM; i++) printf("%d ", array[i]);
	printf("\n");
	
	return 0;
}