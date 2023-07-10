#pragma once

#include<iostream>

using namespace std;


class CSub_Menu
{
public:
	CSub_Menu();
	virtual ~CSub_Menu();
public:
	void auctionItemMenu();
	void auctionSaleMenu(const string& uid);
	void auctionBidMenu(const string& uid);
	void auctionSubMenu(string uid);
protected:

private:

};

