#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum piece {
	none,
	circle,
	cross
};

class board {
	private:
	piece pieces[3][3];
	
	board() {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				pieces[i][j] = none;
			}
		}
	}
	
	~board() {
	}
	
	piece getPieceAtPos(int x, int y) {
		return pieces[x][y];
	}
	
	adbo
	
	
};

int main()  {
	
	
	return 0;
}
