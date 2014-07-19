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
GamePiece::GamePiece(char x, int y):x(x), y(y){}

// what does the board look like underneath
// this game piece.
void GamePiece::unoccupiedValue(char x, int y){
	if ((x%2==0 && y%2==0) || (x%2!=0 && y%2!=0)) {
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
