// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// gameboard.h

#ifndef __GAMEBOARD_H__
#define __GAMEBOARD_H__

#include <iostream>
#include <string>
#include "gamepiece.h"

struct Move {
	// initial pos
	Pos pos1;
	// final pos
	Pos pos2;
};

class GameBoard {
	public:
	~GameBoard();
	// singleton constructors
	static GameBoard *startGame(string init);
	void clearBoard();
	bool isLegalMove(Move &m)
	void move(Move &m)
	friend std::ostream& operator<<(std::ostream &out, GameBoard &gb);
	
	// setup methods
	void add(char piece, Pos p);
	void del(Pos p);
	bool validBoard();
	
	private:
	GameBoard();
	void defaultGameBoard();
	GamePiece *piece[9][8];
	static GameBoard *gbInstance;
	static double whiteWins;
	static double blackWins;
	// static Move *listMoves;
};
#endif
