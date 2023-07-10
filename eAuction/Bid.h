#pragma once
#include<iostream>

using namespace std;

class CBid
{
public:
	CBid();
	virtual ~CBid();
public:
	void displayBid();
	void addBid(const string& uid);
	void updateBid();
	void deleteBid();
	void Bid_finalising();
	void Payment();

protected:

private:
};

