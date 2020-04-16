#include "Utility.h"

void Utility::gotoxy(int x, int y)
{
	HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;

	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(consoleHandler, pos);
}

void Utility::setColor(int color, int bgColor)
{
	HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	color &= 0xf;
	bgColor &= 0xf;

	SetConsoleTextAttribute(consoleHandle, (bgColor << 4) | color);
}