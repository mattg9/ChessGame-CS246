// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// pawn.cc

#include <iostream>
#include <string>
#include "gamepiece.h"
#include "pawn.h"
using namespace std;

Pawn::Pawn(char x, int y, string player):GamePiece(x,y){
	unoccupiedValue(x,y);
	if (player == "white") {
		name = "P";
	} else {
		name = "p";
	}
	captured = false;
}

void Pawn::print(ostream &out) const {
	if (!captured) {
		out << name;
	} else {
		out << unoccupied;
	}
}

void Pawn::Captured(){
	captured = !captured;
}

bool Pawn::getCaptured(){
	return captured;
}
