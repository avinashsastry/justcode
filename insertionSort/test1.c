#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(unsigned int* a, unsigned int* b) {
	unsigned int temp = *a;
	*a = *b;
	*b = temp;
}

void insertion_sort(unsigned int* a, int N) {
	
	int swap_count = 0;
	
	for (int i = 1; i < N; i++) {
		int j = i;
		while ( (j > 0) && (a[j] < a[j-1]) ) {
			// in place swap
			swap_count++;
			swap(&a[j], &a[j-1]);
			j--;
		}
	}
	
	printf("Swap Count: %d\n", swap_count);
}

/*
 * Returns the diff of a in another array b (which is the same length as A)
 */
void diff(unsigned int *a, int* b, int N) {
	
	b[0] = 0;
		
	// Assuming A and B have the same length
	for (int i = 0; i < N-1; i++) {
		b[i+1] = a[i+1] - a[i]; 
	}

}
int main() {

	// Number of lines
	int n = 0;	
	printf("Enter number of lines: ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		// Number of elements
		int num_elem = 0;
		printf("Enter number of elements: ");
		scanf("%d", &num_elem);
		
		// Allocate an array using malloc
		unsigned int* a = (unsigned int*) malloc( num_elem * sizeof(unsigned int) );
		
		printf("Enter elements: ");
		for (int j = 0; j < num_elem; j++) {		 	
		 	// scanf the elements
		 	scanf("%d", &a[j]);
		}
				
		// Take the diff
		int* b = (int*) malloc( num_elem * sizeof(int) );
		diff(a, b, num_elem);
		
		for (int j = 0; j < num_elem; j++) {
			printf("%d ", a[j]);
		}
		
		printf("\n");
		
		for (int j = 0; j < num_elem; j++) {
			printf("%d ", b[j]);
		}
		
		printf("\n");
		
		// We have our array now sort it using insertion sort (inplace)
		insertion_sort(a, num_elem);
		
		// Free the heap space
		free(a);
		free(b);
	}
}