#include "Library.h"
#include "Sql.h"
#include <regex>
#include <iostream>
#include <iomanip>
#include <sstream>
#include <chrono>
#include <ctime>


CSql conn;

CLibrary::CLibrary()
{
}

CLibrary::~CLibrary()
{
}



string CLibrary::Input_user()
{
    while (1)
    {
        string uid;
        cout << "Enter the user id: ";
        cin >> uid;
        if ((conn.LogCheckUserExist(uid)) == 1)
        {
            return uid;  
        }
        else
        {
            cout<<"Invalid User Id.";
        }
    }
}

string CLibrary::Getpass()
{
    string pass;
   // try
   // {
        char c = 0;
        while (1)
        {
            while (c != '\n')
            {
                //cin >> num;

               // cout << msg;
                c = getchar();
                if (c == '\n')
                    continue;
                pass = pass + c;

            }
            if (pass.length() > 0)
                return pass;
            else
                c = 0;
        }
    //}
}

int input_int0(const string& msg)
{
   
   // cout << msg;
    char c=0;

    while (1)
    {
        //cin >> num;

            cout << msg;
            int c1=getchar();
            if (c1 == 10)
                return c;
            else
                c = c1;

        if (c >= 49 && c <= 57)
            return c;
        else
            c = getchar();
    }
   // return 1;
    //while (1)
    //{
    //    string num
    //}
}

int CLibrary::input_int(const string& msg)
{

    // cout << msg;
    char c = 0;
    string s;
    cout << msg;
    while (1)
    {
        //cin >> num;

        int c = getchar();
        if (c == 10 && s.length()>0)
            break;

        if (c == 10)
            continue;


        if (c >= 49 && c <= 57)
            s += c;
        else
        {
            
            while (c != 10)
            {
                c = getchar();
            }
            return 0;
        }
            
    }

    int i = atoi(s.c_str());
    return i;
}
string CLibrary::Is_buyer_seller()
{
    while (1)
    {
        string utype;
        utype = Input_text("Enter whether you are a buyer or a seller (B/S): ", 1);
        if (utype == "B" || utype == "b" || utype == "S" || utype == "s")
        {
            return utype;
        }
        else
        {
            cout << "invalid Input. Enter again.";
        }
    }
}

