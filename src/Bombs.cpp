#include "Bombs.h"


Bombs::Bombs()
	: m_loc({ 0, 0 })
{}
//--------------------------
Bombs::Bombs(const Location& other)
	: m_loc(other)
{}
//--------------------------
Location Bombs::getNeighbor(const Location& other, int direction)
{
	switch (direction)
	{
	case 1: // UP
		return Location(other.row - 1, other.col); 
	case 2: // DOWN
		return Location(other.row + 1, other.col);
	case 3: // LEFT
		return Location(other.row, other.col - 1);
	case 4: // RIGHT
		return Location(other.row, other.col + 1);
	}
}
//--------------------------------
void Bombs::setBombsLoc(const Location& other)
{
	m_loc = other;
}
void Bombs::decTimer()
{
	m_timer--;
}
Location Bombs::getBombsLoc() const
{
	return m_loc;
}
int Bombs::getTimer() const
{
	return m_timer;
}