#include <iostream>
#include "Items.h"
#include "Library.h"
#include <SQLAPI.h>
#include <sstream>
#include "Common.h"



CItems::CItems()
{
}

CItems::~CItems()
{
}

void CItems::add_item()
{
    CLibrary lib;
    CSql sql;

	cout << "\n--------Add Items--------\n";
	string pid;
	pid = lib.Input_new_pid();
	string name;
	name = lib.Input_text("Enter product name: ", 20);
	int qty;
	qty = lib.input_int("Enter the quantity: ");
	string comp_name;
	comp_name = lib.Input_text("Enter the company name: ", 20);
	string date;
	date = lib.Input_date("Enter the manufacturing date(YYYY/MM/DD): ");
    ostringstream ost;
    ost << "insert into product(Pid,Name, Qty, Company_Name, Mfg_Date)";
    ost << "values('" << pid << "', '" << name << "', '" << qty<< "', '" << comp_name << "', '" << date << "')";
    string strqry = ost.str();
    
    sql.insertData(strqry);
}
void CItems::displayItems()
{
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA("Select * from product"));

        // this instructs the library to allocate a buffer for 100 rows
        // and, using respective native API, request data from server in pages of 100 rows
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        cout << "-----------------------------Items List------------------------------\n";
        cout << "Pid\tName\tQty\tCompany Name\tMfg Date\n";
        cout << "---------------------------------------------------------------------\n";
        while (cmd.FetchNext())
        {
            // printf("Name: %s, age: %d \n",
            cout << (string)cmd.Field(_TSA("Pid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Name")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Qty")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Company_Name")).asString()<<'\t';
            //cout << "\n";
            cout << "\t";
            cout << (string)cmd.Field(_TSA("Mfg_Date")).asString();
            cout << "\n";
            // process result< set row by row as usual
        }
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
}

void CItems::editItems()
{
    CLibrary lib;
    CSql sql;

    cout << "\n--------Edit Items--------\n";
    string pid = lib.Input_Product();
    if (pid == "")
    {
        cout << "Exiting from edit item";
    }
    string oldQty = sql.getOldQty(pid);
    cout << "Old quantity is: " << oldQty;
    int nQty = lib.input_int("\nEnter new quantity to update: ");
    ostringstream ost;
    ost << "update product set Qty="<< nQty << " where Pid='" << pid << "'";
    string strqry = ost.str();
    sql.updateData(strqry);
    cout << "";
    displayItems();
    cout << "Updated product id " << pid << " successfully.";
    cout << "";
}

void CItems::deleteItems()
{
    CLibrary lib;
    CSql sql;

    cout << "\n--------Delete Items--------";
    string pid = lib.Input_Product();
    if (pid == "")
    {
        cout << "Exiting from edit item";
    }
    ostringstream ost;
    ost << "delete from product where Pid='" << pid << "'";
    string strqry = ost.str();
    sql.deleteData(strqry);
    cout << "";
    displayItems();
    cout << "Deleted product id " << pid << " successfully.";
    cout << "\n";
}