bool CLibrary::Number_validation(string numb)
{
    regex reg("^[0-9]{10}$");
    if (regex_match(numb, reg))
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

string CLibrary::Number_input()
{
    string msg = "Enter the phone number: ";
    while (1)
    {
        string numb;
        cout << msg;
        cin >> numb;
        if (Number_validation(numb) == true)
        {
            return numb;
        }
        else
        {
            msg = "Invalid phone number. Enter again: ";
        }
    }
  
}

string CLibrary::Input_new_pid()
{
    while (1)
    {
        string pid;
        pid = Input_text("Enter the product id: ", 20);
        if (conn.Is_pid_exist(pid) == 1)
        {
            cout << "Given product id already exist.Existing Product Ids are : ";
        }
        else
        {
            return pid;
        }
    }
}


string CLibrary::Input_date(string msg)
{
    if (msg == "")
    {
        msg = "Enter the date(YYYY-MM-DD): ";
    }
    while (1)
    {
        string date;
        cout << msg;
        cin >> date;
        if (date == "")
        {
            return "";
        }
        else if (Date_validation(date)==true)
        {
            return date;
            break;
        }
    }
    return "";
}

bool CLibrary::Date_validation(string date_string)
{

    time_t time1;
   // time1= time(date_string);

    std::string date_time_format = "%Y/%m/%d";
    std::istringstream ss{ date_string };
    std::tm dt;

    ss >> std::get_time(&dt, date_time_format.c_str());

    std::time_t final_time;

    int y = 1900 + dt.tm_year ;
    int m = 1 + dt.tm_mon ;
    int d = dt.tm_mday;

    if (!(1582 <= y))//comment these 2 lines out if it bothers you
        return false;
    if (!(1 <= m && m <= 12))
        return false;
    if (!(1 <= d && d <= 31))
        return false;
    if ((d == 31) && (m == 2 || m == 4 || m == 6 || m == 9 || m == 11))
        return false;
    if ((d == 30) && (m == 2))
        return false;
    if ((m == 2) && (d == 29) && (y % 4 != 0))
        return false;
    if ((m == 2) && (d == 29) && (y % 400 == 0))
        return true;
    if ((m == 2) && (d == 29) && (y % 100 == 0))
        return false;
    if ((m == 2) && (d == 29) && (y % 4 == 0))
        return true;

    return true;
}

string CLibrary::Input_Product()
{
    while (1)
    {
        string pid = Input_text("\n\nEnter the Pid id: ", 20);
        if (pid == "")
        { 
            return "";
        }
        else if (conn.Is_pid_exist(pid) > 0)
        {
            return pid;
        }
        else
        {
            cout << "Invalid Pid id. Existing Product ids are: " << conn.getProductIds();
        }
    }
}

int CLibrary::inputSid()
{
    
    while (1)
    {
        int sid = input_int("Enter the sell id: ");
        if (sid == 0)
        {
            return 0;
        }
        ostringstream ost;
        ost << "select count(*) from seller where Sid=" << sid;
        string qry = ost.str();
        if (conn.isSellExist(qry) > 0)
        {
            return sid;
        }
        else
        {
            cout << "Invalid Sell id. Existing Sell Ids are: " << conn.getSellIds();
        }
    }
}

int CLibrary::inputBid()
{
    while (1)
    {
        int bid = input_int("Enter the Bid id: ");
        if (bid == 0)
        {
            return 0;
        }
        ostringstream ost;
        ost << "select count(*) from Bidding where Bid=" << bid;
        string qry = ost.str();
        if (conn.isBidExist(qry) > 0)
        {
            return bid;
        }
        else
        {
            cout << "Invalid Bid id. Existing Bid Ids are: " << conn.getBidIds();
        }
    }
}

int CLibrary::yesNoMenu()
{
    cout << "\n1.Yes\n2.No\n";
    while (1)
    {
        cout << "Enter your choice: ";
        int ch;
        cin >> ch;
        if (ch == 1)
            return 1;
        else if (ch == 2)
            return 2;
    }

    return 0;
}

string CLibrary::Input_text(string msg, int maxlength)
{
    while (1)
    {
        string name;
        cout << msg;
        cout << ": ";
        cin >> name;
        if (name == "")
        {
            return "";
        }
        else if (name.length() > maxlength)
        {
            cout << "Input data length is " << name.length() << ". It's length cannot more than " << maxlength;
        }
        else
        {
            return name;
        }
    }
}

string CLibrary::inputCardNum()
{
    cout << "Valid card number format xxxx-xxxx-xxxx-xxxx.";
    cout << "The first character must be either 4,5 or 6. Ex. 4xxx-xxxx-xxxx-xxxx.";
    string msg = "Enter the card number to pay: ";
    /*while (1)
    {

    }
    */
    return "";
}

string CLibrary::Input_new_user()
{
    string uid;
    CSql sql;
    while (1)
    {
        
        uid = Input_text("Enter your User Id: ", 20);
        if (uid == "")
        {
            return "";
        }
        if (uid == "NUL")
        {
            cout << "Invalid user id.";
        }
        else if (sql.RegCheckUserExist(uid) == 0)
        {
            break;
            
        }
    }
    return uid;
}

int CLibrary::inputNewSid()
{
    CSql sql;

    while (1)
    {
        int sid = input_int("Enter the sell id: ");
        if (sid == 0)
        {
            return sid;
        }
        ostringstream ost;
        ost << "select count(*) from seller where Sid=" << sid;
        string strqry = ost.str();
        if (conn.isSellExist(strqry) > 0)
        {
            cout << "Given sell id already exist. Existing Sell Ids are: " << sql.getSellIds();
        }
        else
        {
            return sid;
        }
    }    
}

int CLibrary::securityFee(int offer, const string& msg)
{
    while (1)
    {
        int fee = input_int(msg);
        if (fee == 0)
        {
            return 0;
        }
        else if (fee >= offer)
        {
            cout << "Security fees cannot be greater than or equal to the offer price [" << offer << "]. Enter again: ";
        }
        else
        {
            return fee;
        }
    }
}
