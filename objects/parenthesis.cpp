#include <iostream>

void printPar(int l, int r, char* str, int count) {
	
	printf("%s: l=%d, r=%d, count=%d\n", __func__, l, r, count);
	
	if (!str) return;
	if (l < 0 || r < l) return;
	
	if (l == 0 && r == 0)
		printf("%s\n", str);
	
	if (l > 0) {
		str[count] = '(';
		printPar( l-1, r, str, count+1);
	}
	
	if (r > l) {
		str[count] = ')';
		printPar( l, r-1, str, count+1);
	}
}

void printPar(int n) {
	char str[n*2];
	int count = 0;
	
	printPar(n, n, str, 0);
}

// To print all possible pairs of n-pairs of parenthesis
int main() {
	printPar(3);
}