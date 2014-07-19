// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// queen.cc

#include <iostream>
#include <string>
#include "gamepiece.h"
#include "queen.h"
using namespace std;

Queen::Queen(char x, int y, string player):GamePiece(x,y){
	unoccupiedValue(x,y);
	if (player == "white") {
		name = "Q";
	} else {
		name = "q";
	}
	captured = false;
}

void Queen::print(ostream &out) const {
	if (!captured) {
		out << name;
	} else {
		out << unoccupied;
	}
}

void Queen::Captured() {
	captured = !captured;
}

bool Queen::getCaptured() {
	return captured;
}
