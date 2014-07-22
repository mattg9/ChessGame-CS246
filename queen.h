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
	Queen(Pos &p, std::string player);

	// is this move legal with how this piece operates?
		//bool isLegalMove(Move &m); 
	bool getCaptured();
	void Captured();
	void print(std::ostream &out) const;
	private:
	bool captured;
};

#endif
