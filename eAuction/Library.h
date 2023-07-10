#pragma once
#include<iostream>

using namespace std;

class CLibrary
{
public:
    CLibrary();
    virtual ~CLibrary();
public:
    
    string Input_user();
    string Getpass();
    string Input_text(string msg, int maxlength);
    string Input_new_user();
    int input_int(const string& msg);
    string Is_buyer_seller();
    bool Number_validation(string numb);
    string Number_input();
    string Input_new_pid();
    int inputNewSid();
    string Input_date(string msg="");
    bool Date_validation(string date_string);
    string Input_Product();
    int inputSid();
    int inputBid();
    string inputCardNum();
    int yesNoMenu();
    int securityFee(int offer, const string& msg);
protected:

private:
};


