#include "Sub_Menu.h"
#include "Library.h" 
#include "Sql.h"
#include "Items.h"
#include "Sales.h"
#include "Bid.h"

CSql sql;
CLibrary lib;
CItems item;
CSales sale;
CBid bid;

CSub_Menu::CSub_Menu()
{
}

CSub_Menu::~CSub_Menu()
{
}

void CSub_Menu::auctionItemMenu()
{
	while (1)
	{
		try
		{
			cout << "\n--------Item Menu--------";
			cout << "\n1)Display Items\n2)Add Item\n3)Edit Item\n4)Delete Item\n5)Exit\n";
			int ch = lib.input_int("Enter your choice no.: ");
			if (ch == 1)
			{
				item.displayItems();
				continue;
			}
			else if (ch == 2)
			{
				item.add_item();
				continue;
			}
			else if (ch == 3)
			{
				item.editItems();
				continue;
			}
			else if (ch == 4)
			{
				item.deleteItems();
				continue;
			}
			else if (ch == 5)
			{
				cout<<"Exiting from Item Menu.\n";
				break;
			}
			else
			{
				cout << "Wrong input. Ener again.";
			}

		}
		catch (...)
		{

		}
	}
}

void CSub_Menu::auctionSaleMenu(const string& uid)
{
	while (1)
	{
		try
		{
			cout << "\n--------Sales Menu--------\n";
			cout << "\n1)Display Sales\n2)Add Sales\n3)Edit Sales\n4)Delete Sales\n5)Finalise bids\n6)Confirm Payment\n7)Exit\n";
			int ch = lib.input_int("\nEnter your choice no.: ");
			if (ch == 1)
			{
				sale.displaySales();
				continue;
			}
			else if (ch == 2)
			{
				sale.addSales(uid);
				continue;
			}
			else if (ch == 3)
			{
				sale.updateSales();
				continue;
			}
			else if (ch == 4)
			{
				sale.deleteSales();
				continue;
			}
			else if (ch == 5)
			{
				sale.finaliseBid();
				continue;
			}
			else if (ch == 7)
			{
				cout << "Exiting from Sale Menu.\n";
				break;
			}
			else
			{
				cout << "Wrong input. Ener again.";
			}

		}
		catch (...)
		{

		}
	}
}

void CSub_Menu::auctionBidMenu(const string& uid)
{
	while (1)
	{
		try
		{
			cout << "\n--------Bid Menu--------";
			cout << "\n1)Display Bids\n2)Add Bid\n3)Edit Bid\n4)Delete Bid\n5)Payment\n6)Processed Bids\n7)Exit";
			int ch = lib.input_int("\nEnter your choice no.: ");
			if (ch == 1)
			{
				bid.displayBid();
				continue;
			}
			else if (ch == 2)
			{
				//bid.addSales(uid);
				continue;
			}
			else if (ch == 3)
			{
				//bid.updateSales();
				continue;
			}
			else if (ch == 4)
			{
				//bid.deleteSales();
				continue;
			}
			else if (ch == 5)
			{
				//bid.finaliseBid();
				continue;
			}
			else if (ch == 7)
			{
				cout << "Exiting from Sale Menu.\n";
				break;
			}
			else
			{
				cout << "Wrong input. Ener again.";
			}

		}
		catch (...)
		{

		}
	}
}

void CSub_Menu::auctionSubMenu(string uid)
{
	string uname = sql.getUserName(uid);
	cout << "\nWelcome ["<<uname<<"]\n";
	while (1)
	{
		try
		{
			CLibrary lib;
			cout << "\n--------Main Menu--------";
			cout << "\n1)Items\n2)Sales\n3)Bid\n4)Log Out\n";
			int op;
			string msg = "Enter your choice no.: ";
			op = lib.input_int(msg);
			if (op == 1)
			{
				auctionItemMenu();
			}
			else if (op == 2)
			{
				auctionSaleMenu(uid);
			}
			else if (op == 3)
			{
				auctionBidMenu(uid);
			}
			else if (op == 4)
			{
				cout << "Do you want to exit from E-Auction?";
				int ch = lib.yesNoMenu();
				if (ch == 1)
				{
					break;
				}
				else
				{
					cout << "Wrong Input";
				}
			}
			else
			{
				cout << "Invalid Input";
			}
		}
		catch (...)
		{
			cout << "Unknown Error";
		}
	}
}
