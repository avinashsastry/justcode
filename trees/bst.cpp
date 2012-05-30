#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class node {

	private:
	int value;
	node* parent;
	node* left;
	node* right;
	
	public:
	node(node* Parent = NULL, int Value = 0) {
		parent = Parent;
		value = Value;
	}
	
	~node() {
		delete parent;
		delete left;
		delete right;
	}
	
	int getValue() {
		return value;
	}
	
	node* getParent() {
		if (parent) return parent;
		else return NULL;
	}
	
	node* getLeft() {
		if (left) return left;
		else return NULL;
	}
	
	node* getRight() {
		if (right) return right;
		else return NULL;
	}	
	
	void addNode(int newValue) {
		if (newValue <= value) {
			if (left) {
				left->addNode(newValue);
			}
			else {
				left = new node(this, newValue);
			}	
		}
		else { 
			if (right) {
				right->addNode(newValue);
			}
			else {
				right = new node(this, newValue);
			}
		}
	}
	
	node* search(int searchValue) {
		if (searchValue == value) {
			return this;
		}
		else if (searchValue < value) {
			if (left) return left->search(searchValue);
			else return NULL;
		}
		else {
			if (right) return right->search(searchValue);
			else return NULL;
		}
	}
	
	void print() {
		if (left) left->print();
		printf("%d \n", value);
		if (right) right->print();
	}
	
	void printValue() {
		printf("Value: %d\n", value);
	}
};

class BinarySearchTree {
	
	private:
	node* root;
	unsigned int size;
	
	public:
	BinarySearchTree(node* root=NULL) {
		root = NULL;
		size = 0;
	}
	
	~BinarySearchTree() {
	}
	
	node* getRoot() {
		if (root) return root;
		else return NULL;
	}
	
	unsigned int getSize() {
		return size;
	}
	
	void addNode(int value) {
		if (!root) {
			root = new node(NULL, value);
		}
		else {
			root->addNode(value);
		}
		
		size++;
	}
	
	// binary search
	node* getNodeByValue(int value) {
		if (root) return root->search(value);
		else return NULL;
	}
	
	void deleteNodeByValue(int value) {
		//root->deleteNode(value);
	}
	
	void print() {
		root->print();
	}
	
};

// A simple example of a binary search tree
int main() {

	BinarySearchTree* bst = new BinarySearchTree(NULL);
	node* tempNode;
	
	bst->addNode(5);
	bst->addNode(3);
	bst->addNode(4);
	bst->addNode(7);
	bst->addNode(6);
	
	bst->print();
	
	tempNode = bst->getNodeByValue(9);
	if (tempNode)
		tempNode->printValue();
	else
		printf("Node not found!\n");
		
	tempNode = bst->getNodeByValue(7);
	if (tempNode)
		tempNode->printValue();
	else
		printf("Node not found!\n");

}