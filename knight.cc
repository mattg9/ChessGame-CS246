// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// knight.cc

#include <iostream>
#include <string>
#include "gamepiece.h"
#include "knight.h"
using namespace std;

Knight::Knight(char x, int y, string player):GamePiece(x,y){
	unoccupiedValue(x,y);
	if (player == "white") {
		name = "N";
	} else {
		name = "n";
	}
	captured = false;
}

void Knight::print(ostream &out) const {
	if (!captured) {
		out << name;
	} else {
		out << unoccupied;
	}
}

void Knight::Captured(){
	captured = !captured;
}

bool Knight::getCaptured(){
	return captured;
}
