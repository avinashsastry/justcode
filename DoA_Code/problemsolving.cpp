#include <iostream>
#include <stdlib.h>
#include <string.h>

using namespace std;

#include "graph.h"

int solveNode(graphNode* node, int numNodes, bool* solvedProblems) {
	if (!node) return 0;
	
	//printf("Entering node: (%d, %d)\n", node->getKey(), node->getValue());
	int maxNodes = -1;
	int maxInd = -1;
	
	for (int i = 0; i < node->getNumOutEdges(); i++) {
		graphNode* tempNode = node->outEdgeAtIndex(i);
		if (!solvedProblems[tempNode->getKey()]) {
			int nNodes = solveNode(tempNode, numNodes, solvedProblems);
			if (nNodes > maxNodes) {
				maxNodes = nNodes;
				maxInd = i;
			}
		}
	}
	
	if (maxInd >= 0) {
		graphNode* tempNode = node->outEdgeAtIndex(maxInd);
		solvedProblems[tempNode->getKey()] = true;
		printf("CurrNode: (%d, %d), Solving: (%d, %d) - maxInd: %d\n", node->getKey(), node->getValue(), tempNode->getKey(), tempNode->getValue(), maxInd);
	}

	// mark this problem as solved and return
	return maxNodes + numNodes + 1;
}

// Returns the minimum number of "days"
// that it takes to traverse through a graph
int solve(graph* problems, int n) {

	bool solvedProblems[n+1];
	memset(solvedProblems, 0, (n+1)*sizeof(bool));
	
	int numProbs = 0;
	int numDays = 0;
	graphNode* startPoint = problems->getNodeWithKey(0);
	
	while (numProbs < n) {
		// At each step we try and remove the max number of nodes
		// That's our greedy criterion
		numProbs += solveNode(startPoint, 0, solvedProblems);
		numDays++;
		
		//printf("%d. NumSolved: %d\n", numDays, numProbs);
	}
	
	return numDays;
}

int main() {
	
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i++) {
		int n, k;
		graph* problems = new graph();
		// Add an imaginary starting node that should be connected to all nodes
		problems->addNode(0, 10000);

		cin >> n >> k;
		
		for(int j = 0; j < n; j++) {
			int x;
			cin >> x;
			problems->addNode(j+1, x);
			problems->initializeEdgesForNodeWithKey(j+1, k);	
		}
		
		//problems->print();
		int numDays = solve(problems, n);
		printf("%d\n", numDays);
	}
	
	return 0;
}