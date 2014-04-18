#include <stdio.h>
#include <stdlib.h>
#include <string.h>

list* result addlists(list* A, list* B) {
	if (!A && !B) return NULL;
	if (!A && B) return B;
	if (!B && A) return A;
	
	node* tempNode = A->head;
	node* tempNode2 = B->head;
	
	list* C = new list();
	
	int first = 0;
	int second = 0;
	int result = 0;
	int carry = 0;
	
	while (tempNode != NULL) {
		
		if (tempNode)
			first = tempNode->value;
		else
			first = 0;
			
		if (tempNode2)
			second = tempNode2->value;
		else
			second = 0;
		
		result = first + second + carry;
		
		if (result > 9)
			result = result - 10;
			carry = 1;
		}
		
		// Create new node for result
		list->addNode(result);
		
		if (tempNode)
			tempNode = tempNode->next;
		tempNode2 = tempNode2->next
	}
	
}

int main() {
	
	
	return 0;
}