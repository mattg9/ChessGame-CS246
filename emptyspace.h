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
	EmptySpace(char x, int y);
	//bool isLegalMove(char x1, int y1, char x2, int y2);
	void Captured();
	bool getCaptured();
	void print(std::ostream &out) const;
};
#endif
