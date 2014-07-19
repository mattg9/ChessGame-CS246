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
Player* Player::CreatePlayer(string name, GameBoard *gb){
	if (numberPlayers < maxPlayers) {
		Player *p = new Player(name, gb);
		numberPlayers++;	
		return p;
	}
}

// player constructor
Player::Player(string name, GameBoard *gb):name(name),gb(gb) {
	// name = computer -> plus difficulty
	
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
	char x1 = pos1[0];
	int y1 = pos1[1] - '0';
	char x2 = pos2[0];
	int y2 = pos2[1] - '0';
	if (gb->isLegalMove(x1,y1,x2,y2)) {
		gb->move(x1,y1,x2,y2);
	}
	cout << *gb;
}
