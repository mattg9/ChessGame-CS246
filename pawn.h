// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// pawn.h

#ifndef __PAWN_H__
#define __PAWN_H__

#include <iostream>
#include <string>
#include "gamepiece.h"
class Pawn : public GamePiece {
	public:
	Pawn(char x, int y, std::string player);

	// is this move legal with how this piece operates?
	//bool isLegalMove(Position pos1, Position pos2); 
	bool getCaptured();	
	void print(std::ostream &out) const;
	void Captured();
	private:
	bool captured;
};
#endif
