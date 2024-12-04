#include "Controller.h"
#include <conio.h>
#include <iostream>
#include <string>
#include <fstream>


/*Controller::Controller()
{
}*/
void Controller::findGuards()
{
    Location locGuard = { 0, 0 };
    int maxRow = m_board.getSizeOfRow();
    int maxCol = m_board.getSizeOfCol();
    int cell = 0;
    while (locGuard.row < maxRow)
    {
        locGuard.col = 0;
        for (;locGuard.col < maxCol;locGuard.col++)
        {
            Location tempguard = locGuard;
            locGuard = m_board.getLoc('!', locGuard);
            if (locGuard.row != 0 || locGuard.col != 0)
            {
                m_guards.push_back(Guards(locGuard));
            }
            else
            {
                locGuard = tempguard;
            }
        }
        locGuard.row++;
    }
}
//----------------
void Controller::startGame()
{ // to put a while for the level and all the playing
	while (true)
	{
		if (m_board.Loading(m_level) == END_GAME)
		{
			exit(EXIT_SUCCESS);
		}
		Location locPlayer = m_board.getLoc('/', Location(0, 0));
		m_player.setLoc(locPlayer);
        findGuards();
	//	Location locDoor = m_board.getLoc('D');
		m_board.print();
		runLevel();

		m_level++;
	}
}
//------------------------
void Controller::runLevel()
{
  //  std::cout << "leaderboar" << std::endl;
    Location locDoor = m_board.getLoc(DOOR, Location(0, 0));
    Location locPlayer = m_board.getLoc('/', Location(0, 0));
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

            if (m_board.ismovevalid(locPlayer, step, 0))
            {
                // Update player location
                m_player.move(step);

                if(!guardsVsPlayer(locPlayer))
                {
                    // Update board
                    m_board.updatboard(locPlayer, m_player.getPlayerLoc(0), '/');
                }
               // moveGuards(locPlayer);
                //checkHit(locPlayer);
                 // where to print leader board


                 // Update locPlayer for next iteration
                 locPlayer = m_player.getPlayerLoc(0);
                    if ((locPlayer.row == locDoor.row) && (locPlayer.col == locDoor.col))
                    {
                        levelComplete = true;
                        break;
                    }
                    moveGuards(locPlayer);
                // Add any level completion checks here
                // For example, check if player reached the door
           
                     
            }
        }
        else if (step == ' ')
        {
            moveGuards(locPlayer);
            if (checkHit(locPlayer))
            {
                resetPos(locPlayer);
            }
        }

        // Add a way to exit the level or game
        // For example, ESC key or reaching a specific condition
        Screen::setLocation(Location(m_board.getSizeOfRow() + 1, 0));
        std::cout << "lives" << m_player.getLives() << std::endl;
        std::cout << "Player loc" << m_player.getPlayerLoc(0).row <<  m_player.getPlayerLoc(0).col<< std::endl;
        std::cout << "Player loc" << m_player.getPlayerLoc(1).row << m_player.getPlayerLoc(1).col << std::endl;
    }

    //points lives
}
//------------------------
bool Controller::checkHit(const Location& other)
{
    for (int start = 0; start < m_guards.size(); start++)
    {
        if (other.row == m_guards[start].getGuardLoc(0).row
            && other.col == m_guards[start].getGuardLoc(0).col)
        {
            m_player.decLives();
            return true;
        }
    }
    return false;
}
//-------------------------
void Controller::resetPos(const Location& other)
{
    m_board.updatboard(other, m_player.getPlayerLoc(START_POSTION), '/');
    m_player.setLoc(m_player.getPlayerLoc(START_POSTION));
    for (int start = 0; start < m_guards.size(); start++)
    {
        if (m_guards[start].isAlive())
        {
            m_board.updatboard(m_guards[start].getGuardLoc(0), m_guards[start].getGuardLoc(START_POSTION), '!');
            m_guards[start].setLoc(m_guards[start].getGuardLoc(START_POSTION));
        }
    }
}
//-------------------
void Controller::moveGuards(const Location& player)
{
    for (int guard = 0; guard < m_guards.size(); guard++)
    {
        if (m_guards[guard].isAlive())
        {
            Location currLocGuard = m_guards[guard].getGuardLoc(0);
            auto direction = m_guards[guard].selectDirection(player);
            if (m_board.ismovevalid(currLocGuard, direction, 1))
            {
                m_guards[guard].moveTheGuard(direction);
                if (!guardsVsPlayer(player))
                {
                    m_board.updatboard(currLocGuard, m_guards[guard].getGuardLoc(0), '!');
                }
            }

        }
    }
}
bool Controller::guardsVsPlayer(const Location& player)
{
    if (checkHit(m_player.getPlayerLoc(0)))
    {
        m_board.updatboard(player, m_player.getPlayerLoc(0), '/');
        resetPos(player);
        return true;
    }
    return false;
}