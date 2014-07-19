// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// gamepiece.h

#ifndef __GAMEPIECE_H__
#define __GAMEPIECE_H__

#include <iostream>
#include <string>

class GamePiece {
	public:
	// constructor and destructor
	GamePiece(char x, int y);
	virtual ~GamePiece();
	// is this move legal with how this piece operates?
	//virtual bool isLegalMove(Position pos1, Position pos2) = 0; 
	virtual void Captured() = 0;
	virtual void print(std::ostream& out) const = 0;
	// assign string value for the gameboard box colour below piece
	// mutator functions for initializing, and in game changing
	// of pieces
	void unoccupiedValue(char x, int y);
	void setUnoccupied(std::string str);
	// accessor functions
	std::string getUnoccupied();
	std::string getName();
	virtual	bool getCaptured() = 0;
	protected:
	std::string name; // gamepiece name
	std::string unoccupied; // either a white box " " or black "_" position
	// position of gamepiece
	char x;
	int y;
	
};
#endif
