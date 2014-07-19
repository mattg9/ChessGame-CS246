// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// knight.h

#ifndef __KNIGHT_H__
#define __KNGIHT_H__

#include <iostream>
#include <string>
#include "gamepiece.h"

class Knight : public GamePiece {
	public:
	Knight(char x, int y, std::string player);

	// is this move legal with how this piece operates?
	//isLegalMove(Position pos1, Position pos2); 
	bool getCaptured();
	void print(std::ostream &out) const;
	void Captured();
	private:
	bool captured;
};
#endif
