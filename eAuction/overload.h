#pragma once
#include <iostream>
using namespace std;

class Coverload
{
public:
	Coverload();
	~Coverload();
	public:
	virtual void fruit(string name);
	void fruit(int price);
	void template1();
};

class Coverload2: public Coverload
{
public:
	Coverload2();
	~Coverload2();
public:
	virtual void fruit(string name);
	void fruit(int price);
};

