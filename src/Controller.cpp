#include "Controller.h"
#include <iostream>
#include <string>
#include <fstream>


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

	while()
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
