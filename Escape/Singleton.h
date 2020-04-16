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
	static T& instance()
	{
		static T _instance;

		return _instance;
	}

private:
	Singleton(const Singleton&) { }
	Singleton& operator=(const Singleton&) { }
};