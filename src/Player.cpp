#include "Player.h"
//#include "StaticObjects.h"
#include <conio.h>
#include <string>



void Player::move()
{
	auto step = _getch();
	switch (step)
	{
	case SpecialKeys::UP:
	{
		if (isMoveGood())
		{
			m_player = std::string(space);
				m_player.col--;
			//space in location of player
			//set_location and then put player
		}
	}
	case SpecialKeys::DOWN:
	{

	}
	case SpecialKeys::RIGHT:
	{

	}
	case SpecialKeys::LEFT:
	{

	}
	}
}