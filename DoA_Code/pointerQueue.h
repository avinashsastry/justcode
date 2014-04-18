#ifndef POINTERQUEUE_H
#define POINTERQUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *	A simple  integer queue, nothing fancy really.
 *  FIFO
 */
 
template <class object> 
class pointerQueue {

private:
	object** array;
	unsigned int length;
	unsigned int max_length;
	
public:
	pointerQueue(unsigned int max_len);
	~pointerQueue();
	
	void push(object* o);
	object* pop();
	object* peek();
	bool isEmpty();
	
	void print();
};

#endif