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
	Singleton() { }

	virtual ~Singleton() { }

public:
	static T* instance()
	{
		if (!_pinstance)
			_pinstance = new T();

		return _pinstance;
	}

private:
	Singleton(const Singleton&) { }
	Singleton& operator=(const Singleton&) { }

private:
	static T* _pinstance;
};

template<class T> 
T* Singleton<T>::_pinstance = nullptr;