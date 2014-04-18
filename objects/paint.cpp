#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N	10

void paint(int** grid, unsigned int x, unsigned int y, int colour) {
	if ( (x >= 0 && x < N) && (y < N && y >= 0) ) {
		if (grid[x][y] != colour) {
			grid[x][y] = colour;
			
			// right
			paint(grid, x, y+1, colour);
			paint(grid, x, y-1, colour);
			paint(grid, x+1, y, colour);
			paint(grid, x-1, y, colour);
		}
	}
}

int main() {
	int** grid = (int**) malloc(N * sizeof(int*));
	for (int i = 0; i < N; i++) {
		grid[i] = (int*) malloc(N*sizeof(int));
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i < 7 && j < 5)
				grid[i][j] = 0;
			else
				grid[i][j] = 1;
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	
	paint(grid, 3, 4, 1);
	
	printf("\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", grid[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}