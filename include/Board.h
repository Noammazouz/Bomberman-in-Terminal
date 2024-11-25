#pragma once
#include <string>
#include <vector>


class Controller;

class Board
{
public:
	Board();
	void getLevel(std::ifstream currFileName);
	//int GetCell(Location loc);

private:
	std::vector<std::string> m_board;
};