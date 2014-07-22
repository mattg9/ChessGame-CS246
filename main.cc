// a5 CHESS
// Matthew Gaston 20516570
// Andrew Gemmel
// main.cc
#include <iostream>
#include <string>
#include "gameboard.h"
#include "player.h"
using namespace std;

int main() {
	GameBoard *gb = 0;
	Player *white = 0;
	Player *black = 0;
	bool whiteplays = true;
	bool setup = false;
	
	string input;
	while (true) {
		// read in commands
		cin >> input;
		// end of file reached
		// delete the game board and players
		if (cin.fail() && cin.eof()) {
			cin.clear();
			gb->printScore();
			delete white;
			delete black;
			delete gb;
			break;
		}
		// GAME
		// start a new game
		if (input == "game"){
			if (!setup){
				gb = GameBoard::startGame("default");
			} else {
				setup = false;
			}
			string whiteplayer, blackplayer;
			cin >> whiteplayer >> blackplayer;
			white = Player::CreatePlayer(whiteplayer,"white",gb);
			black = Player::CreatePlayer(blackplayer,"black",gb);
			cout << *gb;
			while (true) {
			// PLAYING THE GAME
				string command;
				cin >> command;
				if (cin.fail() || cin.eof()) {
					cin.clear();
					cin.ignore();
				}
				// resign, stop game
				if (command == "resign") {
					if (whiteplays) {
				//		cout << "Black Wins!" << endl;
					} else {
				//		cout << "White Wins!" << endl;
					}
					break;
				// white human plays
				} else if (command == "move" && whiteplays) {
					white->move();
				// black human plays
				} else if (command == "move"){
					black->move();
				// undo a move
				//} else if (command == "undo") {
				//	white->undo();
				}
				//if (command != "undo") {
					whiteplays = !whiteplays;
				//}
			}
		// SETUP
		// initialize a game board. not in game
		} else if (input == "setup") {
			setup = true;
			gb = GameBoard::startGame("setup");
			string command;
			while (true) {
				cin >> command;
				if (command == "done") {
					if (gb->validBoard()) {
						cout << *gb;
						break;
					} else {
						cout << "not a valid board!" << endl;
					}
				} else if (command == "+") {
					char piece;
					string pos;
					cin >> piece >> pos;
					Pos p;
					p.x = pos[0];
					p.y = pos[1]-'0';
					gb->add(piece,p);
				} else if (command == "-") {
					string pos;
					cin >> pos;
					Pos p;
					p.x = pos[0];
					p.y = pos[1]-'0';
					gb->del(p);
				} else if (command == "=") {
					string colour;
					cin >> colour;
					if (colour == "black"){
						whiteplays = false;
					} else if (colour == "white"){
						whiteplays = true;
					}	
				}
			}
		}
	}
}
			
				
