#pragma once

#include "Utility.h"

//
// "�̱��� ���ø� Ŭ���� ����"
// ������ ��ü�� �ش� Ŭ������ ��ӹ޾� �����Ѵ�.
//

template <class T>
class Singleton
{
protected:
	Singleton() { cout << "singleton ����\n"; }

	virtual ~Singleton() { cout << "singleton �Ҹ�\n"; }

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