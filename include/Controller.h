#pragma once

#include <vector> 
#include <string>
#include "Board.h"
#include "Consts.h"
#include "Player.h"
#include "Bombs.h"
#include "Guards.h"
//#include "StaticObjects.h"


class Controller
{
public:
	Controller() = default;
	void runLevel();
	void startGame();
	void findGuards();
	bool checkHit(const Location& other);
	void resetPos(const Location& other);
	void moveGuards(const Location& other);
	bool guardsVsPlayer(const Location& player);
	bool lostGame();
	void  setAbomb(const Location& player);
	void bombsUpdate();
	void explosion(int cell, char wanted);
	void checkPlayerGuard(char wanted);
	void  getPoints( int startGuards);
	void clearingLevel();
	//resetlevel()

private:
	int m_level = STARTING_LEVEL;
	bool m_nextLavel = true;
	Board m_board;
	Player m_player;
	std::vector<Guards> m_guards;
	std::vector<Bombs> m_bombs;
};