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

}

int Utility::inputContol()
{
	int result{ -1 };

	int key = _getch();

	if (key == 224 || key == 0)
	{
		key = _getch();

		switch (key)
		{
		case 72:
			result = UP;
			break;

		case 75:
			result = LEFT;
			break;

		case 77:
			result = RIGHT;
			break;

		case 80:
			result = DOWN;
			break;
		}
	}

	else if (key == 13)
	{
		result = ENTER;
	}

	return result;
}