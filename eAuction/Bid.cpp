#include "Bid.h"
#include "Library.h"
#include <SQLAPI.h>
#include <sstream>
#include "Common.h"
#include <iostream>

CBid::CBid()
{
}
CBid::~CBid()
{
}

void CBid::displayBid()

{
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA("Select * from Bidding"));

        // this instructs the library to allocate a buffer for 100 rows
        // and, using respective native API, request data from server in pages of 100 rows
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        cout << "----------------------------Bidding List-----------------------------\n";
        cout << "Bid\tSid\tUid\tBidding Price \tBid Finalise \tSecurity_Fees\n";
        cout << "---------------------------------------------------------------------\n";
        while (cmd.FetchNext())
        {
            // printf("Name: %s, age: %d \n",
            cout << (string)cmd.Field(_TSA("Bid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Sid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Uid")).asString() << '\t';
            cout << "\t";
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Bidding_Price")).asString() << '\t';
            //cout << "\n";
            cout << "\t";
            cout << (string)cmd.Field(_TSA("Bid_Finalise")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Security_Fees")).asString();
            cout << "\n";
            // process result< set row by row as usual
        }
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
}

void CBid::addBid(const string& uid)
{
    CLibrary lib;
    CSql sql;
    ostringstream ost;

    cout << "\n--------Add Bids--------\n";
    int sid = lib.inputNewSid();
    if (sid == 0)
    {
        cout << "Exiting from Bid";
        return;
    }
    int fees = sql.fetchSecurityFees(sid);
    if (fees > 0)
    {
        cout << "This Sales require security fees Rs: " << fees;
        cout << "Do you want to continue? ";
        int yn = lib.yesNoMenu();
        if (yn == 2)
        {
            cout << "Exiting from Add Bid";
            return;
        }
    }
    int saleP = sql.fetchSalePrice(sid);
    cout << "Sale price : " << saleP;
    int price = lib.input_int("Enter the bid price Rs: ");
    if (price == 0)
    {
        cout << "Exiting from Add Bid";
        return;
    }
    if (fees > 0)
    {
        cout << "Security money is: " << fees;
        //int cardNum= lib.inputCardNum()
    }

    
}

void CBid::Bid_finalising()
{
	CSql sql;
	CLibrary lib;
	ostringstream ost;

	cout << "\n--------Finalise Bids--------";
	sql.bidFinalisingData();
	cout << "\n";
	int bid = lib.inputBid();
	if (bid == 0)
	{
		cout << "Exiting from Finalise Bid";
		return;
	}
	ost << "select count(*) from bidding where Bid_Finalise=0 and Bid=" << bid;
	string strqry = ost.str();
	bool isbidExist = sql.isRecordExist(strqry);
	if (isbidExist == false)
	{
		cout << "Invalid Bid Id";
		cout << "Exiting from finalise Bid";
		return;
	}
	cout << "Bid finalised successfully";
	ost << "update bidding set Bid_Finalise=1 where Bid=" << bid;
	string qry = ost.str();
	sql.updateData(qry, 0);

}



