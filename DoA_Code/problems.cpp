#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "nodeList.h"

#define MAX_PROBS

// Function solve()
int solve(nodeList* problems, node* problem, node* prevProblem, int k) {
	if (!problems) return 0;
	if (!problem) return 1;
	
	node* prev = prevProblem;
	node* next = problem->nextNode;
	
	if (prev) {
		if (prev->v >= (problem->v + k) || prev->v <= (problem->v - k)) {
			// solve it by deleting it
			solve(problems, next, problem, k);
			problems->deleteNode(problem);
		}
		else {
			solve(problems, next, prev, k);
		}
	}
	else {
		//head - go ahead and solve it
		solve(problems, next, problem, k);
		problems->deleteNode(problem);
	}
	
	return 1;
}
int solveAll(nodeList* problems, int k, int i) {
	if (!problems) return 0;
	
	int numDays = 0;
	int currentNode = 0;
	node* tempNode = problems->getNodeAtIndex(i);
	
	while (tempNode != NULL) {
		numDays += solve(problems, tempNode, NULL, k);
		tempNode = problems->getNodeAtIndex(0);
	}
	return numDays;
}

int main() {
	
	int t = 0;
	scanf("%d", &t);
	
	for (int m = 0; m < t; m++) {
		int n = 0;
		scanf("%d", &n);
		
		int k = 0;
		scanf("%d", &k);
		
		int minDays = 0;
		
		int* array = (int*) malloc ( n * sizeof(int) );
		
		for (int i = 0; i < n; i++) {
			scanf("%d", &array[i]);
		}
		
		for (int i = 0; i < n; i++) {
			// Create list
			nodeList* problems = new nodeList(array, n);
			
			// Solve all
			int numDays = 0;
			numDays = solveAll(problems, k, i);
			
			if (numDays != 0) { 
				if (numDays < minDays) minDays = numDays;
			}
		}
		
		printf("%d\n", numDays);
	}
	return 0;
}