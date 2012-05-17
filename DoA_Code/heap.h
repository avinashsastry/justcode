#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

/*
 *	A quick and dirty heap implementation
 *	Uses a single integer array to keep track of all 
 * 	elements.
 */
class heap {

	private:
		// A dynamically allocated array
		// of integers that serves as the memory
		// for holding all values.
		int* keys;
		
		// The current length of the array/heap in memory
		unsigned int total_length;
		
		// The actual (logical) length of the heap
		unsigned int heap_length;
		
		
		// heapify()
		// internal methods to balance/rearrange the heap
		void heapify();
		void reverse_heapify();
		
	public:
		// Constructor
		heap();
		
		// Insert()
		// Method to insert a new value into the heap
		// Also handles the amount of memory allocated for the heap
		void insertKey(int newValue); 
		
		// Extract min()
		// Function to extract the minimum value of the heap
		int returnMinKey();
		
		// Extracts the minimum element
		// Rebalances the heap
		int extractMinKey();
		
		// Prints out the elements in the heap
		void print();
		
		// destructor
		// Free all memory used
		~heap();
};