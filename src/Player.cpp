#include "Player.h"

Player::Player(const Location& other)
    : m_loc(other),m_startPosPlayer(other)
{
}

Player::Player()
    : m_loc({ 0, 0 }), m_lives(START_LIFE), m_points(0), m_startPosPlayer({ 0, 0 })
{
}

Location Player::getPlayerLoc(int option) const
{
    switch (option)
    {
    case 0:
        return m_loc;
        break;
    case START_POSTION:
        return m_startPosPlayer;
        break;
    }
}

void Player::setLoc(const Location& other)
{
   m_loc = m_startPosPlayer = other;
}

void Player::move(int step)
{
    switch (step)
    {
        case SpecialKeys::UP:
            m_loc.row--;
            break;
        case SpecialKeys::DOWN:
            m_loc.row++;
            break;
        case SpecialKeys::RIGHT:
            m_loc.col++;
            break;
        case SpecialKeys::LEFT:
            m_loc.col--;
            break;
    }
}

//----------------------------
int Player::getLives() const
{
    return m_lives;
}

void Player::decLives()
{
    m_lives--;
}