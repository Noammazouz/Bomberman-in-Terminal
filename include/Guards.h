#pragma once

#include "Location.h"
#include "io.h"
#include "Consts.h"

class Guards
{
public:
	Guards(const Location& other);
	Location getGuardLoc(int option) const;
	int selectDirection(const Location& other) const;
	int getCounter() const;
	bool isAlive() const;
	void setAlive(bool alive);
	void setLoc(const Location& other);
	void moveTheGuard(int step);

private:
	Location m_loc_guard;
	Location m_firstLoc;
	int m_counter;
	bool m_alive;
};
