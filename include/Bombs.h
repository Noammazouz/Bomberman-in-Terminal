#pragma once

#include "Location.h"


class Bombs
{
public:
	Bombs();
	Bombs(const Location& other);
	Location getNeighbor(const Location& other, int direction);
	Location getBombsLoc() const;
	void setBombsLoc(const Location& other);
	void decTimer();
	int getTimer() const;

private:
	int m_timer = 5;
	Location m_loc;
};