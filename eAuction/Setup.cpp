#include <iostream>
#include "Setup.h"
#include <SQLAPI.h>
#include "Sql.h"
#include "Common.h"



CSetup::CSetup()
{
}

CSetup::~CSetup()
{
}
void CSetup::CreateTable()
{
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA("Select * from e_auction_user"));

        // this instructs the library to allocate a buffer for 100 rows
        // and, using respective native API, request data from server in pages of 100 rows
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {

            // printf("Name: %s, age: %d \n",
            cout << (string)cmd.Field(_TSA("Uid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Name")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("User_type")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Phone")).asString();
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Address")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Password")).asString();
            cout << "\n";
            // process result< set row by row as usual
        }
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
}

void CSetup::setup()
{
    string s = "SqlPackage.exe /Action:Publish /SourceFile:\"C:\\Anusha\\eAuction\\E_auction\\bin\\Debug\\E_auction.dacpac\" /TargetConnectionString:\"Data Source=DEV-STATION-01\\SQLEXPRESS;Database=e_auction;User ID=sa;Password=sa@1234;Connect Timeout=500\" /p:DropObjectsNotInSource=false /p:BlockOnPossibleDataLoss=false /DeployScriptPath:\".\\E_auctionDeployScript.txt\" /DeployReportPath:\".\\E_auctionDeployReport.xml\" ";
    system(s.c_str());
}

