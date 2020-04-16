#pragma once

#include "Utility.h"

//
// "싱글톤 템플릿 클래스 제작"
// 관리자 객체는 해당 클래스를 상속받아 구현한다.
//

template <class T>
class Singleton
{
protected:
	Singleton() { cout << "singleton 생성\n"; }

	virtual ~Singleton() { cout << "singleton 소멸\n"; }

public:
	static T& instance()
	{
		static T _instance;

		return _instance;
	}

private:
	Singleton(const Singleton&) { }
	Singleton& operator=(const Singleton&) { }
};