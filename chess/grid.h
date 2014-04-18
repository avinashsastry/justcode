#include "square.h"

class Grid {
private:
	uint N = 0;	// Size of the grid, let's assume that it is always a square.
	// Double array to hold the squares
	Square** squares;
	Cursor* cursor;

public:
	// Constructor to set the size of the grid to default values
	// and to init the squares array.
	Grid();

	// Initialize function to create the pieces and set their positions.
	void initGrid();

	// get Cursor position
	Cursor* getCursor();

	// Functions to manipulate pieces on the grid
	bool addPieceAtPosition(Piece* p, uint posX, uint posY);
	bool removePieceFromPosition(Piece* p, uint posX, posY);
}