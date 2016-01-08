#include "Board.h"
#include "ViewConsole.h"

int main()
{
	Board b;
	ViewConsole v(&b);

	v.start();

	return 0;
}