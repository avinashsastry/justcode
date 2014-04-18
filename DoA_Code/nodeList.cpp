#include "nodeList.h"


// Constructor
node::node(int value, node* prev=NULL, node* next=NULL) {
	prevNode = prev;
	nextNode = next;
	v = value;
}

// Destructor
node::~node() {
	prevNode = NULL;
	nextNode = NULL;
}

nodeList::nodeList(int* values, unsigned int length) {
	
	head = NULL;
	tail = NULL;
	
	for (unsigned int i = 0; i < length; i++) {
		node* tempNode = new node(values[i]);
		appendNode(tempNode);
	}
}

nodeList::~nodeList() {
	for (node* tempNode = head; tempNode != NULL; tempNode = tempNode->nextNode) {
		delete tempNode;
	}
	head = NULL;
	tail = NULL;
}

// Get node at index i - zero-indexed!
	node* nodeList::getNodeAtIndex(unsigned int i) {
	unsigned int j = 0;
	node* tempNode;
	
	for (tempNode = head; tempNode != NULL; tempNode = tempNode->nextNode) {
		if (j == i) break;
		j++;
	}
	
	if (tempNode) {
		//printf("Found: %d\n", tempNode->v);
		return tempNode;
	}
	else {
		//printf("Not found!\n");
		return NULL;
	}
}

// Appends a node to our linked list
void nodeList::appendNode(node* newNode) {
	
	node* tempNode = tail;
	
	if (tempNode) {
		tempNode->nextNode = newNode;
		newNode->prevNode = tempNode;
		newNode->nextNode = NULL;
		
		tail = newNode;
	}
	else {
		// This is the first node
		newNode->nextNode = NULL;
		newNode->prevNode = NULL;
		
		head = newNode;
		tail = newNode;
	}
}

// Insert node at a given index.
// This is also zero-indexed!
void nodeList::insertNodeAtIndex(node* newNode, unsigned int i) {
	
	if (!newNode) return;
	
	// Insert as head
	if (i == 0) {
		newNode->prevNode = NULL;
		newNode->nextNode = head;
		head->prevNode = newNode;
		head = newNode;
	}
	else {
		node* tempNode = getNodeAtIndex(i-1);
		if (tempNode) {
			if (tempNode->nextNode) {
				newNode->prevNode = tempNode;
				newNode->nextNode = tempNode->nextNode;
			
				node* tempNode2 = tempNode->nextNode;		
				tempNode2->prevNode = newNode;
				
				tempNode->nextNode = newNode;
			}
			else {
				// Last node in list.. just use append
				appendNode(newNode);
			}
		}
		else {
			// If node doesn't exist? Do nothing
		}
	}
}

// Delete node at Head;
void nodeList::deleteNodeAtHead() {
	node* currentHead = head;
	node* tempNode = currentHead->nextNode;

	if (tempNode) {
		tempNode->prevNode = NULL;
		head = tempNode;
	}
	else {
		// This is the only node
		head = NULL;
		tail = NULL;
	}

	delete currentHead;
}

// Delete node at tail
void nodeList::deleteNodeAtTail() {
	node* currentTail = tail;
	node* tempNode = currentTail->prevNode;
	
	if (tempNode) {
		tempNode->nextNode = NULL;
		tail = tempNode;
	}
	else {
		// Lone ranger of a node
		head = NULL;
		tail = NULL;
	}
	
	delete currentTail;
}

// Delete node at index i (again zero-indexed!)
void nodeList::deleteNodeAtIndex(unsigned int i) {
	node* tempNode = getNodeAtIndex(i);
	
	if (tempNode) {
		if (tempNode == head) {
			deleteNodeAtHead();
		}
		else if (tempNode == tail) {
			deleteNodeAtTail();
		}
		else {
			node* prev = tempNode->prevNode;
			node* next = tempNode->nextNode;
			
			prev->nextNode = next;
			next->prevNode = prev;
			
			// Free up memory - this could get ugly if I'm not careful
			delete tempNode;
		}
	}
	else {
		// Index out of bounds? Probably.. ignore pain!
	}
}

void nodeList::deleteNode(node* delNode) {
	if (!delNode) return;
	
	if (delNode == head) {
		deleteNodeAtHead();
	}
	else if (delNode == tail) {
		deleteNodeAtTail();
	}
	else {
		node* prev = delNode->prevNode;
		node* next = delNode->nextNode;
		
		prev->nextNode = next;
		next->prevNode = prev;
		
		// Free up memory - this could get ugly if I'm not careful
		delete delNode;
	}
}

// prints out the values in the node list
void nodeList::printList() {
	for (node* tempNode = head; tempNode != NULL; tempNode = tempNode->nextNode) {
		printf("%d ", tempNode->v);
	}
	printf("\n");	
}

void nodeList::reverse() {
	node* tempNode1 = head;
	node* tempNode2 = tail;
	
	if (tempNode1 != NULL && tempNode2 != NULL) {
		while (tempNode1 != tempNode2) {
			
			printList();
		
			// swap tempNode1 with tempNode2 
			int swap = tempNode1->v;
			tempNode1->v = tempNode2->v;
			tempNode2->v = swap;
			
			if (tempNode1->nextNode != tempNode2) {
				tempNode1 = tempNode1->nextNode;
				tempNode2 = tempNode2->prevNode;
			}
			else
				break;
		}
	}
}

#if 0
int main () {
	// Number of lines
	int n = 0;	
	printf("Enter number of lines: ");
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
	
		// Number of problems
		unsigned int num_prob = 0;
		printf("Enter number of problems: ");
		scanf("%d", &num_prob);
		
		// Enter value of K
		int K = 0;
		scanf("%d", &K);
		
		// Malloc the values array and set to 0
		unsigned int* v = (unsigned int*) malloc( num_prob * sizeof(unsigned int));
		memset(v, 0, num_prob * sizeof(unsigned int));
		
		printf("Enter V[i] for each problem: ");
		for (int j = 0; j < num_prob; j++) {
			scanf("%d", &v[j]);
			
			// Create node
			//node* tempNode = new node(v[j], NULL, NULL);
			// Add node to list
			//problems->appendNode(tempNode);
		}
		
		// Here we start
		// Create a list
		nodeList* problems = new nodeList(v, num_prob);
		
		node* tempNode = problems->getNodeAtIndex(0);
		tempNode = problems->getNodeAtIndex(1);
		tempNode = problems->getNodeAtIndex(2);
		tempNode = problems->getNodeAtIndex(3);
		
		tempNode = new node(10, NULL, NULL);
		problems->insertNodeAtIndex(tempNode, 1);
		
		problems->printList();
		
		problems->deleteNodeAtIndex(1);
		problems->printList();
		
		problems->deleteNodeAtIndex(1);
		problems->printList();
		
		problems->deleteNodeAtIndex(0);
		problems->printList();
		
		free(v);		
	}

	return 0;	
}
#endif
