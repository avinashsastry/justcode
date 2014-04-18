
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "graph.h"
	
// Dijkstra's algo for a graph - atleast that's what I'm going for :)
int main() {

	graph mygraph = graph();
	
	graphNode node1(1);
	graphNode node2(2);
	graphNode node3(3);
	graphNode node4(4);
	graphNode node5(5);
	
	mygraph.addNode(&node1);
	mygraph.addNode(&node2);
	mygraph.addNode(&node3);
	mygraph.addNode(&node4);
	mygraph.addNode(&node5);
	
	mygraph.addEdgeFromAtoB(&node1, &node2);
	mygraph.addEdgeFromAtoB(&node1, &node5);
	mygraph.addEdgeFromAtoB(&node2, &node3);
	mygraph.addEdgeFromAtoB(&node3, &node4);
	mygraph.addEdgeFromAtoB(&node5, &node4);
	
	mygraph.print();
	
	graphNode* tempNode = mygraph.getNodeWithKey(5);
	if (tempNode) printf("Found: %d\n", tempNode->getKey());
	return 0;
}