// eAuction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Setup.h"
#include "E_Auction.h"
#include "overload.h"
#include "Library.h"
#include "IBase.h"
#include<stdio.h>
#include "Common.h"
#include "Setup.h"
#include "Test.h"
//#include "C:\SQLAPI\include\SQLAPI.h"
#include <SQLAPI.h>
using namespace std;




template<typename X, typename Y> 
void fun(X a, Y b)
{
    std::cout << "Value of a is : " << a;
    std::cout << "Value of b is : " << b;
}







int main()
{ 
    //fun("abc", 12.3);
    //return 0;
    
    // std::cout << "Hello World!\n";
    Open_Connection();
	//CSetup setup;
	//setup.CreateTable();
	CE_Auction auct;
	auct.Auction_menu();
	/*Coverload overl;
	overl.template1();*/
	/*Coverload2* over2=new Coverload2();
	Coverload* over1=over2;
	over1->fruit("Apple");
	over1->fruit(89);*/
	/*CApple* base=new CApple();
	base->person_name();
	base->type();
	delete base;
	*/
   
    //CSetup setup;
    //setup.CreateTable();
	//SAConnection con;

   

    //Test* P = TestFactory(eKoreaPrint);
    
    //P->MKPrint();

    //string s = "SqlPackage.exe /Action:Extract /TargetFile:Test3.dacpac /DiagnosticsFile:Test3.log /p:ExtractAllTableData=true /p:VerifyExtraction=true /SourceServerName:DEV-STATION-01\\SQLEXPRESS /SourceDatabaseName:Test2 /SourceUser:sa /SourcePassword:sa@1234";
    //system(s.c_str());
    
}

int main1()
{
    // create connection object to connect to database
    SAConnection con;
    con.setClient(SA_SQLServer_Client);
    try
    {
        // connect to database
        // in this example, it is Oracle,
        // but can also be Sybase, Informix, DB2
        // SQLServer, InterBase, SQLBase and ODBC
        con.Connect("DEV-STATION-01\\SQLEXPRESS@e_auction",    // database name
            "sa",  // user name
            "sa@1234"  // password
            ); //Oracle Client
        printf("We are connected!\n");

        // Disconnect is optional
        // autodisconnect will occur in destructor if needed
        con.Disconnect();
        printf("We are disconnected!\n");
    }

    catch (SAException& x)
    {
        // SAConnection::Rollback()
        // can also throw an exception
        // (if a network error for example),
        // we will be ready
        try
        {
            // on error rollback changes
            con.Rollback();
        }
        catch (SAException&)
        {
        }
        // print error message
        printf("%s\n", (const char*)x.ErrText());
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
