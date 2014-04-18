#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM 		100000
#define MAX_DIFF  		1000000000

// value for hash function - prime number!
#define MOD_VALUE		4999
#define ARRAY_LENGTH	100

// simple class to replicate the behaviour of a hashtable
class hashTable {
	private: 
	// array of int pointers
	int** array;
	int* lengths;
	
	public:
	hashTable();
	~hashTable();
	
	int hashFunction(int value);
	void addValue(int value);
	int findElement(int value);
	int getDiffPairs(unsigned int k);
	void print();
};

#endif
