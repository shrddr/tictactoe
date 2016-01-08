#pragma once

class ViewConsole
{
private:
	Board *board;
	void show();
public:
	ViewConsole(Board *b);
	void start();
};

