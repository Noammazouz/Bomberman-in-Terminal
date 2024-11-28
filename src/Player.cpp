#include "Player.h"
//#include <iostream>
#include <conio.h>
#include <string>

Player::Player()
	: m_updateBoard()
{

}

void Player::move()
{
	auto step = _getch();
	Location prevLoc = m_loc;
	if (step == Keys::SPECIAL_KEY)
	{
		step = _getch();
		switch (step)
		{
		case SpecialKeys::UP:
		{
			if (m_updateBoard.ismovevalid(m_loc, SpecialKeys::UP))
			{
				m_loc.row--;
				m_updateBoard.updatboard(prevLoc, m_loc);
			}
			break;
		}
		case SpecialKeys::DOWN:
		{
			m_loc.row++;
			m_updateBoard.updatboard(prevLoc, m_loc);
			break;
		}
		case SpecialKeys::RIGHT:
		{
			m_loc.col++;
			m_updateBoard.updatboard(prevLoc, m_loc);
			break;
		}
		case SpecialKeys::LEFT:
		{
			m_loc.col--;
			m_updateBoard.updatboard(prevLoc, m_loc);
			break;
		}
		}
	}
}
//----------------------------
void Player::setLoc(const Location& other)
{
	m_loc = other;
}
