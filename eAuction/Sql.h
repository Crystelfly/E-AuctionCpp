#pragma once
using namespace std;
#include<iostream>
#include <SQLAPI.h>

class CSql
{
public:
    CSql();
    virtual ~CSql();
public:
    void Open_Connection();
    void DisConnection();
    string Select_data(const string& sql);
    int RegCheckUserExist(const string& uid);
    int Is_pid_exist(string pid);
    int isSellExist(const string& sid);
    int isBidExist(const string& sid);
    bool isRecordExist(const string& sql);
    int insertData(const string& sql, int msg=0);
    int updateData(const string& sql, int dp = 1);
    int deleteData(const string& sql, int dp = 1);
    int LogCheckUserExist(const string& uid);
    string getUserName(string uid);
    string getProductIds();
    string getSellIds();
    string getBidIds();
    string getOldQty(string pid);
    string getOldPrice(int sid);
    string getOldSecPrice(int sid);
    int fetchSecurityFees(int sid);
    int fetchSalePrice(int sid);
    void bidFinalisingData();
    int isUserProductExist(const string& qry);
    SAConnection& GetConn();

protected:

private:
    SAConnection m_con;
};




