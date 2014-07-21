// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// king.h

#ifndef __KING_H__
#define __KING_H__

#include <iostream>
#include <string>
#include "gamepiece.h"


class King : public GamePiece {
	public:
	King(Pos &p, std::string player);

	// is this move legal with how this piece operates?
	//bool isLegalMove(Move &m); 
	bool getCaptured();		
	void print(std::ostream &out) const;
	void Captured();
	private:
	bool captured;
	// can i castle?
	bool hasmoved;
};
#endif
