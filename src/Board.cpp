#include "Board.h"
#include "Consts.h"
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>



Board::Board() : m_board()
{

}
int Board::Loading(int currStage)
{
	m_board.clear();
	auto line = std::string();
	std::string currFileName = std::string("Level") + std::to_string(currStage) + ".txt";
	std::ifstream file(currFileName);
	if (!file)
	{
		// erase the board and then cout;
		std::cout << "You are the best You beat me";
		return END_GAME;
	}

	while (std::getline(file, line))
	{
		m_board.push_back(line);
	}
}
/// ------------
void Board::print()
{
	for (auto temp : m_board)
		std::cout << temp << std::endl;
}
//------------------
Location Board::getLoc(char wanted) const
{
	for (int row = 0; row < m_board.size(); row++)
	{
		for (int col = 0; col < m_board[row].size(); col++)
		{
			if (m_board[row][col] == wanted)
			{
				Location loc(row, col);
				return loc;
			}
		}
	}

	Location notFound( -1, -1);
	return notFound;
}
