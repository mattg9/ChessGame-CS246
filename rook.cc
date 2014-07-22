// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// rook.cc

#include <iostream>
#include <string>
#include "gamepiece.h"
#include "rook.h"
using namespace std;

Rook::Rook(Pos &p, string player):GamePiece(p){
	unoccupiedValue(p);
	if (player == "white") {
		name = "R";
	} else {
		name = "r";
	}
	captured = false;
}

void Rook::print(ostream &out) const {
	if (!captured) {
		out << name;
	} else {
		out << unoccupied;
	}
}

void Rook::Captured() {
	captured = !captured;
}

bool Rook::getCaptured() {
	return captured;
}
