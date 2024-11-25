#pragma once
#include <vector> 
#include <string>
#include "Board.h"

class Controller
{
public:
	Controller();
	void GetBoard();
	void run();

private:
	void Loading();
	Board m_level;
	//std::vector <std::string>;
};