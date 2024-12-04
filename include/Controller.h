#pragma once

#include <vector> 
#include <string>
#include "Board.h"
#include "Consts.h"
#include "Player.h"
//#include "Bomb.h"
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
	//bool isDoor(const Location& subect, const Location& door);
	//resetlevel()

private:
	int m_level = STARTING_LEVEL;
	Board m_board;
	Player m_player;
	std::vector<Guards> m_guards;
};