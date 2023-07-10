#pragma once
#include <iostream>
using namespace std;

class Test
{
public:
	Test();
	virtual ~Test();
public:
	virtual void MKPrint();
};

class IndiaPrint:public Test
{
public:
	IndiaPrint();
	virtual ~IndiaPrint();
public:
	void MKPrint();
};

class cChinaPrint :public Test
{
public:
	cChinaPrint();
	virtual ~cChinaPrint();
public:
	void MKPrint();
};

class cKoreaPrint :public Test
{
public:
	cKoreaPrint();
	virtual ~cKoreaPrint();
public:
	void MKPrint();
};

enum eTest
{
	eIndiaPrint=1,
	eChinaPrint=2,
	eKoreaPrint=3

};
Test* TestFactory(eTest nClassType);
