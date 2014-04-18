class Piece {
	
private:
	Player* _player;

public:
	Piece();
	Player* getPlayer();
	virtual bool canMove(uint startX, uint startY, uint endX, uint endY);
}