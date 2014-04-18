#include <stdio.h>

typedef enum pieceType {
	PIECE_NONE,
	PIECE_PAWN,
	PIECE_ROOK,
	PIECE_BISHOP,
	PIECE_KNIGHT,
	PIECE_QUEEN,
	PIECE_KING
};

class square {
	unsigned int posX;
	unsigned int posY;
};

class piece {
	public:
	pieceType type;
	square pos;
	
	piece() {
		type = PIECE_PAWN;
	}
	
	~piece() {
	}
};

int main() {
	
	piece pawns[16];
	printf("Type: %d\n", pawns[1].type);
	return 0;
}
