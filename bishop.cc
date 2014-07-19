// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// bishop.cc

#include <iostream>
#include <string>
#include "gamepiece.h"
#include "bishop.h"
using namespace std;

Bishop::Bishop(char x, int y, string player):GamePiece(x,y){
	unoccupiedValue(x,y);
	if (player == "white") {
		name = "B";
	} else {
		name = "b";
	}
	captured = false;
}

void Bishop::print(ostream &out) const {
	if (!captured) {
		out << name;
	} else {
		out << unoccupied;
	}
}

void Bishop::Captured(){
	captured = !captured;
}

bool Bishop::getCaptured(){
	return captured;
}
