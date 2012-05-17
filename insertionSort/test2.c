#include <stdio.h>

int main() {
	
	int j;
	for (j = 56; j > 0; j -= j & -j) {
		printf("%8x\n", j);
		printf("%8x\n", -j);
		printf("%8x, %d\n", j & -j, j); 
	} 
	printf("%8x\n", j);
	printf("%8x\n", -j);
	printf("%8x, %d\n", j & -j, j); 

	return 0;
}