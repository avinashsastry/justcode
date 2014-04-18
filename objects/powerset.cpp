#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N	5

using namespace std;

void printPowerSet(int* array, unsigned int n) {
	if (!array) return;
	if (n < 0) return;
	
	if (n == 1) {
		printf("%d\n", *array);
		return;
	}
	
	for (int i = 0; i < n; i++) {		
		int* array2 = (int*) malloc( (n-1)*sizeof(int) );
		
		// setup array here
		int j = 0;
		int k = 0;
		while (k < n-1 && j < n) {
			if (j != i) {
				array2[k] = array[j];
				k++;
				j++;
			}
			else {
				j++;
			}
		}
		
		printPowerSet(array2, n-1);
		free(array2);	
	}
	
	for (int i = 0; i < n; i++) {
		printf("%d ", array[i]);
	}
	printf("\n");
}

// We're going to try and print out the power set of a given array of numbers
int main() {
	
	int array[N] = {1, 2, 3, 4, 5};
	printPowerSet(array, N);
	return 0;
}