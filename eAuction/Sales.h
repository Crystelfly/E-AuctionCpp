#pragma once
#include<iostream>

using namespace std;

class CSales
{
public: 
	CSales();
	virtual ~CSales();
public:
	void displaySales();
	void addSales(const string& uid);
	void updateSales();
	void deleteSales();
	void finaliseBid();

protected:

private:
};

