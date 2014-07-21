// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// pawn.cc

#include <iostream>
#include <string>
#include "gamepiece.h"
#include "king.h"
using namespace std;

King::King(Pos &p, string player):GamePiece(p){
	unoccupiedValue(p);
	if (player == "white") {
		name = "K";
	} else {
		name = "k";
	}
	captured = false;
}

void King::print(ostream &out) const {
	if (!captured) {
		out << name;
	} else {
		out << unoccupied;
	}
}

void King::Captured(){
	captured = !captured;
}

bool King::getCaptured(){
	return captured;
}
