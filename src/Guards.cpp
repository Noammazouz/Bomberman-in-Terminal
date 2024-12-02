#include "Guards.h"
#include <ctime>
#include <cstdlib>

Guards::Guards(const Location& other)
    :m_loc_guard(other), m_firstLoc(other), m_alive(true)
{
	std::srand(std::time(nullptr));
	m_counter = std::rand() % 10;
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
void Guards::move(int counter)
{

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