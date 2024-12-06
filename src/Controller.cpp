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
    //int cell = 0;
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
	while (m_nextLavel)
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
    int numOfGuards = static_cast<int> (m_guards.size());


    while (!levelComplete)
    {
        auto step = _getch();
        if (step == Keys::SPECIAL_KEY)
        {
            step = _getch();
            // Check if move is valid
            if (m_board.ismovevalid(locPlayer, step, 0))
            {
                Screen::setLocation(locPlayer);
                /*for (int start = 0; start < m_bombs.size(); start++)
                {
                    if (m_bombs[start].getBombsLoc().row == locPlayer.row && m_bombs[start].getBombsLoc().col == locPlayer.col)
                    {
                        std::cout << '%';
                        break;
                    }
                    else
                    {
                        std::cout << ' ';
                        break;
                    }
                }*/
                std::cout << ' ';
                // Update player location
                m_player.move(step);

                if(!guardsVsPlayer(m_player.getPlayerLoc(0)))
                {
                    // Update board
                    m_board.updatboard(locPlayer, m_player.getPlayerLoc(0), '/');
                }
                if (lostGame())
                {
                    m_nextLavel = false;
                    break;
                }

                 // Update locPlayer for next iteration
                locPlayer = m_player.getPlayerLoc(0);
                if ((locPlayer.row == locDoor.row) && (locPlayer.col == locDoor.col))
                {
                    levelComplete = true;
                    break;
                }
                moveGuards(locPlayer);
                if (lostGame())
                {
                    m_nextLavel = false;
                    break;
                }
                // Add any level completion checks here
                // For example, check if player reached the door      
            }
        }
        else if (step == ' ')
        {
            moveGuards(locPlayer);
            if (lostGame())
            {
                m_nextLavel = false;
                break;
            }
        }
        else if (step == 'b')
        {
            setAbomb(locPlayer);
        }
        if (!m_bombs.empty())
        {
            bombsUpdate();
        }
        Screen::setLocation(Location(m_board.getSizeOfRow() + 1, 0));
        std::cout << "lives" << m_player.getLives() << std::endl;
        // Add a way to exit the level or game
        // For example, ESC key or reaching a specific condition
    }
    if (levelComplete)
    {
        getPoints(numOfGuards);
        clearingLevel();
    }

    //points lives
}
//------------------------
bool Controller::checkHit(const Location& other)
{
    for (int start = 0; start < m_guards.size(); start++)
    {
        if (m_guards[start].isAlive() && other.row == m_guards[start].getGuardLoc(0).row
            && other.col == m_guards[start].getGuardLoc(0).col)
        {
            m_player.decLives();
            return true;
        }
    }
    return false;
}
//-------------------------
void Controller::resetPos(const Location& playerloc)
{
    m_board.updatboard(playerloc, m_player.getPlayerLoc(START_POSTION), '/');
    m_player.setLoc(m_player.getPlayerLoc(START_POSTION));
    for (int start = 0; start < m_guards.size(); start++)
    {
        if (m_guards[start].isAlive())
        {
            m_board.updatboard(m_guards[start].getGuardLoc(0), m_guards[start].getGuardLoc(START_POSTION), '!');
            m_guards[start].setLoc(m_guards[start].getGuardLoc(START_POSTION));
        }
    }
    for (int start = 0; start < static_cast<int> (m_bombs.size()); start++)
    {
        m_board.printBomb(m_bombs[start].getBombsLoc(), ' ', 1);
    }
    m_bombs.clear();
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
                m_board.updatboard(currLocGuard, m_guards[guard].getGuardLoc(0), '!');
                guardsVsPlayer(player);
            }

        }
    }
}
// ----------------
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
bool Controller::lostGame()
{
    if (m_player.getLives() == 0)
    {
		clearingLevel();
        std::cout << " fuck you all";
        //clearingLevel();
        return true;
    }

    return false;
}
//----------------------------------
void  Controller::setAbomb(const Location& player)
{
    m_bombs.push_back(Bombs(player));
    Screen::setLocation(player);
    m_board.printBomb(player, '%', 1);
}
//--------------------------------------
void Controller::bombsUpdate()
{
    for (int bomb = static_cast<int> (m_bombs.size()) - 1; bomb > -1 ; bomb--)
    {
        m_bombs[bomb].decTimer();
        int timer = m_bombs[bomb].getTimer();
        if (timer == 0)
        {
            explosion(bomb, '*');
        }
        else if (timer < 0)
        {
            explosion(bomb, ' ');
            m_bombs.erase(m_bombs.begin() + bomb);
        }
        else
        {
            m_board.printBomb(m_bombs[bomb].getBombsLoc(), static_cast<char> (timer + '0'), 0);
        }
    }
}
//------------------------------------
void Controller::explosion(int cell, char wanted)
{
    if (cell >= 0 && cell < static_cast<int>(m_bombs.size()))
    {
        Location bomb = m_bombs[cell].getBombsLoc();
        m_board.printBomb(bomb, wanted, 1);
        //check if there is a player or a guard
          checkPlayerGuard(wanted);
        for (int neighbor = 1; neighbor < NEIGHBORSIZE; neighbor++)
        {
            m_board.printBomb(m_bombs[cell].getNeighbor(bomb, neighbor), wanted, 1);
            //check if there is a player or a guard
            checkPlayerGuard(wanted);
        }
    }
}
//----------------
void Controller::checkPlayerGuard(char wanted)
{  
    if (wanted == '*')
    {
        Location playerLoc = m_player.getPlayerLoc(0);
        bool playerHitByBomb = false;
        for (int bomb = 0; bomb < static_cast<int> (m_bombs.size()); bomb++)
        {
            Location temp = m_bombs[bomb].getBombsLoc();
            for (int guard = static_cast<int> (m_guards.size()) - 1; guard > -1; guard--)
            {
                Location guardLoc = m_guards[guard].getGuardLoc(0);
                if ((temp.col == guardLoc.col) && (temp.row == guardLoc.row))
                {
                    // Remove the guard from the board
                    //m_board.updatboard(guardLoc, guardLoc, ' ');

                    // Remove the guard from the guards vector
                    //m_guards.erase(m_guards.begin() + guard);
                    m_guards[guard].setAlive(false);
                    m_board.updatboard(guardLoc, guardLoc, ' ');
                    m_guards.erase(m_guards.begin() + guard);
					//m_board.printBomb(guardLoc, ' ');
                }
            }
        }

        for (int bomb = 0; bomb < static_cast<int> (m_bombs.size()); bomb++)
        {
            Location temp = m_bombs[bomb].getBombsLoc();
            if ((temp.col == playerLoc.col) && (temp.row == playerLoc.row))
            {
                //resetPos(playerLoc);
                playerHitByBomb = true;
                return;
            }
        }
        if (playerHitByBomb)
        {
            resetPos(playerLoc);
        }
    }
}
//-------------------
void Controller::getPoints(int startGuards)
{
    int numOfGuards = static_cast<int> (m_guards.size());
    int points = 0;
    points += ENDING_LEVEL;
    points += (startGuards * POINT_FOR_GUARD);
    points += (std::abs(numOfGuards - startGuards) * KILL_GUARD);
    m_player.setPoints(points);
}
//-------------------
void Controller::clearingLevel()
{
	m_guards.clear();
	m_bombs.clear();
    system("cls");
}