#include "Board.h"

Board::Board()
{
    for (int x = 0; x < SIZE; x++)
        for (int y = 0; y < SIZE; y++)
			b[x][y] = EMPTY;
}

int Board::getSize()
{
	return SIZE;
}

bool Board::makeMove(int x, int y, Cell s)
{
	if ((x >= 0) && (x < SIZE) && (y >= 0) && (y < SIZE))
	{
		b[x][y] = s;
		return true;
	}
		
	else
		return false;
}

Cell Board::getCell(int x, int y)
{
	return b[x][y];
}

State Board::getState()
{
	// check for xwin and owin
	int xcount, ocount;

	// vertically
    for (int x = 0; x < SIZE; x++)
	{
		xcount = ocount = 0;
        for (int y = 0; y < SIZE; y++)
		{
			if (b[x][y] == X) xcount++;
			else xcount = 0;
			if (b[x][y] == O) ocount++;
			else ocount = 0;
		}
		if (xcount == WINLEN) return XWIN;
		if (ocount == WINLEN) return OWIN;
	}

	// horizontally
    for (int y = 0; y < SIZE; y++)
	{
		xcount = ocount = 0;
        for (int x = 0; x < SIZE; x++)
		{
			if (b[x][y] == X) xcount++;
			else xcount = 0;
			if (b[x][y] == O) ocount++;
			else ocount = 0;
		}
		if (xcount == WINLEN) return XWIN;
		if (ocount == WINLEN) return OWIN;
	}

	// diagonally from left to bottom
    for (int i = 0; i < SIZE; i++)
	{
		int x = 0;
		int y = i;
		xcount = ocount = 0;
        for (int d = 0; d < SIZE - i; d++)
		{
			if (b[x+d][y+d] == X) xcount++;
			else xcount = 0;
			if (b[x+d][y+d] == O) ocount++;
			else ocount = 0;
		}
		if (xcount == WINLEN) return XWIN;
		if (ocount == WINLEN) return OWIN;
	}

	// diagonally from top to right
    for (int i = 0; i < SIZE; i++)
	{
		int x = i;
		int y = 0;
		xcount = ocount = 0;
        for (int d = 0; d < SIZE - i; d++)
		{
			if (b[x+d][y+d] == X) xcount++;
			else xcount = 0;
			if (b[x+d][y+d] == O) ocount++;
			else ocount = 0;
		}
		if (xcount == WINLEN) return XWIN;
		if (ocount == WINLEN) return OWIN;
	}

	// diagonally from top to left
    for (int i = 0; i < SIZE; i++)
	{
		int x = i;
		int y = 0;
		xcount = ocount = 0;
        for (int d = 0; d < i + 1; d++)
		{
			if (b[x - d][y + d] == X) xcount++;
			else xcount = 0;
			if (b[x - d][y + d] == O) ocount++;
			else ocount = 0;
		}
		if (xcount == WINLEN) return XWIN;
		if (ocount == WINLEN) return OWIN;
	}

	// diagonally from right to bottom
    for (int i = 0; i < SIZE; i++)
	{
		int x = SIZE - 1;
		int y = i;
		xcount = ocount = 0;
        for (int d = 0; d < SIZE - i; d++)
		{
			if (b[x - d][y + d] == X) xcount++;
			else xcount = 0;
			if (b[x - d][y + d] == O) ocount++;
			else ocount = 0;
		}
		if (xcount == WINLEN) return XWIN;
		if (ocount == WINLEN) return OWIN;
	}



	// nowin and board filled: draw
	int count = 0;
    for (int x = 0; x < SIZE; x++)
        for (int y = 0; y < SIZE; y++)
			if (b[x][y] != EMPTY) count++;
	if (SIZE*SIZE == count) return DRAW;

	// else: nowin
	return NOWIN;
}
