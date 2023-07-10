#pragma once
#include<iostream>

using namespace std;

class CItems
{
public: 
	CItems();
	virtual ~CItems();
public:
	void add_item();
	void displayItems();
	void editItems();
	void deleteItems();


protected:

private:
};

