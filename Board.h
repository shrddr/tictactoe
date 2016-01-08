#pragma once

enum Cell { EMPTY, X, O };
enum State { NOWIN, XWIN, OWIN, DRAW };

class Board
{
private:
	static const int SIZE = 3;
	static const int WINLEN = 3;
	Cell b[SIZE][SIZE];
public:
	Board();
	int getSize();
	bool makeMove(int x, int y, Cell s);
	Cell getCell(int x, int y);
	State getState();
};

