#pragma once

#include "Location.h"
#include "io.h"
#include "Consts.h"

class Guards
{
public:
	Guards(const Location& other);
	Location getGuardLoc(int option) const;
	void move(int counter);
	int getCounter() const;
	bool isAlive() const;
	void setLoc(const Location& other);

private:
	Location m_loc_guard;
	Location m_firstLoc;
	int m_counter;
	bool m_alive;
};
