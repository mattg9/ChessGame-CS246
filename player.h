// a5 chess
// Matthew Gaston 20516570
// Andrew Gemmel
// player.h

#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <iostream>
#include <string>
#include "gameboard.h"

class Player {
	public:
	static Player *CreatePlayer(std::string name, GameBoard *gb);
	~Player();
	
	void move();
	//void undo();
	
	private:
	void humanMove();	
	//void cpuLevel1Move();
	//void cpuLevel2Move();
	//void cpuLevel3Move();
	//void cpuLevel4Move();
	Player(std::string name, GameBoard *gb);
	std::string name;
	GameBoard *gb;
	//std::string colour;
	int static numberPlayers;
	int static maxPlayers;
	//char static *lastMovex1;
	//char static *lastMovex2;
	//int static *lastMovey1;
	//int static *lastMovey2;
};	

#endif
