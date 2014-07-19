// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// queen.h

#ifndef __QUEEN_H__
#define __QUEEN_H__

#include <iostream>
#include <string>
#include "gamepiece.h"
class Queen : public GamePiece {
	public:
	Queen(char x, int y, std::string player);

	// is this move legal with how this piece operates?
		//bool isLegalMove(Position pos1, Position pos2); 
	bool getCaptured();
	void Captured();
	void print(std::ostream &out) const;
	private:
	bool captured;
};

#endif
