#pragma once
#include <vector> 
#include <string>
#include "Board.h"

class Controller
{
public:
	Controller();
	void GetBoard();
	std::vector<std::string> Loading();
	void run();

private:
	
	int m_currStage;
	Board m_level;
	//std::vector <std::string>;
};