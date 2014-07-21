// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// gamepiece.cc


#include <iostream>
#include <string>
#include "gamepiece.h"
using namespace std;

// create an abstract game piece
// assign the position x,y
GamePiece::GamePiece(Pos &p):p(p){}

// what does the board look like underneath
// this game piece.
void GamePiece::unoccupiedValue(Pos &p){
	if ((p.x%2==0 && p.y%2==0) || (p.x%2!=0 && p.y%2!=0)) {
		unoccupied = "_";
	} else {
		unoccupied = " ";
	}
}

// mutate unoccupied
void GamePiece::setUnoccupied(string str){
	unoccupied = str;
}

// get member unoccupied value
string GamePiece::getUnoccupied(){
	return unoccupied;
}

// get member name value
string GamePiece::getName(){
	return name;
}

// destroy a game piece
GamePiece::~GamePiece(){}
