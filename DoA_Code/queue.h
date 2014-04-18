#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 *	A simple  integer queue, nothing fancy really.
 *  FIFO
 */
 
template <class object> 
class queue {

private:
	object* array;
	unsigned int length;
	unsigned int max_length;
	
public:
	queue(unsigned int max_len);
	~queue();
	
	void push(object o);
	object pop();
	object peek();
	bool isEmpty();
	
	void print();
};

#endif