#include "Controller.h"
#include <conio.h>
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
    bool levelComplete = false;

    while (!levelComplete)
    {
        auto step = _getch();
        if (step == Keys::SPECIAL_KEY)
        {
            step = _getch();
            Location newLoc = locPlayer;

            // Determine new location based on step
            switch (step)
            {
            case SpecialKeys::UP:
                newLoc.row--;
                break;
            case SpecialKeys::DOWN:
                newLoc.row++;
                break;
            case SpecialKeys::LEFT:
                newLoc.col--;
                break;
            case SpecialKeys::RIGHT:
                newLoc.col++;
                break;
            }

            // Check if move is valid
            if (m_board.ismovevalid(locPlayer, step))
            {
                // Update player location
                m_player.move(step);

                // Update board
                m_board.updatboard(locPlayer, m_player.getLoc());

                // Update locPlayer for next iteration
                locPlayer = m_player.getLoc();

                // Add any level completion checks here
                // For example, check if player reached the door
                // if (locPlayer == doorLocation) levelComplete = true;
            }
        }
        // Add a way to exit the level or game
        // For example, ESC key or reaching a specific condition
    }
}
//------------------------

//-------------------------
