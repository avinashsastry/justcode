#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM		8

/*
 *	ChoosePivot:
 * 	Chooses a pivot element from the array
 *	Returns the index of the element
 */
int choosePivot(int* array, unsigned int N) {
	return array[0];
}

/*
 *	PartitionArray:
 * 	Creates a new array partitioned around a pivot element
 *  NOTE: This implementation is sub-optimal not in time, 
 * 	but in memory contraints. The ideal quicksort uses almost no additional 
 *  memory, this one uses O(n) additional memory, but it's much easier
 *  to understand, plus we have enough RAM to go around these days :)
 *	Returns nothing.
 */
int partitionArray(int* array, unsigned int N, int pivot) {
	// input checks
	if (!array) return 0;
	if (N == 0) return 0;
	if (N == 1) return 1;
	
	// Allocate some memory
	int i = 0;
	int j = 0;
	int l = 0;
	int* arrayL = (int*) malloc(N * sizeof(int)); // Will contain all elements < than pivot
	int* arrayR = (int*) malloc(N * sizeof(int)); // Will contain all elements > than pivot
	
	for (unsigned int k = 0; k < N; k++) {		
		if (array[k] < pivot) {
			arrayL[i] = array[k];
			i++;
		}
		else if (array[k] > pivot) {
			arrayR[j] = array[k];
			j++;
		}
		else if (array[k] == pivot) {
			l++;
		}
	}
	
	//for (int z = 0; z < i; z++) printf("%d ", arrayL[z]);
	//printf("\n");
	
	//for (int z = 0; z < j; z++) printf("%d ", arrayR[z]);
	//printf("\n");
	
	// Create our new partitioned array
	memcpy(array, arrayL, i*sizeof(int));
	for (int z = 0; z < l; z++) array[i+z] = pivot;
	memcpy(array+i+l, arrayR, j*sizeof(int));
	
	//for (int z = 0; z < N; z++) printf("%d ", array[z]);
	//printf("\n");
	
	free(arrayL);
	free(arrayR);
	
	return i;
}

/*
 *	Quick Sort:
 * 	Sorts an array pretty damn quickly
 */
void quick_sort(int* array, unsigned int N) {
	// Input checks
	if (!array) return;
	if (N == 0) return;
	
	//printf("Entering QuickSort: N = %d\n", N);
	
	// Base case
	if (N == 1) return;
	
	// Choose a pivot element
	int pivot = choosePivot(array, N);
	//printf("Pivot: %d\n", pivot);
	
	// partition around this pivot into two arrays 
	// a and b
	int partIndex = partitionArray(array, N, pivot);
	//printf("PartIndex: %d\n", partIndex);
	
	quick_sort(array, partIndex);
	quick_sort(array + partIndex + 1, N-partIndex-1);
}

// Test function to try out quick sort on an unsorted array
int main() {
	
	int array[NUM] = {7, 2, -1, 4, 2, 9, 14, 57};
	
	// Print
	for (int i = 0; i < NUM; i++) printf("%d ", array[i]);
	printf("\n");
	
	// We are going to sort this array with merge sort
	quick_sort(array, NUM);
	
	// Print
	for (int i = 0; i < NUM; i++) printf("%d ", array[i]);
	printf("\n");
	
	return 0;
}