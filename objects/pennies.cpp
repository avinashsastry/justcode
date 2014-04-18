#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define	QUARTER	25
#define	DIME	10
#define	NICKEL	 5
#define	PENNY	 1


int numWaysOfCounting(int n, int count, int denom) {

		printf("count=%d, denom=%d\n", count, denom);
	
	if (n < 0) return 0;
	if (count < 0) return 0;
	if (count > n) return 0;
	
	int next_denom = 0;
	switch (denom) {
		case 25:
		next_denom = 10;
	break;
		case 10:
		next_denom = 5;
	break;
		case 5:
		next_denom = 1;
	break;
		case 1:
		return 1;
	break;
	}	
	
	int ways = 0;
	for (int i = 0; i*denom <= n; i++) {
		 ways += numWaysOfCounting(n, count+i*denom, next_denom);
	}
	
	return ways;
}


int makeChange(int n, int denom) {
	int next_denom = 0;
	switch (denom) {
		case 25:
		next_denom = 10;
	break;
		case 10:
		next_denom = 5;
	break;
		case 5:
		next_denom = 1;
	break;
		case 1:
		printf("makeChange: %d, %d\n", n, denom);
		return 1;
	}	
	
	int ways = 0;
	for (int i = 0; i * denom <= n; i++) {
		ways += makeChange(n - i * denom, next_denom);
	}
	return ways;
}


// Program to print the number of ways of representing 
// n cents with quarters/dimes/nickels and pennies 
int main() {
	int n = 25;
	//printf("Ways for %d: %d\n", n, makeChange(n, QUARTER));
	printf("Ways for %d: %d\n", n, 	numWaysOfCounting(n, 0, QUARTER));
}