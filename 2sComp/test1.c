#include <stdio.h>

#define NUM_BITS 32

int main() {
	int n = 0;
	printf("Enter the number of lines: ");
	scanf("%d", &n);
	
	int a = 0;
	int b = 0;
	
	// run main loop
	for (int i = 0; i < n; i++) {
		printf("Enter the first number A: ");
		scanf("%d", &a); 
		
		printf("Enter the second number B: ");
		scanf("%d", &b); 
		
		// Initialize a variable x to cycle through
		int x = 0;
		int num1;
		int num2;
		
		if (a <= b) {
			num1 = a;
			num2 = b;
		}		
		else {
			num1 = b;
			num2 = a;
		}	
		
		printf("Range: %d to %d\n", num1, num2);
		
		// Set x to num 1
		x = num1;
		
		int complete_sum = 0;
		
		// Cycle from num1 to num2 inclusive
		while ((x >= num1) && (x <= num2)) {
					
			// For each number get the 2's complement representation
			printf("%d: %x\n", x, x);
			
			// I know there are 32 bits - I can check each bit individually
			// Not very efficient, but maybe it'll do the job?
			int sum = 0;
			for (int j = 0; j < NUM_BITS; j++) {
				sum += ( (x >> j) & 1 );
			}
						
			complete_sum += sum;
			x++;
		}	
		
		printf("complete sum: %d\n", complete_sum);
	}
	return 0;
}