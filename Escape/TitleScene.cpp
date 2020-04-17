#include "TitleScene.h"
#include "Utility.h"

TitleScene::TitleScene() : _cntidx{ 0 } { }

void TitleScene::run()
{
	system("mode con cols=56 lines=32 | title 테스트");
	
	titleDraw();

	menuDraw();
	
	menuChoice();
}

void TitleScene::titleDraw()
{
	Utility::setColor(Utility::white, Utility::black);
	cout << "\n\n";
	cout << "	&&&&&   &&&    &&&    &    &&&&&   &&&&&  \n";
	cout << "	&      &      &      & &   &    &  &      \n";
	cout << "	&&&&   &&&&   &     &&&&&  &&&&&   &&&&   \n";
	cout << "	&          &  &     &   &  &       &      \n";
	cout << "	&&&&&  &&&&    &&&  &   &  &       &&&&&  \n";
	cout << "\n";
	cout << "	       &&&     &    &     &  &&&&&  \n";
	cout << "	      &       & &   &&   &&  &      \n";
	cout << "	      & &&&  &&&&&  & & & &  &&&&   \n";
	cout << "	      &   &  &   &  &  &  &  &      \n";
	cout << "	       &&&   &   &  &     &  &&&&&  \n";
	cout << "\n";
}

void TitleScene::menuDraw()
{
	// 커서위치 설정
	setX(20);
	setY(15);
	
	Utility::setColor(Utility::lightgreen, Utility::black);
	Utility::gotoxy(_x, _y);
	cout << "> 게 임 시 작  ";
	
	Utility::setColor(Utility::white, Utility::black);
	Utility::gotoxy(_x, _y + 1);
	cout << "  게 임 정 보  ";

	Utility::gotoxy(_x, _y+2);
	cout << "     종 료     \n";
}

void TitleScene::menuChoice()
{
	/*while (1)
	{
		int input = Utility::inputContol();

		switch (input)
		{
		case Utility::UP:
			if (_cntidx != 0)
			{
				Utility::gotoxy(_x, _y);
				cout << " ";

				_y -= 1;

				Utility::gotoxy(_x, _y);
				cout << ">";

				_cntidx--;
			}
			break;

		case Utility::DOWN:
			if (_cntidx != 2)
			{
				Utility::gotoxy(_x, _y);
				cout << " ";

				_y += 1;

				Utility::gotoxy(_x, _y);
				cout << ">";

				_cntidx++;
			}
			break;

		case Utility::ENTER:

			break;
		}
	}*/
}
