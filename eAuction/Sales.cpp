#include "Sales.h"
#include "Library.h"
#include <SQLAPI.h>
#include <sstream>
#include "Common.h"
#include <iostream>
#include "Bid.h"

CSales::CSales()
{
}

CSales::~CSales()
{
}

void CSales::displaySales()
{
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA("Select * from seller"));

        // this instructs the library to allocate a buffer for 100 rows
        // and, using respective native API, request data from server in pages of 100 rows
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        cout << "-----------------------------Sales List------------------------------\n";
        cout << "Sid\tUid\tPid\tOffer Price \tExpiry Date \tSecurity_Fees\n";
        cout << "---------------------------------------------------------------------\n";
        while (cmd.FetchNext())
        {
            // printf("Name: %s, age: %d \n",
            cout << (string)cmd.Field(_TSA("Sid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Uid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Pid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Offer_Price")).asString() << '\t';
            //cout << "\n";
            cout << "\t";
            cout << (string)cmd.Field(_TSA("Expiry_Date")).asString() << '\t';
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

void CSales::addSales(const string& uid)
{
    CLibrary lib;
    CSql sql;
    ostringstream ost;

    cout << "\n--------Add Sales--------\n";
    int sid = lib.inputNewSid();
    if (sid == 0)
    {
        cout << "Exiting from add sales";
        return;
    }
    string pid = lib.Input_Product();

    ost << "select count(*) from seller where Uid='" << uid << "' and Pid='" << pid << "'";
    string strqry = ost.str();

    if (pid == "")
    {
        cout << "Exiting from add sales";
        return;
    }
    else if(sql.isUserProductExist(strqry)==1)
    {
        cout << "User id ", uid, " for the Product id ", pid, " already exist.";
        return;
    }
    int offer = lib.input_int("Enter the offer price Rs: ");
    if (offer == 0)
    {
        cout << "Existing from sales";
        return;
    }
    string date;
    date = lib.Input_date("Enter the expiry date(YYYY/MM/DD): ");
    if (date == "")
    {
        cout<< "Existing from sales";
        return;
    }
    int fee = lib.securityFee(offer, "Enter the security fees: ");
    if (fee == 0)
    {
        cout << "Exiting from add sales";
        return;
    }
    ost << "insert into seller values ('" << sid << "','" << uid << "','" << pid << "','" << offer << "','" << date << "'," << fee << ")";
    string qry = ost.str();
    sql.insertData(qry);
}

void CSales::updateSales()
{
    CSql sql;
    CLibrary lib;
    ostringstream ost;

    cout << "\n--------Update Sales--------";
    cout << "\n";
    cout << "Existing sell ids are: " << sql.getSellIds();
    cout << "\n";
    int sid = lib.inputSid();
    if (sid == 0)
    {
        cout << "Exiting from update sales";
        return;
    }
    string oldPrice = sql.getOldPrice(sid);
    string oldSecPrice = sql.getOldSecPrice(sid);
    cout << "Old Offer price is Rs: " << oldPrice;
    cout << "\n";
    cout << "Old Security fee is Rs: " << oldSecPrice<<"\n";
    int newRec = lib.input_int("Enter the new Offer Price: ");
    if (newRec==0)
    {
        cout << "Exiting from update sales";
        return;      
    }
    int NewSecPrice = lib.securityFee(newRec, "Enter the new security fees: ");
    if (NewSecPrice == 0)
    {
        cout << "Exiting from update sales";
        return;
    }
    ost << "select count(*) from seller where Sid=" << sid;
    string strqry = ost.str();
    if (sql.isSellExist(strqry) == 0)
    {
        cout << "Record does not exist";
    }
    else
    {
        ost << "update seller set Offer_Price=" << newRec << ", Security_Fees=" << NewSecPrice << " where Sid='" << sid << "'";
        string qry = ost.str();
        sql.updateData(qry);
        cout << "";
        displaySales();
        cout << "Updated sell id " << sid << " successfully.";
    }
}

void CSales::deleteSales()
{
    CSql sql;
    CLibrary lib;
    ostringstream ost;

    cout << "\n--------Delete Sales--------";
    cout << "\n";
    cout << "Existing sell ids are: " << sql.getSellIds();
    cout << "\n";
    int sid = lib.inputSid();
    ost << "select count(*) from seller where Sid=" << sid;
    string strqry = ost.str();
    if (sid == 0)
    {
        cout << "Exiting from update sales";
        return;
    }
    else if (sql.isSellExist(strqry) == 0)
    {
        cout << "Record does not exist";
    }
    else
    {
        ost << "delete from seller where Sid='" << sid << "'";
        string strqry = ost.str();
        sql.deleteData(strqry);
        cout << "";
        displaySales();
        cout << "Deleted sell id " << sid << " successfully.";
    }
}

void CSales::finaliseBid()
{
    CBid bid;
    bid.Bid_finalising();
}
