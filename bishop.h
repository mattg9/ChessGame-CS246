// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// bishop.h

#ifndef __BISHOP_H__
#define __BISHOP_H__

#include <iostream>
#include <string>
#include "gamepiece.h"

class Bishop : public GamePiece {
	public:
	Bishop(Pos &p, std::string player);

	// is this move legal with how this piece operates?
	//bool isLegalMove(Position pos1, Position pos2); 
	bool getCaptured();
	void print(std::ostream &out) const;	
	void Captured();
	private:
	bool captured;
};
#endif
