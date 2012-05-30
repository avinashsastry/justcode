#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_EDGES	10
#define MAX_NODES	100

// Single unit of a graph
// It can have a key
// It can have connections with other nodes
// Outgoing and incoming - i.e. a directed graph node
class node {

	private:
	int key;
	
	unsigned int n_out;
	unsigned int n_in;
	
	// Unordered list of nodes with outgoing connections
	node** out_edges;
	
	// Unordered list of nodes with incoming connections
	node** in_edges;
	
	public:
	// Every node gets created with a UNIQUE key
	node(int keyValue) {
		key = keyValue;
		n_out = 0;
		n_in = 0;
		
		out_edges = (node**) malloc( MAX_EDGES * sizeof(node*) );
		in_edges = (node**) malloc( MAX_EDGES * sizeof(node*) );
	}
	
	~node() {
		if (out_edges) free(out_edges);
		if (in_edges) free(in_edges);
	}
	
	int getKey() {
		return key;
	}
	
	unsigned int getNumOutEdges() {
		return n_out;
	}
	
	unsigned int getNumInEdges() {
		return n_in;
	}
	
	node* outEdgeAtIndex(unsigned int i) {
		if (out_edges[i]) return out_edges[i];
	}
	
	node* inEdgeAtIndex(unsigned int i) {
		if (in_edges[i]) return in_edges[i];
	}
	
	void addEdgeTo(node* B) {
		if (!B) return;
		out_edges[n_out-1] = B;
		n_out++;
	}
	
	void addEdgeFrom(node* B) {
		if (!B) return;
		in_edges[n_in-1] = B;
		n_in++;
	}
	
	// Maybe some day we can rmeove edges.
	// Not today :P
};

class graph {
	
	private:
	// Number of nodes
	int numNodes;
	
	// Unordered array of all nodes
	node** nodes;
	
	node* BFS(int key) {
	
		// Create an array of nodes
		node** nodeList = (node**) malloc( MAX_NODES * sizeof(node*) );
		int node_count = 0;
		
		// Start with the very first node
		nodeList[node_count] = nodes[0];
		node_count++;
		
		while (node_count < numNodes) {
			node* currentNode = nodeList[node_count];
			
			if (currentNode->getKey() == key) {
				if (nodeList) free(nodeList);	
				return currentNode;
			}
			
			for (int i = 0; i < currentNode->getNumOutEdges(); i++) {
				node* nextNode = currentNode->outEdgeAtIndex(i);
				nodeList[node_count + i] = nextNode;
			}
			node_count++;
		}
		
		if (nodeList) free(nodeList);
		return NULL;	
	}
	
	node* DFS(int key) {
	}
	
	public:
	graph() {
		numNodes = 0;
		nodes = (node**) malloc( MAX_NODES * sizeof(node*) );
	}
	
	~graph() {
		if (nodes) free(nodes);
	}
	
	node* getNodeWithKey(int key) {
		// Use either breadth-first or depth-first
	}
	
	// temporary function to add nodes without checking for the key
	void
	
	// I'm serious about the UNIQUE part.
	void addNodeWithKey(int key) {
		node* tempNode;
		
		tempNode = getNodeWithKey(key);
		if (!tempNode) {
			tempNode = new node(key);
			nodes[numNodes] = tempNode;
			numNodes++;
		}
		else {
			printf("Error: duplicate node - Not adding!");
		}
	}
	
	void addEdgeFromAtoB(node* A, node* B) {
	}
};

// Dijkstra's algo for a graph
int main() {
	
}