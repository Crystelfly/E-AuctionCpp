#include <iostream>
#include "Register.h"
#include "Library.h"
#include "Sql.h"

using namespace std;

CRegister::CRegister()
{
}

CRegister::~CRegister()
{
}
void CRegister::Register()
{
    CLibrary lib;
    CSql sql;

    try
    {
        cout << "\n--------Register New User--------\n";
        string uid;
        uid=lib.Input_new_user();
        string name;
        name = lib.Input_text("Enter your name: ", 25);
        string password;
        cout << "Enter password: ";
        password = lib.Getpass();
        string type1;
        type1 = lib.Is_buyer_seller();
        string phone;
        phone = lib.Number_input();
        string add;
        add = lib.Input_text("Enter your address: ", 30);
        string query = "insert into e_auction_user (Uid, Name, User_type, phone, address, Password) values \
                    ('" + uid + "','" + name + "','" + type1 + "','" + phone + "','" + add + "','" + password + "')";
        sql.insertData(query);

    }
    catch (...)
    {
        cout << "Register unsuccessful\n";
    }
}

string CRegister::Login()
{
    CLibrary lib;
    CSql sql;

    int count = 0;
    string uid;

    try
    {
        cout << "\n--------Login User--------\n";
       
        uid = lib.Input_user();
        string password;
        cout << "Enter password: ";
        password = lib.Getpass();
        bool returnBool = sql.isRecordExist("select count(*) from e_auction_user where Uid='" + uid + "' and Password='" + password + "'");
        if (returnBool == false)
        {
            cout << "Invalid User id or password\n";
            return "";
        }

        else
        {
            cout << "Login successful\n";
            return uid;
        }
    }
    catch (...)
    {
        cout << "Login Error";
        count = 0;
    }

    return "";
}


