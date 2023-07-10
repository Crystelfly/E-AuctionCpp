#include "E_Auction.h"
#include "Library.h"
#include "Register.h"
#include <iostream>
#include "Sub_Menu.h"
CE_Auction::CE_Auction()
{
}
CE_Auction::~CE_Auction()
{
}
void CE_Auction::Auction_menu()
{
	
	CLibrary lib;
	CRegister reg;
	CSub_Menu subm;
	while (1)
	{
		try
		{
			cout << "\n1)Register\n2)Log In\n3)Help\n4)Exit\n";
            int alt;
			string msg = "Enter your choice no.: ";
			alt = lib.input_int(msg);
			if (alt == 1)
			{
				reg.Register();
			}
			else if (alt == 2)
			{
				string uid=reg.Login();
				if (uid.length() == 0)
				{
					continue;
				}
				else
				{
					subm.auctionSubMenu(uid);
				}
			}
			else if (alt == 4)
			{
				if (lib.yesNoMenu() == 1)
				{
					break;
				}
			}

			else
			{
				cout << "not working fine";
				cout << "\n";
			}
		}
		catch (...)
		{

		}
	}
}