// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// emptyspace.cc

#include <iostream>
#include <string>
#include "gamepiece.h"
#include "emptyspace.h"
using namespace std;

EmptySpace::EmptySpace(Pos &p):GamePiece(p){
	unoccupiedValue(p);
	name = "empty";
}

void EmptySpace::print(ostream &out)const {
	out << unoccupied;
}
	
void EmptySpace::Captured(){
	// nothing to do here, no member called captured
	// code should not be executed
}

bool EmptySpace::getCaptured(){
	return true;
} // same thing over here		
