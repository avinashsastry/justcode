#include <stdio.h>
#include <time.h>

int fib(int n) {
	if (n == 0) return 1;
	if (n == 1) return 1;
	else return (fib(n-1) + fib(n-2));
}

// yay recursion! Fibonacci numbers
int main() {
	
	time_t start, end;
	unsigned int fib = 1;
	unsigned int prevfib = 1;
	unsigned int prevfib2 = 1;
	
	time(&start);
	for (int i = 2; i < 50; i++) {
		if ( i == 0 ) fib = 1;
		else if ( i == 1 ) fib = 1;
		else {
			fib = prevfib + prevfib2;
			prevfib2 = prevfib;
			prevfib = fib;
		}
	}
	printf("\n");
	time(&end);
	
	double dif = difftime(end, start);
	printf("Time: %f\n\n", dif);
	return 0;
}