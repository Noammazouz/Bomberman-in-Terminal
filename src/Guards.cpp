#include "Guards.h"
#include <ctime>
#include <cstdlib>
#include <cmath>

Guards::Guards(const Location& other)
    :m_loc_guard(other), m_firstLoc(other), m_alive(true)
{
	std::srand(std::time(nullptr));
	m_counter = std::rand() % 3;
}
//------------------------------
Location Guards::getGuardLoc(int option) const
{
    switch (option)
    {
    case 0:
        return m_loc_guard;
        break;
    case START_POSTION:
        return m_firstLoc;
        break;
    }

}
//----------------------------
int Guards::getCounter() const
{
	return m_counter;
}
//-----------------
int Guards::selectDirection(const Location& other)
{
    int yDistance = m_loc_guard.row - other.row;
    int xDistance = m_loc_guard.col - other.col;

    if (std::abs(yDistance) > std::abs(xDistance))
    {
        if (yDistance > 0)
        {
            return SpecialKeys::UP;
        }
        else
        {
            return SpecialKeys::DOWN;
        }
    }
    else
    {
        if (xDistance > 0)
        {
            return SpecialKeys::LEFT;
        }
        else
        {
            return SpecialKeys::RIGHT;
        }
    }

    return 0;//just for error
}
//------------------------
void Guards::moveTheGuard(int step)
{
    switch (step)
    {
    case SpecialKeys::UP:
        m_loc_guard.row--;
        break;
    case SpecialKeys::DOWN:
        m_loc_guard.row++;
        break;
    case SpecialKeys::RIGHT:
        m_loc_guard.col++;
        break;
    case SpecialKeys::LEFT:
        m_loc_guard.col--;
        break;
    }
}
//--------------------------
bool Guards::isAlive() const
{
    return m_alive;
}
//----------
void Guards::setLoc(const Location& other)
{
    m_loc_guard = other;
}