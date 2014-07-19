// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// gameboard.cc

#include <iostream>
#include <string>
#include "gamepiece.h"
#include "gameboard.h"
#include "emptyspace.h"
#include "king.h"
#include "queen.h"
#include "bishop.h"
#include "knight.h"
#include "rook.h"
#include "pawn.h"
using namespace std;

// points for white and black are
// kept track of on gameboard
double GameBoard::whiteWins = 0;
double GameBoard::blackWins = 0;
GameBoard* GameBoard::gbInstance = NULL;

// one gameboard exists at any time
// this method creates gameboard
GameBoard *GameBoard::startGame(){
	if (gbInstance == NULL){
		gbInstance = new GameBoard();
		return gbInstance;
	}
}


// constructing the gameboard	
GameBoard::GameBoard(){
	for (int i = 1; i < 9; i++) {
		for (char j = 'a'; j <= 'h'; j++) {
			if (i == 1) {
				if (j == 'a' || j == 'h') {
					piece[i][j-97] = new Rook(j,i,"white");
				} else if (j == 'b' || j == 'g') {
					piece[i][j-97] = new Knight(j,i,"white");
				} else if (j == 'c' || j == 'f') {
					piece[i][j-97] = new Bishop(j,i,"white");
				} else if (j == 'd') {
					piece[i][j-97] = new Queen(j,i,"white");
				} else {
					piece[i][j-97] = new King(j,i,"white");
				}
			} else if (i == 2) {
				piece[i][j-97] = new Pawn(j,i, "white");
			} else if (i == 7) {
				piece[i][j-97] = new Pawn(j,i,"black");
			} else if (i == 8) {
				if (j == 'a' || j == 'h') {
					piece[i][j-97] = new Rook(j,i,"black");
				} else if (j == 'b' || j == 'g') {
					piece[i][j-97] = new Knight(j,i,"black");
				} else if (j == 'c' || j == 'f') {
					piece[i][j-97] = new Bishop(j,i,"black");
				} else if (j == 'd') {
					piece[i][j-97] = new Queen(j,i,"black");
				} else {
					piece[i][j-97] = new King(j,i,"black");
				}
			} else { 
				piece[i][j-97] = new EmptySpace(j,i);
			}
		}
	}
}

// destroy pieces on gameboard
GameBoard::~GameBoard(){
	for (int i = 1; i < 9; i++) {
		for (char j = 'a'; j == 'h'; j++) {
		delete piece[i][j];
		}
	}
}

// pint the gameboard
ostream& operator<<(ostream &out, GameBoard &gb){
	for (int i = 8; i > 0; i--) {
		out << i;
		for (char j = 'a'; j <= 'h'; j++) {
			gb.piece[i][j-97]->print(out);
		}
		out << endl;
	}
	out << " abcdefgh" << endl;
	return out;
}

bool GameBoard::isLegalMove(char x1, int y1, char x2, int y2){
 	// check for pieces in the way!
	// does the piece move like this!
	//piece[y1][x2-97]->isLegalMove(x2,y2);
	return true;
}

void GameBoard::move(char x1, int y1, char x2, int y2) {
	string p1 = piece[y1][x1-97]->getUnoccupied();
	string p2 = piece[y2][x2-97]->getUnoccupied();
	piece[y1][x1-97]->setUnoccupied(p2);
	piece[y2][x2-97]->setUnoccupied(p1);
	GamePiece *temp;
	// difference between a move and undo
	// undo reverts to last state
	// move will change captured to true
	if (piece[y2][x2-97]->getName() != "empty"
		&& !piece[y2][x2-97]->getCaptured()) {
		piece[y2][x2-97]->Captured();
	}
	temp = piece[y1][x1-97];
	piece[y1][x1-97] = piece[y2][x2-97];
	piece[y2][x2-97] = temp;
}
