#include "heap.h"

/* Heap methods */

// heapify()
// internal method to balance/rearrange the heap
void heap::heapify() {

	// NOTE: heapify assumes one very important fact:
	// That a new element was just added at the 
	// very last index of the array.
	
	// Given that this is true:
	// We can continue on to re-balancing the heap
	int temp = 0;
	unsigned int i = heap_length;	// Index of last element
	
	// bubble up the inserted node
	while (i > 1) {
		
		// Parent of i = (int) i/2 (cause of rounding down for odd numbers)
		if (keys[i-1] > keys[(int)i/2 - 1]) {
			// All is fine.
			// If i is 0, it will terminate here.
			break;
		}
		else {
			// Swap with parent
			temp = keys[i-1];
			keys[i-1] = keys[i/2 - 1];
			keys[i/2 - 1] = temp;
		}
		
		i = i/2;
	}
}

void heap::reverse_heapify() {
	
	// NOTE: reverse_heapify() makes one very important assumption:
	// That it is called after removing the head of the heap 
	// and replacing it with the last element in the array.
	
	// Given that this is true:
	// Rebalance
	int temp = 0;
	unsigned int i = 1;
	
	while (i <= heap_length) {
			
		// Children of i = 2*i and 2*i+1;
		unsigned int childL = 2*i;
		unsigned int childR = 2*i+1;
		unsigned int childToSwap = i;
		
		// Compare with left child if it exists
		if (childL <= heap_length) {
			if (keys[childL-1] < keys[childToSwap-1]) {
				childToSwap = childL;
			}
		}
		
		// Compare with right child
		if (childR <= heap_length) {
			if (keys[childR-1] < keys[childToSwap-1]) {
				childToSwap = childR;
			}
		}
		
		if (childToSwap != i) {
			// swap with the childToSwap
			printf("Swapped with %d at [%d]\n", keys[childToSwap-1], childToSwap);
			temp = keys[i-1];
			keys[i-1] = keys[childToSwap-1];
			keys[childToSwap-1] = temp;
		}
		else {
			// Heap condition OK! Get out of here..
			break;
		}
		
		// Repeat on the swapped position
		i = childToSwap;
	}
}

// Constructor
heap::heap() {
	// Initialize an array of zeros
	// with a default memory size of 64, perhaps?
	// We want to avoid making the mem calls too often, 
	// so we can double this size everytime we exceed it.
	keys = (int*) malloc(64 * sizeof(int));
	
	// Catch malloc if failed
	if (!keys) {
		printf("Malloc FAIL! Heap not initialized!");
	}
	
	// Initialize to zeros
	memset(keys, 0, 64 * sizeof(int));
	
	// set length to current allocation
	total_length = 64;	
	
	// Set length to 0
	heap_length = 0;
}

// Insert()
// Method to insert a new value into the heap
// Also handles the amount of memory allocated for the heap
void heap::insertKey(int newValue) {
	
	// If the length in memory is not enough,
	// extend it.
	if (total_length < (heap_length+1)) {
		// Allocate double the current memory
		int* keys2 = (int*) realloc(keys, 2*total_length * sizeof(int));
		if (!keys2) {
			printf("REALLOC failed! Couldn't insert element!");
			return;
		}
		
		// If successful, update pointer and total_length
		keys = keys2;
		total_length *= 2;
	}
	
	// Add the value	
	keys[heap_length] = newValue;
	heap_length++;
	
	// Balance the heap
	heapify();
}

// Extract min()
// Function to extract the minimum value of the heap
int heap::returnMinKey() {
	if (heap_length > 0) return keys[0];
	// Lol, this is awkward!
	else return NULL;
}

// Extracts the minimum element and removes it from the heap
// Rebalances the heap
int heap::extractMinKey() {
	
	if (heap_length > 0) {
		// Remove the first element
		int result = keys[0];
		
		// Replace head with last element
		keys[0] = keys[heap_length-1];
		heap_length--;
		
		// Now call reverse_heapify()
		reverse_heapify();
		
		return result;
	}
	else {
		return NULL;
	}
}

// Function to print out the tree
void heap::print() {
	unsigned int j = 0;
	unsigned int jsum = pow(2, j);
	for (unsigned int i = 1; i <= heap_length; i++) {
		printf("%d ", keys[i-1]);
		if (i == jsum) {
			printf("\n");
			//printf(" j = %d\n", j);
			j++;
			jsum += pow(2, j);
		}
	}
	printf("\n ---- \n");
}

// destructor
// Free all memory used
heap::~heap() {
	if (keys) free(keys);
}

// Heap implementation + test code
// The goal of this bit of code is to implement
// a quick array-based heap.
int main() {
	
	heap h = heap();
	
	// insert some elements
	h.insertKey(4);
	h.insertKey(7);
	h.insertKey(8);
	h.insertKey(3);
	h.insertKey(2);
	h.insertKey(9);
	h.insertKey(1);
	h.insertKey(5);
	h.insertKey(6);
		h.insertKey(9);
	h.insertKey(1);
	h.insertKey(5);
	h.insertKey(6);
		h.insertKey(6);

	h.print();
	
	//printf("Min element so far: %d\n", h.returnMinKey());
	
	/*
	h.extractMinKey();
	h.print();
	
	h.extractMinKey();
	h.print();
	
	h.extractMinKey();
	h.print();
	
	h.extractMinKey();
	h.print();
	
	h.extractMinKey();
	h.print();
	*/

	return 0;
}