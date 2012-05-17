#include <stdio.h>
#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <assert.h>

// Constructor
void stackNew(stack* s, int elemSize, void (*freefn)(void*)) {
	
	assert(s != NULL);
	assert(elemSize > 0);

	s->elemSize = elemSize;
	s->logicallength = 0;
	s->allocatedlength = 4;							// use a default length of 4
	s->elems = (int*) malloc(4 * elemSize);
	assert(s->elems != NULL);
	
	s->freefn = freefn;
}

// Destructor
void stackDispose(stack* s) {
	if (!s) return;
	if (s->freefn != NULL) {
		for (int i = 0; i < s->logicallength; i++) {
			s->freefn( (char*) s->elems + i*s->elemSize );
		}
	}
	free(s->elems);
	// NOTE: Do not free "stack", because it is not explicitly malloc-ed
}

// Methods

// Utility method to allocate more memory for the stack
// NOTE: static for a function (variable, too, I guess)
// is like "private" for a particular file. It is an
// "internal" function.
static void stackGrow(stack* s) {
		
		s->allocatedlength *= 2;						// double alloc length
		s->elems = realloc(s->elems, s->allocatedlength * s->elemSize);	// only in C, not C++
		
		// NOTE: realloc will return the same address with a new sized block
		// if it can find the memory in place, else,
		// it will call malloc + memove, free s->elems, and return the new pointer
		
		// Special Note: realloc defaults to malloc if s->elems == NULL
		// which means you actually never need to use malloc :)
		
		// Catch the mem-fail
		assert(s->elems != NULL);
}

// stackPush - adds data onto the stack
// allocates more memory if data doesn't fit
void stackPush(stack* s, void* elemAddr) {
	
	// Check for memory first
	if (s->logicallength == s->allocatedlength) {
		//reallocate
		stackGrow(s);
	}
	
	void* target = (char*) s->elems + (s->logicallength * s->elemSize);
	memcpy(target, elemAddr, s->elemSize);
	s->logicallength++;
}

// Pop out the last element that was added to the heap
// does it also handle memory? Reduce allocated length each time it crosses some threshold?
void stackPop(stack* s, void* elemAddr) {
	assert (s->logicallength > 0);
	s->logicallength--;	
	void* source = (char*) s->elems + (s->logicallength * s->elemSize);
	memcpy(elemAddr, source, s->elemSize);
}

void stringFree(void* x) {
	// Some epic de-referencing to free the string
	// that is contained in the pointer
	free( *(char**) x);	
}

// test code
int main() {
	stack stringStack;
	char* friends[3] = {"Al", "Bob", "Carl"};
	
	stackNew(&stringStack, sizeof(char*), stringFree);
	
	for (int i = 0; i < 3; i++) {
		char* copy = strdup(friends[i]);
		printf("Push: %s\n", copy);
		stackPush(&stringStack, &copy);
	}
	
	char* name;
	for (int i = 0; i < 3; i++) {
		stackPop(&stringStack, &name);
		printf("Pop: %s\n", name);
	}
	free(name);
	
	stackDispose(&stringStack);
}