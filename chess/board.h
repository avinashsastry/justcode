#include "player.h"
#include "grid.h"
#include "piece.h"

class ChessBoard {
private:
	// Needs two players
	Player* pWhite;	// Player 1
	Player* pBlack;	// Player 2

	// A grid for storing pieces on the board
	// A grid should be composed of squares, and at each square, there may or may not be a piece
	Grid* grid;

	// An array to init and track pieces in the game
	Piece** pieces;

	// function to add pieces to the grid at a given position - used to initialize the board
	void addPieceToGrid(Piece* p, int pos_X, int pos_Y);

public:
	// Constructor to initialize the players, grid and squares
	ChessBoard();

	// A function to initialize the board to some initial config
	int resetBoard();
}