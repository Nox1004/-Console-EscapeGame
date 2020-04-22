#pragma once

#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iostream>

using namespace std;

//
// �ܼ�â�� �̿��� �� ������ �Լ����� ����
// Utility Ŭ������ ����Ŭ������ ǥ���ϱ� ���� �����Լ��鸸 �����ϰ� �ִ�.
//

class Utility
{
public:
	enum Color { black, blue, green, cyan, red, purple, brown, lightgray, darkgray, lightblue, lightgreen, lightcyan, lightred, lightpurple, yellow, white };

public:
	static void gotoxy(int x, int y);

	static void setColor(int color, int bgColor);

	static void clean();

	static void delay(float time);

	static void textSleep(const char *pStr, DWORD dwMilliseconds);
};