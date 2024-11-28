#include "Controller.h"
#include <iostream>
#include <string>
#include <fstream>

void Controller::startGame()
{ // to put a while for the level and all the playing

	while (true)
	{
		if (m_board.Loading(m_level) == END_GAME)
		{
			exit(EXIT_SUCCESS);
		}
		Location locPlayer = m_board.getLoc('/');
		m_player.setLoc(locPlayer);
	//	Location locGuard = m_board.getLoc('!');
	//	Location locDoor = m_board.getLoc('D');
		m_board.print();
		runLevel();

		m_level++;
	}
}
//------------------------
void Controller::runLevel()
{
	while (1)
	{
		m_player.move();
	}
}
//------------------------

//-------------------------
