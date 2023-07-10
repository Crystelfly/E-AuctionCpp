#pragma once
#include <iostream>
using namespace std;

class IBase
{
public:
	IBase();
	virtual ~IBase();
public:
	virtual void person_name();
	void type();
};

class CApple:public IBase
{
public:
	CApple();
	virtual ~CApple();
public:
	virtual void person_name();
};


