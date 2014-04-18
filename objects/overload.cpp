#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>

using namespace std;
class node { 
	public:
	unsigned int id;
	int value;
	
	node* left;
	node* right;
	
	node(int i, int v, node* leftNode, node* rightNode) {
		id = i;
		value = v;
		left = leftNode;
		right = rightNode;
	}
	
	~node() {
	}
	
	node& operator=(const node &otherNode) {
		if (this != &otherNode) {
			memcpy(this, &otherNode, sizeof(node));
			return *this;
		}
		else {
			return *this;
		}
	}
};

int main() {
	
	node* lefty = new node(1, 1000, NULL, NULL);
	node* righty = new node(3, 3000, NULL, NULL);
	
	node noddy(2, 5000, lefty, righty);
	
	cout << noddy.id << noddy.value << noddy.left->id << noddy.right->id << endl;
	
	node noddy2(23, 4000, lefty, righty);
	noddy2 = noddy;
	
	cout << noddy2.id << noddy2.value << noddy2.left->id << noddy2.right->id << endl;
	
}