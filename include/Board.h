#pragma once
#include "Location.h"
#include <string>
#include <vector>


class Controller;

class Board
{
public:
	Board();
	int Loading(int currStage);
	void print();
	Location getLoc(char wanted);
	//int GetCell(Location loc);

private:
	std::vector<std::string> m_board;
	//int m_currStage = 1;
};