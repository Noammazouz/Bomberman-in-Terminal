#include "Player.h"

Player::Player(const Location& other)
    : m_loc(other)
{
}

Player::Player()
    : m_loc({ 0, 0 }), m_lives(START_LIFE), m_points(0)
{
}

const Location& Player::getPlayerLoc() const
{
    return m_loc;
}

void Player::setLoc(const Location& other)
{
    m_loc = other;
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