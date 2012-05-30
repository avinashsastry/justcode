#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class stack {

	private:
	int* array;
	
	public:
	stack(int* arrayPointer) {
		// Initialize - we'll use the first element of the array for length
		array = arrayPointer;
		array[0] = 0;
	}
	
	~stack() {
	}
	
	void push(int value) {
		if (!array) return;
		
		array[array[0]+1] = value;
		array[0]++;
	}
	
	int pop() {
		if (!array) return -1;
		
		int value = array[array[0]];
		array[array[0]] = 0;	//reset? not reqd. really
		array[0]--;
		
		return value;
	}
	
	bool isEmpty() {
		if (array[0] == 0) return true;
		else return false;
	}
};


class queue{

	private:
	stack* stack1;
	stack* stack2;
	
	public:
	queue(int* arraypointer, int n) {
		stack1 = new stack(arraypointer);
		stack2 = new stack(arraypointer + n/2);
	}
	
	~queue() {

	}
	
	void push(int value) {
		stack1->push(value);
	}
	
	int pop() {
		while (!stack1->isEmpty()) {
			stack2->push(stack1->pop());
		}
		
		int value = stack2->pop();
		
		while(!stack2->isEmpty()) {
			stack1->push(stack2->pop());
		}
		
		return value;
	}
};

// 1. use a single array to implement three (multiple) stacks
// 2. One array but subdivide it into n parts.

// part 2 
// use 2 stacks to create a queue

int main() {

	// Start by implementing 1 stack?
	int array[300];
	
	stack one = stack(array);
	stack two = stack(array+100);
	stack three = stack(array+200);
	
	one.push(1);
	two.push(2);
	three.push(3);
	one.push(5);
	
	// Pop some stuff 
	printf("Pop: %d \n", one.pop());
	printf("Pop: %d \n", two.pop());
	printf("Pop: %d \n", three.pop());
	
	int array2[100];
	queue Q = queue(array2, 10);
	
	Q.push(5);
	Q.push(7);
	Q.push(11);
	
	printf("Pop: %d\n", Q.pop());
	printf("Pop: %d\n", Q.pop());
	printf("Pop: %d\n", Q.pop());
	
	
	return 0;
}