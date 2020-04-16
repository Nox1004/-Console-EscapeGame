#include "InputMgr.h"

int InputMgr::getControl()
{
	int input{ -1 };
	int key = _getch();

	if (key == 224 || key == 0)
	{
		key = _getch();

		switch (key)
		{
		case 72:
			input = Up;
			break;

		case 75:
			input = Left;
			break;

		case 77:
			input = Right;
			break;

		case 80:
			input = Down;
			break;
		}
	}
	else if (key == 13)
	{
		input = Enter;
	}

	return input;
}