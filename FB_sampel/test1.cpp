#include <stdio.h>
#include <string.h> //for malloc
#include <stdlib.h>

#define MAX_N	8

// should use a heap like data structure (min always on top)
// that allows two operations:
// 1. extractMin() - extracts the top element
// 2. addToTop() - can only add an element if it is less than the current min
class peg_heap {

	private:
	unsigned int length;
	unsigned int* array;
	
	void heapify() {
		// add to bottom - work it up
		// Note: start indexing at 1 to N (not 0)
	
		unsigned int i = length-1;
		
		while ( i > 0 ) {
			if (array[i] < array[i-1]) {
				unsigned int temp = array[i];
				array[i] = array[i-1];
				array[i-1] = temp;
			}
			else {
				break;
			}
			i--;
		}
	}

	public:
	
	// Constructor
	peg_heap() {
		array = (unsigned int*) malloc ( MAX_N * sizeof(unsigned int) );
		length = 0;
	}
	
		// Add element to heap and heapify it
	void addElem(unsigned int d) {
		if (length < MAX_N) {
			//printf("Adding %d at pos: %d", d, length);
			array[length] = d;
			length++;
			heapify();
		}
	}
	
	unsigned int returnMin() {
		if (length > 0)
			return array[0];
		else return 0;
	}
	
	unsigned int extractMin() {
		if (length > 0) {
		 	int result = array[0];
		 	// re-sort
		 	for (int i = 0; i < length-1; i++) {
		 		array[i] = array[i+1];
			}
		 	array[length-1] = 0;	
		 	length--;
		 	return result;
		}
		else return 0;
	}
	
	bool addToTop(unsigned int d) {
		if (length > 0) {
			if (d < array[0]) {
				addElem(d);
				return true;
			}
			else
			return false;
		}
		else {
			addElem(d);
			return true;
		}
			
	}
	
	void print() {
		if (length > 0) {
			printf("[ ");
			for (int i = 0; i < length; i++)
				printf("%d  ", array[i]);
			printf("]\n");
		}
		else {
			printf("[]\n");
		}
	}
	
	bool isEmpty() {
		if (length == 0)
			return true;
		else
			return false;
	}
	
	~peg_heap() {
		if (array) free(array);
	}
};

// Makes a move from current peg to target peg
void makeAMove(peg_heap* peg_array, unsigned int num_pegs, unsigned int source_peg, unsigned int dest_peg, unsigned int cur_disc_size, unsigned int* discs) {
	
	peg_heap* src = &(peg_array[source_peg-1]);
	peg_heap* dest = &(peg_array[dest_peg-1]);
	
	unsigned int disc_radius = src->returnMin();

	while (disc_radius != cur_disc_size) {
		// Wrong disc! get rid of it and then try again
		
		if (disc_radius == 0) break;
			
		for (int i = 1; i <= num_pegs; i++) {
			// check all other pegs
			if (i != source_peg && i != dest_peg) {
				if ( (peg_array[i-1].returnMin() == disc_radius + 1) || (peg_array[i-1].isEmpty()) ) {
					makeAMove(peg_array, num_pegs, source_peg, i, disc_radius, discs);
				}
			}
		}
		
		//update disc_radius
		disc_radius = src->returnMin();
	}
	
	// if this is the right disc
	if (disc_radius == cur_disc_size) {
		// check if you can add it to the target
		bool success = dest->addToTop(disc_radius);	
		// If success move on, else
		if(!success) { 
			// get rid of the blocking disc
			// find out where to move it
			// Find the peg with the disc radius just greater than the top one of this peg
			for (int i = 1; i <= num_pegs; i++) {
				// check all other pegs
				if (i != source_peg && i != dest_peg) {
					if (peg_array[i-1].returnMin() == dest->returnMin() + 1 || peg_array[i-1].isEmpty()) {
						makeAMove(peg_array, num_pegs, dest_peg, i, dest->returnMin(), discs);
					}
				}
			}
		}
		else {
			// Move worked! - remove the disc from its current position
			src->extractMin();
			// update new position
			discs[cur_disc_size-1] = dest_peg;
			printf("Move: %d to %d\n", source_peg, dest_peg);
			//printf("discs[%d] = %d\n", cur_disc_size-1, discs[cur_disc_size-1]);
		}		
	}
	else {
		//printf("blew it dude!\n");
	}
		
}


/* 
 *	Tower of Hanoi problem.
 *	N discs distributed over K pegs
 *	Solve for the minimum number of moves
 *	I know there's a better way to do this.. overthinking..
 */
int main() {
	int n = 0;
	int k = 0;
	
	// Take in N - number of discs
	scanf("%d", &n);
	
	// Now k - number of pegs
	scanf("%d", &k);
	
	unsigned int* discs = 	(unsigned int*) malloc( n * sizeof(unsigned int) );
	unsigned int* discs_final = (unsigned int*) malloc( n * sizeof(unsigned int) );
	
		// Initialize peg_heaps
	peg_heap pegs[k];
	
	// First line - for each disc
	for (int i = 0; i < n; i++) {
		scanf("%u", &discs[i]);
		pegs[discs[i]-1].addElem(i+1);
		
	}
	
	// Second line - final pos 
	for (int i = 0; i < n; i++) {
		scanf("%u", &discs_final[i]);
	}
	
	// Now we've got the input
	// scan backwards through the target
	for (int i = n-1; i >= 0; i--) {
		// My aim should be to meet each target 
		// from the larger disc to the smaller.	
		
		// print all pegs to see what just happened?!
		//for (int j = 0; j < k; j++) {
		//	pegs[j].print();
		//}
		
		unsigned int cur_peg = discs[i];
		unsigned int target_peg = discs_final[i];
		
		//printf("Trying: %d to %d --- Disc:%d\n", cur_peg, target_peg, i+1);
		
		makeAMove(pegs, k, cur_peg, target_peg, i+1, discs);	
	}
	
	free(discs);
	free(discs_final);
	
	return 0;
}