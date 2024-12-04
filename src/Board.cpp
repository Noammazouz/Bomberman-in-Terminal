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
        std::cout << "You are the best! You beat me!" << std::endl;
        return END_GAME;
    }

    while (std::getline(file, line))
    {
        m_board.push_back(line);
    }

    sizeRow = static_cast<int>(m_board.size()) - 1;
    sizeCol = static_cast<int>(m_board[sizeRow].size()) - 1;

    return currStage;
}

void Board::print()
{
    for (const auto& temp : m_board)
        std::cout << temp << std::endl;
}

Location Board::getLoc(char wanted, const Location& other) const
{
    int col = other.col;
    for (int row = other.row; row < static_cast<int>(m_board.size()); row++)
    {
        for (; col < static_cast<int>(m_board[row].size()); col++)
        {
            if (m_board[row][col] == wanted)
            {
                return Location(row, col);
            }
        }
        if (col == static_cast<int>(m_board[row].size()))
        {
            col = 0;
        }
    }
    return Location(0, 0); // Return invalid location if not found
}

void Board::updatboard(const Location& prevLoc, const Location& newLoc, char wanted)
{
    // Remove player from previous location
    if (prevLoc.row >= 0 && prevLoc.row < static_cast<int>(m_board.size()) &&
        prevLoc.col >= 0 && prevLoc.col < static_cast<int>(m_board[prevLoc.row].size()))
    {
        m_board[prevLoc.row][prevLoc.col] = ' ';
    }

    // Place player at new location
    if (newLoc.row >= 0 && newLoc.row < static_cast<int>(m_board.size()) &&
        newLoc.col >= 0 && newLoc.col < static_cast<int>(m_board[newLoc.row].size()))
    {
        m_board[newLoc.row][newLoc.col] = wanted;
    }

    // Update screen
    Screen::setLocation(prevLoc);
    std::cout << ' ';
    Screen::setLocation(newLoc);
    std::cout << wanted;
}

bool Board::ismovevalid(const Location& loc, int direction, int option) const
{
    if (option == 0)
    {
        switch (direction)
        {
        case SpecialKeys::UP:
            return (loc.row > 0 && m_board[loc.row - 1][loc.col] != WALL && m_board[loc.row - 1][loc.col] != ROCK);

        case SpecialKeys::DOWN:
            return (loc.row < sizeRow && m_board[loc.row + 1][loc.col] != WALL && m_board[loc.row + 1][loc.col] != ROCK);

        case SpecialKeys::RIGHT:
            return (loc.col < sizeCol && m_board[loc.row][loc.col + 1] != WALL && m_board[loc.row][loc.col + 1] != ROCK);

        case SpecialKeys::LEFT:
            return (loc.col > 0 && m_board[loc.row][loc.col - 1] != WALL && m_board[loc.row][loc.col - 1] != ROCK);

        }
    }
    else
    {
        switch (direction)
        {
        case SpecialKeys::UP:
            return (loc.row > 0 && m_board[loc.row - 1][loc.col] != WALL && m_board[loc.row - 1][loc.col] != ROCK
                && m_board[loc.row - 1][loc.col] != DOOR);

        case SpecialKeys::DOWN:
            return (loc.row < sizeRow && m_board[loc.row + 1][loc.col] != WALL && m_board[loc.row + 1][loc.col] != ROCK &&
                m_board[loc.row + 1][loc.col] != DOOR);

        case SpecialKeys::RIGHT:
            return (loc.col < sizeCol && m_board[loc.row][loc.col + 1] != WALL && m_board[loc.row][loc.col + 1] != ROCK && 
                    m_board[loc.row][loc.col + 1] != DOOR);

        case SpecialKeys::LEFT:
            return (loc.col > 0 && m_board[loc.row][loc.col - 1] != WALL && m_board[loc.row][loc.col - 1] != ROCK &&
                    m_board[loc.row][loc.col - 1] != DOOR);

        }
    }
    return false;
}

int Board::getSizeOfRow() const
{
    return sizeRow;
}

int Board::getSizeOfCol() const
{
    return sizeCol;
}