// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// player.cc

#include <iostream>
#include <string>
#include "gameboard.h"
#include "player.h"
using namespace std;

// singleton pattern extended to 
// restricting creation of more than 2 players
int Player::numberPlayers = 0;
int Player::maxPlayers = 2; 

// creates and returns a new pointer to a player
// if there is not already 2 existing players
Player* Player::CreatePlayer(string name, string colour, GameBoard *gb){
	if (numberPlayers < maxPlayers) {
		Player *p = new Player(name, colour, gb);
		numberPlayers++;	
		return p;
	}
}

// player constructor
Player::Player(string name, string colour, GameBoard *gb):name(name),colour(colour),gb(gb) {
	// name = computer -> plus difficulty
	inCheck = false;
}

Player::~Player(){}	

	
void Player::move(){
	if (name == "human") {
		humanMove();
	} else if (name == "computer[1]") {
	//	cpuLevel1Move();
	} else if (name == "computer[2]") {
	//	cpuLevel2Move();
	} else if (name == "computer[3]") {
	//	cpuLevel3Move();
	} else {
	//	cpuLevel4Move();
	}
}

void Player::humanMove() {
	string pos1, pos2;
	cin >> pos1 >> pos2;
	Move m;
	m.pos1.x = pos1[0];
	m.pos1.y = pos1[1];
	m.pos2.x = pos2[0];
	m.pos2.y = pos2[1];
	if (gb->isLegalMove(m, inCheck, colour)) {
		gb->move(m);
	}
	if (inCheck) {
		inCheck = false;
	}
	cout << *gb;
}
