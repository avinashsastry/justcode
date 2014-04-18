#include "hashtable.h"

hashTable::hashTable() {
	array = (int**) malloc ( MOD_VALUE * sizeof(int*) );
	memset(array, 0, MOD_VALUE * sizeof(int*));
	
	lengths = (int*) malloc ( MOD_VALUE * sizeof(int) );
	memset(lengths, 0, MOD_VALUE * sizeof(int));
}

hashTable::~hashTable() {
	for (int i = 0; i < MOD_VALUE; i++) {
		if (array[i]) free(array[i]);
	}
	free(array);
}

int hashTable::hashFunction(int value) {
	return (value % MOD_VALUE);
}

void hashTable::addValue(int value) {
	int i = hashFunction(value);
	if (!array[i]) {
		array[i] = (int*) malloc(ARRAY_LENGTH * sizeof(int));
	}
	array[i][lengths[i]] = value;
	lengths[i]++;
}

int hashTable::findElement(int value) {
	int hash = hashFunction(value);
	
	for (int i = 0; i < lengths[hash]; i++) {
		if (array[hash][i] == value) return value;
	}
	return 0;
}

int hashTable::getDiffPairs(unsigned int k) {
	if (!array) return 0;
	
	int numPairs = 0;
	hashTable H = hashTable();
	
	for (int i = 0; i < MOD_VALUE; i++) {
		for (int j = 0; j < lengths[i]; j++) {
			if (array[i]) {
				int x1 = array[i][j];
				//printf("Searching: %d\n", x1);
				H.addValue(x1);
				
				// two possibilities
				int x2 = x1+k;
				int x3 = x1-k;
				//printf("Possible: %d, %d\n", x2, x3);
				
				// Check both
				int y = findElement(x2);
				if (y != 0) {
					//printf("y: %d\n", y);
					if (H.findElement(x2) == 0) {
						numPairs++;
					}
				}
				
				y = findElement(x3);
				if (y != 0) {
					//printf("y: %d\n", y);
					if (H.findElement(x3) == 0) {
						numPairs++;
					}
				}
			}
		}
	}
	return numPairs;
}	

// print all elements
void hashTable::print() {
	for (int i =0; i < MOD_VALUE; i++) {
		for (int j = 0; j < lengths[i]; j++) {
			if (array[i]) 
				printf("array[i][j]: %d\n", array[i][j]);
		}
	}
}