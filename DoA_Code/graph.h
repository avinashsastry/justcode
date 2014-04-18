#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "hashtable.h"

// Single unit of a graph
// It can have a key
// It can have connections with other nodes
// Outgoing and incoming - i.e. a directed graph node

class graphNode {

	private:
	int key;
	int value;
	
	unsigned int n_out;
	unsigned int n_in;
	
	// Unordered list of nodes with outgoing connections
	graphNode** out_edges;
	
	// Unordered list of nodes with incoming connections
	graphNode** in_edges;
	
	public:
	// Every node gets created with a UNIQUE key
	graphNode(int k, int v);
	~graphNode();
	
	int getKey();
	int getValue();
	
	unsigned int getNumOutEdges();
	unsigned int getNumInEdges();
	
	graphNode* outEdgeAtIndex(unsigned int i);
	graphNode* inEdgeAtIndex(unsigned int i);
	
	void addEdgeTo(graphNode* B);
	void addEdgeFrom(graphNode* B);
	
	// Maybe some day we can remove edges.. just not yet.
};

class graph {
	
	private:
	// Number of nodes
	int numNodes;
	unsigned int size;
	
	// Unordered array of all nodes
	graphNode** nodes;
	
	graphNode* BFS(graphNode* startNode, int key);
	
	graphNode* runDFS(hashTable exploredNodes, graphNode* startNode, int key);
	graphNode* DFS(graphNode* startNode, int key);
	
	graphNode* runDFS2(int* exploredNodes, int length, graphNode* startNode, int key);
	graphNode* DFS2(graphNode* startNode, int key);
	
	public:
	graph();
	~graph();
	
	graphNode* getNodeWithKey(int key);
	
	// I'm serious about the UNIQUE part.
	void addNode(graphNode* newNode);
	void addNode(int key, int value);
	void addEdgeFromAtoB(graphNode* A, graphNode* B);
	
	void initializeEdgesForNodeWithKey(int k, int diff);
	
	void print();
};

#endif