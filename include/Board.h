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
	void print() const;
	Location getLoc(char wanted, const Location& other) const;
	void updateBoard(const Location& prevLoc, const Location& newLoc, char wanted);
	bool isMoveValid(const Location& loc, int direction, int option) const;
	int getSizeOfRow() const;
	int getSizeOfCol() const;
	void printBomb(const Location& loc, char wanted, int select);
	void printLeaderBoard(int level, int lives, int points);

private:
	std::vector<std::string> m_board;
	int sizeRow = 0;
	int sizeCol = 0;	
};