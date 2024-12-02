#pragma once

#include "Location.h"
#include "io.h"
#include "Consts.h"



class Player
{
public:
	Player( const Location& other);
	Player();
	Location getPlayerLoc(int option) const;
	void setLoc(const Location& other);
	int getLives() const;
	void decLives();
	void move(int step);
	//bool isMoveGood() const;

private:
	Location m_loc;
	Location m_startPosPlayer;
	//Board m_updateBoard;
	int m_lives = START_LIFE;
	int m_points = 0;
};