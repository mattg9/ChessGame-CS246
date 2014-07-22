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

// prints the score;
void GameBoard::printScore() {
	cout << "Final Score: " << endl;
	cout << "White: " << whiteWins << endl;
	cout << "Black: " << blackWins << endl;
}

// one gameboard exists at any time
// this method creates gameboard
GameBoard *GameBoard::startGame(string init){
	if (gbInstance == NULL){
		gbInstance = new GameBoard();
	} 
	if (init == "default") {
		gbInstance->defaultGameBoard();
	} else if (init == "setup") {
		gbInstance->clearBoard();
	}
	return gbInstance;
}


// clear gameboard for steup mode
void GameBoard::clearBoard(){
	for (int i = 1; i < 9; i++) {
		for (char j = 'a'; j <= 'h'; j++){
			Pos p;
			p.x = j;
			p.y = i;
			if (piece[i][j-97] != NULL) {
				delete piece[i][j-97];
			}
			piece[i][j-97] = new EmptySpace(p);	
		}
	}
}

void GameBoard::add(char gamepiece, Pos p) {
	delete piece[p.y][p.x-97];
	string player;
	if (gamepiece >= 'a' && gamepiece <= 'z') {
		player = "black";
	} else {
		player = "white";
	}
	if (gamepiece == 'p' || gamepiece == 'P') {
		piece[p.y][p.x] = new Pawn(p, player);
	} else if (gamepiece == 'r' || gamepiece == 'R') {
		piece[p.y][p.x] = new Rook(p,player);
	} else if (gamepiece == 'q' || gamepiece == 'Q') {
		piece[p.y][p.x] = new Queen(p,player);
	} else if (gamepiece == 'k' || gamepiece == 'K') {
		piece[p.y][p.x] = new King(p,player);
	} else if (gamepiece == 'b' || gamepiece == 'B') {
		piece[p.y][p.x] = new Bishop(p,player);
	} else if (gamepiece == 'n' || gamepiece == 'N') {
		piece[p.y][p.x] = new Knight(p,player);
	}
}

void GameBoard::del(Pos p) {
	delete piece[p.y][p.x-97];
	piece[p.y][p.x] = new EmptySpace(p);
}

bool GameBoard::validBoard(){
	int countBlackKing = 0;
	int countWhiteKing = 0;
	for (int i = 1; i < 9; i++) {
		for (char j = 'a'; j <= 'h'; j++) {
			if (piece[i][j-97]->getName() == "K") {
				countWhiteKing++;
			} else if (piece[i][j-97]->getName() == "k") {
				countBlackKing++;
			}
			if (piece[i][j-97]->getName() == "p" || piece[i][j-97]->getName() == "P") {
				if (i == 1 || i == 8) {
					return false;
				}
			}
		}
	}
	if (countWhiteKing != 1 || countBlackKing != 1) {
		return false;
	} else {
		return true;
	}
}

GameBoard::GameBoard(){}
// constructing the default gameboard	
void GameBoard::defaultGameBoard(){
	for (int i = 1; i < 9; i++) {
		for (char j = 'a'; j <= 'h'; j++) {
			if (piece[i][j-97] != NULL) {
				delete piece[i][j-97];
			}
			Pos p;
			p.x = j;
			p.y = i;
			if (i == 1) {
				if (j == 'a' || j == 'h') {
					piece[i][j-97] = new Rook(p,"white");
				} else if (j == 'b' || j == 'g') {
					piece[i][j-97] = new Knight(p,"white");
				} else if (j == 'c' || j == 'f') {
					piece[i][j-97] = new Bishop(p,"white");
				} else if (j == 'd') {
					piece[i][j-97] = new Queen(p,"white");
				} else {
					piece[i][j-97] = new King(p,"white");
				}
			} else if (i == 2) {
				piece[i][j-97] = new Pawn(p, "white");
			} else if (i == 7) {
				piece[i][j-97] = new Pawn(p,"black");
			} else if (i == 8) {
				if (j == 'a' || j == 'h') {
					piece[i][j-97] = new Rook(p,"black");
				} else if (j == 'b' || j == 'g') {
					piece[i][j-97] = new Knight(p,"black");
				} else if (j == 'c' || j == 'f') {
					piece[i][j-97] = new Bishop(p,"black");
				} else if (j == 'd') {
					piece[i][j-97] = new Queen(p,"black");
				} else {
					piece[i][j-97] = new King(p,"black");
				}
			} else { 
				piece[i][j-97] = new EmptySpace(p);
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

// output the gameboard
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

bool GameBoard::isLegalMove(Move &m, bool inCheck, string colour){
	// check whether the moves positions are on the board
	// is the pos1 == to pos2. not allowed.
	// is the person in check..inwhich case will this move
	/// put them out of check. 
	// we could move pieces...call is check.. then
	// swap pieces back the way they were originally.
	// does the piece move like this!
	//piece[m.pos1.y][m.pos1.x]->isLegalMove(m.pos2);
	//Pos listpos [8] = piece[m.pos1.y][m.pos1.x]->requiredSpaces(m.pos2);
	// are these pieces occupied with uncaptured game pieces
	return true;
}

//bool GameBoard::isCheck();
//bool GameBoard::isCheckMate();
// uses isCheck which uses isLEgalMove on every possible move
// a player can perform.

// move game pieces
void GameBoard::move(Move &m) {
	string p1 = piece[m.pos1.y][m.pos1.x-97]->getUnoccupied();
	string p2 = piece[m.pos2.y][m.pos2.x-97]->getUnoccupied();
	piece[m.pos1.y][m.pos1.x-97]->setUnoccupied(p2);
	piece[m.pos2.y][m.pos2.x-97]->setUnoccupied(p1);
	GamePiece *temp;
	if (piece[m.pos2.y][m.pos2.x-97]->getName() != "empty"
		&& !piece[m.pos2.y][m.pos2.x-97]->getCaptured()) {
		piece[m.pos2.y][m.pos2.x-97]->Captured();
	}
	temp = piece[m.pos1.y][m.pos1.x-97];
	piece[m.pos1.y][m.pos1.x-97] = piece[m.pos2.y][m.pos2.x-97];
	piece[m.pos2.y][m.pos2.x-97] = temp;
}
