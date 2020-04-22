#pragma once

#include <Windows.h>
#include <conio.h>
#include <ctime>
#include <iostream>

using namespace std;

//
// 콘솔창을 이용할 때 유용한 함수들을 정의
// Utility 클래스는 정적클래스로 표현하기 위해 정적함수들만 포함하고 있다.
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