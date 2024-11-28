#pragma once

#include "Location.h"
#include "io.h"
#include "Consts.h"
#include "Board.h"



class Player
{
public:
	Player();
	void setLoc(const Location& other);
	void move();
	//bool isMoveGood() const;

private:
	Location m_loc;
	Board& m_updateBoard;
	int m_lives = START_LIFE;
	int m_points = 0;
};