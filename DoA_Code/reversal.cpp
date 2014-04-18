#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class node {
	public:
	int val;
	node* nextNode;
};


node* reverseList(node* orig_list) {
	if (!orig_list) return NULL;
	// 1. two pointers
	// 2. reverse the next pointer at each step
	
	node* tempNode = orig_list;
	node* tempNode2 = tempNode->nextNode;
	
	if (tempNode2) {
		node* tempNode3 = tempNode2->nextNode;		
		if (tempNode3) {
			tempNode->nextNode = NULL;
			while (tempNode3 != NULL) {
				tempNode2->nextNode = tempNode;
				tempNode = tempNode2;
				tempNode2 = tempNode3;
				tempNode3 = tempNode3->nextNode;
			}
			
			tempNode2->nextNode = tempNode;
			return tempNode2;
		}
		else {
			tempNode->nextNode = NULL;
			tempNode2->nextNode = tempNode;
			return tempNode2;
		}
	}
	else {
		return tempNode;
	}
}

// Lol, code to reverse a singly-linked list.
// I cannot believe I struggled for an hour for this!
// one pointer mistake and it's better to start from scratch. 
// Seriously.
int main () {
	
	// Initialize a list
	node array[10];
	
	for (int i = 0; i < 10; i++) {
		array[i].val = i;
		if (i < 10-1) {
			array[i].nextNode = &array[i+1];
		}
		else {
			array[i].nextNode = NULL;
		}
	}
	
	node* array2 = reverseList(array);
	
	for (node* i = array2; i!=NULL; i = i->nextNode) {
		printf("%d ", i->val);
	}
	printf("\n");
	return 0;
}