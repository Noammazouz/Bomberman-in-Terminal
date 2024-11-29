#include "Controller.h"
#include <iostream>
#include <string>
#include <fstream>


/*Controller::Controller()
{
}*/
//----------------
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
     Location locPlayer = m_board.getLoc('/');
	while (1)
	{
		m_player.move();
		if (m_board.ismovevalid(locPlayer, SpecialKeys::UP))
		{
			m_board.updatboard(locPlayer, m_player.getLoc());
		}
		else
		{
			m_player.move();
		}
	}
}
//------------------------

//-------------------------
