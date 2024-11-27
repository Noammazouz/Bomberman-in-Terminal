#pragma once

#include "Location.h"
#include "io.h"
#include "Consts.h"



class Player
{
public:
	Player() = default;
	void move();

private:
	Location m_player;
	int m_lives = START_LIFE;
	int m_points = 0;
};