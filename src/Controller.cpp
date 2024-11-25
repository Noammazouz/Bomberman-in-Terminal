#include "Controller.h"
#include <iostream>
#include <string>


using std::string;

void Controller::run()
{

}
//------------------------
void Controller::Loading()
{
	string currFileName = string("Level") + std::to_string(m_currStage) + ".txt";
	std::ifstream file(currFileName);
	if (!file)
	{
		// erase the board and then cout;
		std::cout << "You are the best You beat me" 
	}
}
//------------------------
void GetBoard()
{
	return m_board.getLevel();
}
//-------------------------
void PlayStage()
{

}