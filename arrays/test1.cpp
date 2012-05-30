#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_BYTES	4
#define N			10

/*
class pixel {
	char* array;
	
	pixel() {
		array = (char*) malloc( NUM_BYTES * sizeof(char) );
	}
	
	pixel(char a, char b, char c, char d) {
	}
	
	~pixel() {
		if (array) free(array);
	}
};
*/

void print(int** image, unsigned int n) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%d ", image[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

// FUnction to rotate a given array
void rotate_clockwise(int** image, int** image2, unsigned int n) {
	if (!image) return;
	if (!image2) return;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			image2[j][n-i-1] = image[i][j];
		}
	}
	print(image2, n);
}

// In place!
void rotate_clockwise_IP(int** image, unsigned int n) {
	if (!image) return;
	
	for (int k = 0; k < n/2; k++) {
		for (int l = k; l < n-1-k; k++) {
			int a = image[k][l];
			int b = image[l][n-1-k];
			int c = image[n-1-k][n-1-l];
			int d = image[n-1-l][k];
			
			image[l][n-1-k] = a;
			image[n-1-k][n-1-l] = b;
			image[n-1-l][k] = c;
			image[k][l] = d;			
		}
	}
}



// Given a matrix of NxN that represents an image
// Each pixel is 4 bytes long.
// Rotate the matrix by 90 degrees
int main() {
	
	// Declare a matrix of NxN pixels
	int** image;
	int** image2;
	
	// allocate
	image = (int**) malloc( N * sizeof(int*) );
	for (int i = 0; i < N; i++) {
		image[i] = (int*) malloc( N * sizeof(int) );
	}
	
	image2 = (int**) malloc( N * sizeof(int*) );
	for (int i = 0; i < N; i++) {
		image2[i] = (int*) malloc( N * sizeof(int) );
	}
	
	// Initialize the image
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			image[i][j] = N*i + j;
		}
	}
	
	// Print the image
	print(image, N);
	
	// Rotate the image
	rotate_clockwise_IP(image, N);
	
	// Print again
	print(image, N);
	
	for (int i = 0; i < N; i++) {
		free(image[i]);
	}
	free(image);
	
	return 0;
}