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

void Utility::clean()
{
	system("cls");
}

void Utility::delay(float time)
{
	clock_t delay = static_cast<clock_t>(time * CLOCKS_PER_SEC);

	clock_t start = clock();

	while (clock() - start < delay) { }
}

void Utility::delay(float time, bool* bValue)
{
	clock_t delay = static_cast<clock_t>(time * CLOCKS_PER_SEC);

	clock_t start = clock();

	while (*bValue && clock() - start < delay) { }

	if (*bValue)
		*bValue = false;
}


void Utility::textSleep(const char *pStr, DWORD dwMilliseconds)
{
	cout << pStr;
	Sleep(dwMilliseconds);
}