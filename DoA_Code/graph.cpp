#include "graph.h"
#include "queue.h"

#define MAX_EDGES	1000
#define MAX_NODES	10000

	graphNode::graphNode(int k, int v) {
		key = k;
		value = v;
		n_out = 0;
		n_in = 0;
		
		out_edges = (graphNode**) malloc( MAX_EDGES * sizeof(graphNode*) );
		in_edges = (graphNode**) malloc( MAX_EDGES * sizeof(graphNode*) );
	}
	
	graphNode::~graphNode() {
		if (out_edges) free(out_edges);
		if (in_edges) free(in_edges);
	}
	
	int graphNode::getKey() {
		return key;
	}
	
	int graphNode::getValue() {
		return value;
	}
	
	unsigned int graphNode::getNumOutEdges() {
		return n_out;
	}
	
	unsigned int graphNode::getNumInEdges() {
		return n_in;
	}
	
	graphNode* 	graphNode::outEdgeAtIndex(unsigned int i) {
		if (out_edges[i]) return out_edges[i];
		else return NULL;
	}
	
	graphNode* 	graphNode::inEdgeAtIndex(unsigned int i) {
		if (in_edges[i]) return in_edges[i];
		else return NULL;
	}
	
	void graphNode::addEdgeTo(graphNode* B) {
		if (!B) return;
		out_edges[n_out] = B;
		n_out++;
	}
	
	void graphNode::addEdgeFrom(graphNode* B) {
		if (!B) return;
		in_edges[n_in] = B;
		n_in++;
	}


/* 
 *	Graph functions
 */
	graph::graph() {
		numNodes = 0;
		nodes = (graphNode**) malloc( MAX_NODES * sizeof(graphNode*) );
	}
	
	graph::~graph() {
		if (nodes) {
			for (int i = 0; i < numNodes; i++) {
				if (nodes[i]) delete nodes[i];
			}
		free(nodes);
		}
	}
	
	graphNode* graph::BFS(graphNode* startNode, int key) {
		if (!startNode) return NULL;
		
		// Create an empty set of explored nodes
		hashTable exploredNodes = hashTable();
		
		// Create a queue for exploring nodes
		queue<graphNode*> nodeQ(100);
		
		// Initialize:
		// 1. Add the first node
		nodeQ.push(startNode);
		
		// While we still have nodes to process
		while(!nodeQ.isEmpty()) {
			graphNode* tempNode = nodeQ.pop();
			for (int i = 0; i < tempNode->getNumOutEdges(); i++) {
				graphNode* exploredNode = tempNode->outEdgeAtIndex(i);
				if (exploredNodes.findElement(exploredNode->getKey()) == 0) {
					if (exploredNode->getKey() == key) {
						//found!
						return exploredNode;
					}
					else {
						// continue searching
						// and mark this node as explored
						nodeQ.push(exploredNode);
						exploredNodes.addValue(exploredNode->getKey());				
					}
				}
				else {
					// Already explored!
				}
			}
		}
		return NULL;
	}
	
	graphNode* graph::runDFS(hashTable exploredNodes, graphNode* startNode, int key) {
		
		printf("Exploring: %d\n", startNode->getKey());
		
		if (startNode->getKey() == key) return startNode;
		exploredNodes.addValue(startNode->getKey());
		
		graphNode* exploredNode = NULL;
		graphNode* returnNode = NULL;
		
		// start from the first node - for each edge
		for (int i = 0; i < startNode->getNumOutEdges(); i++) {	
			exploredNode = startNode->outEdgeAtIndex(i);
			if (exploredNodes.findElement(exploredNode->getKey()) == 0) {
				returnNode = runDFS(exploredNodes, exploredNode, key);
				if (returnNode) {
					printf("Found!");
					 return returnNode;
				}
			}
		}
		printf("returning NULL from %d\n", startNode->getKey());
		return NULL;
	}
	
	// Depth-first search on a graph
	graphNode* graph::DFS(graphNode* startNode, int key) {
		if (!startNode) return NULL;
		
		hashTable exploredNodes;
		return runDFS(exploredNodes, startNode, key);
	}
	
	
	graphNode* graph::runDFS2(int* exploredNodes, int length, graphNode* startNode, int key) {
		if (!exploredNodes) return NULL;
		if (!startNode) return NULL;
		
			printf("Exploring: %d\n", startNode->getKey());
		// Check start node
		if (startNode->getKey() == key) return startNode;
		
		exploredNodes[length] = startNode->getKey();
		length++;
		
		graphNode* exploredNode = NULL;
		graphNode* returnNode = NULL;
		
		for (int i = 0; i < startNode->getNumOutEdges(); i++) {
			exploredNode = startNode->outEdgeAtIndex(i);
			bool nodeExplored = false;
			// Check if node explored node has already been seen
			for (int j = 0; j < length; j++) {
				if (exploredNodes[j] == exploredNode->getKey()) {
					nodeExplored = true;
				}
			}
			
			if (!nodeExplored) {
				returnNode = runDFS2(exploredNodes, length, exploredNode, key);
				if (returnNode) {
					printf("Found!");
					return returnNode;
				}
			}
		}
		printf("returning NULL from %d\n", startNode->getKey());
		return NULL;
	}	
	
	graphNode* graph::DFS2(graphNode* startNode, int key) {
		int exploredNodes[MAX_NODES];
		int length = 0;
		
		return runDFS2(exploredNodes, length, startNode, key);
	}
	
	graphNode*  graph::getNodeWithKey(int key) {
		return nodes[key];
	}
	
	void graph::addNode(graphNode* newNode) {
		if (!newNode) return;
		
		if (numNodes < MAX_NODES) {
			nodes[numNodes] = newNode;
			numNodes++;
		}
	}
	
	// I'm serious about the UNIQUE part.
	void graph::addNode(int key, int value) {
		graphNode* tempNode = NULL;
	
		if (!tempNode) {
			tempNode = new graphNode(key, value);
			nodes[numNodes] = tempNode;
			numNodes++;
		}
		else {
			printf("Error: duplicate node - Not adding!");
		}
	}
	
	void graph::addEdgeFromAtoB(graphNode* A, graphNode* B) {
		if (!A) return;
		if (!B) return;
		
		A->addEdgeTo(B);
		B->addEdgeFrom(A);
	}
	
	void graph::print() {
		printf("Num Nodes: %d\n", numNodes);
		for (int i = 0; i < numNodes; i++) {
			printf("---------\n");
			printf("(%d, %d) \n", nodes[i]->getKey(), nodes[i]->getValue());
			for (int j = 0; j < nodes[i]->getNumOutEdges(); j++) {
				graphNode* tempNode = nodes[i]->outEdgeAtIndex(j);
				printf("Edges to: (%d, %d)\n", tempNode->getKey(), tempNode->getValue());
			}
			
		}
		printf("\n");
	}
	
	void graph::initializeEdgesForNodeWithKey(int k, int diff) {
		// Make an edge between each node
		// less than the current one, 
		// as long as the difference in value is less than k
		
		// Since key is 1-indexed
		graphNode* currNode = nodes[k];
		for (int i = 0; i < k; i++) {
			graphNode* tempNode = nodes[i];
			int j = currNode->getValue() - tempNode->getValue();
			if (j < 0) j = -j;
			
			if (j >= diff) addEdgeFromAtoB(tempNode, currNode);
		}
	}