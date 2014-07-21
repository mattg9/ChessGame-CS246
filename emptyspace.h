// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// gamepiece.h

#ifndef __EMPTYSPACE_H__
#define __EMPTYSPACE_H__

#include <iostream>
#include <string>
#include "gamepiece.h"

// empty space on the gameboard
class EmptySpace : public GamePiece {
	public:
	EmptySpace(Pos &p);
	//bool isLegalMove(Move &m);
	void Captured();
	bool getCaptured();
	void print(std::ostream &out) const;
};
#endif
