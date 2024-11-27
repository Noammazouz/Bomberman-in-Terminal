#include "Controller.h"
#include <iostream>
#include <string>
#include <fstream>


using std::string;

void Controller::startGame()
{ // to put a while for the level and all the playing

	while (true)
	{
		if (m_board.Loading(m_level) == END_GAME)
		{
			exit(EXIT_SUCCESS);
		}
		Location locPlayer = m_board.getLoc('/');

		m_board.print();
		runLevel();

		m_level++;
	}
}
//------------------------
void Controller::runLevel()
{

}
//------------------------

//-------------------------
