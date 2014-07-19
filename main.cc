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
	bool game = false;
	GameBoard *gb;
	Player *white, *black;
	bool whiteplays = true;
	
	string input;
	while (true) {
		// read in commands
		cin >> input;
		// end of file reached
		// delete the game board and players
		if (cin.fail() && cin.eof()) {
			cin.clear();
			//gb->printScore();
			delete white;
			delete black;
			delete gb;
			break;
		}
		// GAME
		// start a new game
		if (!game && input == "game"){
			gb = GameBoard::startGame();
			string whiteplayer, blackplayer;
			cin >> whiteplayer >> blackplayer;
			white = Player::CreatePlayer(whiteplayer,gb);
			black = Player::CreatePlayer(blackplayer,gb);
			cout << *gb;
			game = true;
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
		} else if (!game && input == "setup") {
			string command;
			while (true) {
				cin >> command;
				if (command == "done") {
					// check valid board
					break;
				} else if (command == "+") {
					string piece, pos;
					cin >> piece >> pos;
					//gb->add(piece,pos);
				} else if (command == "-") {
					string pos;
					cin >> pos;
					//gb->remove(pos);
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
			
				
