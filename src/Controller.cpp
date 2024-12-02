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
            if (m_board.ismovevalid(locPlayer, step))
            {
                // Update player location
                m_player.move(step);


                if (checkHit(locPlayer))
                {
                    resetPos(locPlayer);
                }
                else
                {
                    // Update board
                    m_board.updatboard(locPlayer, m_player.getPlayerLoc(0), '/');
                }
                //checkHit(locPlayer);
                Screen::setLocation(Location(m_board.getSizeOfRow() + 1, 0)); // where to print leader board
               std::cout << "lives" << m_player.getLives()<< std::endl;// to put a fucntion that prints the leader board.
               // std::cout << m_player.getPlayerLoc(0).row << " " << m_player.getPlayerLoc(0).col << std::endl;


                // Update locPlayer for next iteration
                locPlayer = m_player.getPlayerLoc(0);
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
bool Controller::checkHit(const Location& other)
{
    for (int start = 0; start < m_guards.size(); start++)
    {
        if (other.row == m_guards[start].getGuardLoc(0).row
            && other.col == m_guards[start].getGuardLoc(0).col)
        {
            m_player.decLives();
            //resetPos(other);
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
            m_guards[start].setLoc(m_guards[start].getGuardLoc(START_POSTION));
            m_board.updatboard(m_guards[start].getGuardLoc(0), m_guards[start].getGuardLoc(START_POSTION),'!');
        }
    }
}