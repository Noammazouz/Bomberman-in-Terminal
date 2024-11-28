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
	Location getLoc(char wanted) const;
	//int GetCell(Location loc);

private:
	std::vector<std::string> m_board;
	std::vector<std::string> m_wall;
	std::vector<std::string> m_rock;
	char m_door;
	//int m_currStage = 1;
};