#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SLOTS	4
#define HIT	1
#define PHIT 2

enum colour {
	NONE,
	RED,
	YELLOW,
	GREEN,
	BLUE
};

void getHits(unsigned int* answer, unsigned int* guess, int* hits, int* phits) {
	if (!answer) return;
	if (!guess) return;
	
	int foundhits[MAX_SLOTS];
	memset(foundhits, 0, MAX_SLOTS*sizeof(int));
	
	int found[MAX_SLOTS];
	memset(found, 0, MAX_SLOTS*sizeof(int));
	
	for (int i = 0; i< MAX_SLOTS; i++) {
		//printf("Guess[%d]: %d\n", i, guess[i]);			
		if (guess[i] == answer[i]) {
			//printf("HIT!");
			foundhits[i] = HIT;
			found[i] = guess[i];
		}
		else {	
			for (int j = 0; j< MAX_SLOTS; j++) {					
				if (j != i) {
					if (guess[i] == answer[j]) {
						if (found[j] == NONE) {
							//printf("PHIT at %d!\n", j);
							foundhits[i] = PHIT;
							found[j] = guess[i];
						}
					}
				}
			}
			
		}
	}
	
	for (int i = 0; i < MAX_SLOTS; i++) {
		if (foundhits[i] == HIT) (*hits)++;
		else if (foundhits[i] == PHIT) (*phits)++;
	}
}

// simulate the game of mastermind
int main() {

	unsigned int answer[MAX_SLOTS];
	unsigned int guess[MAX_SLOTS];
	
	printf("Enter answer:\n");
	for (int i = 0; i < MAX_SLOTS; i++) {
		scanf("%d", &answer[i]);
	}
	
	int hits;
	int phits;
		
	while ( hits != MAX_SLOTS) {
	
		hits = 0;
		phits = 0;
		
					printf("Enter guess:\n");
		for (int i = 0; i < MAX_SLOTS; i++) {
			scanf("%d", &guess[i]);
		}
		
		getHits(answer, guess, &hits, &phits);	
		printf("hits: %d, phits: %d\n", hits, phits);
	}
	
	printf("Yay!\n");		
	return 0;
}