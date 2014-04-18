class Square {
	// A square is the basic unit in the chess board.
	// Each square has a height and a width
	// and may or may not contain a piece.
	// If it does contain a piece, then it is considered occupied.

private:
	uint _width = 0;
	uint _height = 0;

	/*
	uint _x;
	uint _y;
	Image* skin;
	*/

	bool _isOccupied = false;
	Piece* piece = NULL;

public:
	square();
	// To return whether it is occupied or not
	bool isOccupied();
	// To return a piece if it is occupied, else NULL.
	Piece* getPiece();

	// Add or remove pieces
	bool addPiece(Piece* p);
	bool removePiece(Piece* p)
}