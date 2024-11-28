#include "Board.h"
#include "Consts.h"
#include "io.h"
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
	sizeRow = (int)m_board.size()-1;
	sizeCol = (int)m_board[sizeRow].size()-1;
	return currStage;
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
//--------
void Board::updatboard(const Location& prevLoc, const Location& newLoc)
{
	//std::cout << "I have arrived" << std::endl;
	//m_board[prevLoc.row][prevLoc.col] = ' ';
	//m_board[newLoc.row][newLoc.col] = '/';
	if (prevLoc.row >= 0 && prevLoc.row < m_board.size() &&
		prevLoc.col >= 0 && prevLoc.col < m_board[prevLoc.row].size())
	{
		m_board[prevLoc.row][prevLoc.col] = ' '; // Clear the previous location
	}

	if (newLoc.row >= 0 && newLoc.row < m_board.size() &&
		newLoc.col >= 0 && newLoc.col < m_board[newLoc.row].size())
	{
		m_board[newLoc.row][newLoc.col] = '/'; // Update the new location with a character
	}
	Screen::setLocation(prevLoc);
	std::cout << ' ';
	Screen::setLocation(newLoc);
	std::cout << '/';
	
}

//-----------------
bool Board::ismovevalid(const Location& loc, int direction) const
{
	switch (direction)
	{
		case SpecialKeys::UP:
		{
			std::cout << m_board.size();
			if (loc.row > 0 && m_board[loc.row-1][loc.col]!=WALL)
			{
				return true;
			}
			break;
		}
		case SpecialKeys::DOWN:
		{
			if (loc.row < sizeRow)
			{
				return true;
			}
			break;
		}
		case SpecialKeys::RIGHT:
		{
			if (loc.col < sizeCol)
			{
				return true;
			}
			break;
		}
		case SpecialKeys::LEFT:
		{
			if (loc.col > 0)
			{
				return true;
			}
			break;
		}
	}
	return false;
}
//--------------------
int Board::getSizeOfRow() const
{
	return sizeRow;
}
//---------------
int Board::getSizeOfCol() const
{
	return sizeCol;
}