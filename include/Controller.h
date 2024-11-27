#pragma once

#include <vector> 
#include <string>
#include "Board.h"
#include "Consts.h"
#include "Player.h"
//#include "Bomb.h"
//#include "Guard.h"
//#include "StaticObjects.h"


class Controller
{
public:

	void runLevel();
	void startGame();
	//resetlevel()
	//

private:
	int m_level = STARTING_LEVEL;
	Board m_board;
	Player m_player;
	//std::vector<Guard>;
	//std::vector<StaticObjects>:
};