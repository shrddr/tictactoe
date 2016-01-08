#include <stdio.h>
#include "Board.h"
#include "ViewConsole.h"

ViewConsole::ViewConsole(Board *b)
{
	board = b;
}

void ViewConsole::start()
{
	while (board->getState() == NOWIN)
	{
		static bool turnX = true;

		int x, y;
		bool correct;

		do {
			printf(turnX ? "player X, your turn: " : "player O, your turn: ");
            scanf("%d %d", &x, &y);
			correct = board->makeMove(x, y, turnX ? X : O);
		} while (!correct);
		
		show();

		turnX = !turnX;
	}

	switch (board->getState())
	{
	case XWIN:
        printf("X wins\n");
		break;
	case OWIN:
        printf("O wins\n");
		break;
	case DRAW:
        printf("draw\n");
		break;
	}
	
}

void ViewConsole::show()
{
	for (size_t y = 0; y < board->getSize(); y++)
	{
		for (size_t x = 0; x < board->getSize(); x++)
		{
			switch (board->getCell(x, y))
			{
			case EMPTY:
				printf(".");
				break;
			case X:
				printf("X");
				break;
			case O:
				printf("O");
				break;
			}
		}
		printf("\n");
	}
}
