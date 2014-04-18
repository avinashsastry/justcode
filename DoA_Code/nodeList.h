#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class node {

// Generally not a good thing to have public variables
// This case, I like though. Makes it much easier.
// And I don't like using friends.	
public:
	int v;
	node* prevNode;
	node* nextNode;

	node(int value, node* prev, node* next);
	~node();

};

class nodeList {

private: 
	node* head;
	node* tail;

public:
	nodeList(int* values, unsigned int length);
	~nodeList();
	
	/* 
	 * Returns a node at a zero-indexed position i 
	 */
	node* getNodeAtIndex(unsigned int i);
	
	/* 
	 * Appends a node to the end of the list
	 */
	void appendNode(node* newNode);
	
	/* 
	 * Inserts a node at zero-indexed position i
	 */
	void insertNodeAtIndex(node* newNode, unsigned int i);
	
	/* 
	 * Deletes the current Head of the list
	 */
	void deleteNodeAtHead();
	
	/* 
	 * Deletes the current tail of the list
	 */
	void deleteNodeAtTail();
	
	/* 
	 * Deletes a node at zero-indexed position i
	 */
	void deleteNodeAtIndex(unsigned int i);
	
	/* 
	 * Deletes a node by its address
	 */
	void deleteNode(node* delNode);
	
	/* 
	 * Prints out the values of all nodes in the list from head to tail
	 */
	void printList();
	
	/* 
	 * reverse a linked list in place
	 */
	void reverse();
};
	