#pragma once

#include "Location.h"
#include "io.h"
#include "Consts.h"
#include "Board.h"



class Player
{
public:
	Player( const Location& other);
	Player();
	const Location& getPlayerLoc() const;
	void setLoc(const Location& other);
	void move(int step);
	//bool isMoveGood() const;

private:
	Location m_loc;
	//Board m_updateBoard;
	int m_lives = START_LIFE;
	int m_points = 0;
};