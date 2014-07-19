// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// gameboard.h

#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#include <iostream>
#include <string>
#include "gamepiece.h"

class GameBoard {
	public:
	~GameBoard();
	// singleton constructor
	static GameBoard *startGame();	
	bool isLegalMove(char x1, int y1, char x2, int y2);
	void move(char x1, int y1, char x2, int y2);
	friend std::ostream& operator<<(std::ostream &out, GameBoard &gb);
	
	private:
	GameBoard();
	GamePiece *piece[9][8];
	static GameBoard *gbInstance;
	static double whiteWins;
	static double blackWins;
};
#endif
