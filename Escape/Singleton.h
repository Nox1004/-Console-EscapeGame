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