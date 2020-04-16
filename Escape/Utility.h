#pragma once

#include <Windows.h>
#include <conio.h>
#include <iostream>

using namespace std;

class Utility
{
public:
	enum KeyInput { UP=0, DOWN, LEFT, RIGHT, ENTER };

public:
	static void gotoxy(int x, int y);

	static void setColor(int color, int bgColor);

	static int inputContol();
};