#include "Sql.h"
#include <SQLAPI.h>
#include "Common.h"
#include <string>
#include <sstream>


CSql::CSql()
{
}

CSql::~CSql()
{
   // m_con.Disconnect();
}

void CSql::Open_Connection()
{
    // create connection object to connect to database
    
    m_con.setClient(SA_SQLServer_Client);
    try
    {
        // connect to database
        // in this example, it is Oracle,
        // but can also be Sybase, Informix, DB2
        // SQLServer, InterBase, SQLBase and ODBC
        m_con.Connect("DEV-STATION-01\\SQLEXPRESS@e_auction",    // database name
            "sa",  // user name
            "sa@1234"  // password
        ); //Oracle Client
        printf("We are connected!\n");

        // Disconnect is optional
        // autodisconnect will occur in destructor if needed
        //con.Disconnect();
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
            m_con.Rollback();
        }
        catch (SAException&)
        {
        }
        // print error message
        printf("%s\n", (const char*)x.ErrText());
    }
    
}

void CSql::DisConnection()
{
    m_con.Disconnect();
}

/*string CSql::Select_data(const string& sql)
{
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(sql.c_str()));

        // this instructs the library to allocate a buffer for 100 rows
        // and, using respective native API, request data from server in pages of 100 rows
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {

            cmd[1].asString();
        }
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
}*/

bool CSql::isRecordExist(const string& sql)
{
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(sql.c_str()));

        // this instructs the library to allocate a buffer for 100 rows
        // and, using respective native API, request data from server in pages of 100 rows
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {

            int count =cmd[1].asLong();
            if (count == 0)
            {
                return false;
            }
               
            else
                return true;
        }
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return false;
}

int CSql::RegCheckUserExist(const string& uid)
{
    bool existance = isRecordExist("select count(*) from e_auction_user where uid='" + uid + "'");
    if (existance == true)
    {
        cout << "User already exist. Try another user name";
        return 1;
    }
    return 0;
}

int CSql::Is_pid_exist(string pid)
{
    bool existance = isRecordExist("select count(*) from product where Pid='" + pid + "'");
    if (existance == true)
    {
        return 1;
    }
    return 0;
}

int CSql::isSellExist(const string& query)
{
    bool existance = isRecordExist(query);
    if (existance == true)
    {
        return 1;
    }
    return 0;
}

int CSql::isBidExist(const string& query)
{
    bool existance = isRecordExist(query);
    if (existance == true)
    {
        return 1;
    }
    return 0;
}

SAConnection& CSql::GetConn()
{
    return m_con;
}


int CSql::LogCheckUserExist(const string& uid)
{
    bool existance = isRecordExist("select count(*) from e_auction_user where uid='" + uid + "'");
    if (existance == true)
    {
        return 1;
    }
    return 0;
}

int CSql::updateData(const string& sql, int dp)
{
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(sql.c_str()));
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        if (dp == 1)
        {
            cout << "Record updated successfully.\n";
        }
        return 1;
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return 0;
}


string CSql::getUserName(string uid)
{
    string name = "select name from e_auction_user where uid='" + uid + "'";
    //cout << name;
    //return name;
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(name.c_str()));

        // this instructs the library to allocate a buffer for 100 rows
        // and, using respective native API, request data from server in pages of 100 rows
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {
           
            return (string)cmd[1].asString();
            //cmd[1].asString();
        }
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return "";
}

int CSql::deleteData(const string& sql, int dp)
{
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(sql.c_str()));
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        if (dp == 1)
        {
            cout << "Record deleted successfully.\n";
        }
        return 1;
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return 0;
}

string CSql::getProductIds()
{
    //string name = "select Pid from product ";
    //cout << name;
    //return name;
   
    try
    {
        string pids;
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA("select Pid from product "));
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";
       
        cmd.Execute();
        while (cmd.FetchNext())
        {
            pids += (string)cmd.Field(_TSA("Pid")).asString();
            pids += ",";
            
            //return (string)cmd[2].asString();
            //cmd[1].asString();
        }
        int len = (pids.length()-1);
        string str = pids;
        pids=str.replace(len, 1, "");
        return pids;
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return "";
}

string CSql::getSellIds()
{
    try
    {
        string sids;
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA("select Sid from seller "));
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {
            sids += (string)cmd.Field(_TSA("Sid")).asString();
            sids += ",";

            //return (string)cmd[2].asString();
            //cmd[1].asString();
        }
        int len = (sids.length() - 1);
        string str = sids;
        sids = str.replace(len, 1, "");
        return sids;
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return "";
}

string CSql::getBidIds()
{
    try
    {
        string bids;
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA("select Bid from Bidding "));
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {
            bids += (string)cmd.Field(_TSA("Bid")).asString();
            bids += ",";

            //return (string)cmd[2].asString();
            //cmd[1].asString();
        }
        int len = (bids.length() - 1);
        string str = bids;
        bids = str.replace(len, 1, "");
        return bids;
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return "";
}


int CSql::isUserProductExist(const string& qry)
{
    bool existance = isRecordExist(qry);
    if (existance == true)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

string CSql::getOldQty(string pid)
{
    try
    {
        string query = "Select Qty from product where Pid='" + pid + "'";
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(query.c_str()));
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {
            return (string)cmd[1].asString();
        }
        
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return 0;
}

string CSql::getOldPrice(int sid)
{
    try
    {
        ostringstream ost;
        ost << "select Offer_Price from seller where Sid='" << sid << "'";
        string strqry = ost.str();
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(strqry.c_str()));
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {
            return (string)cmd[1].asString();
        }
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return 0;
}

string CSql::getOldSecPrice(int sid)
{
    try
    {
        ostringstream ost;
        ost << "select Security_Fees from seller where Sid='" << sid << "'";
        string strqry = ost.str();
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(strqry.c_str()));
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {
            return (string)cmd[1].asString();
        }
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return 0;
}

int CSql::fetchSecurityFees(int sid)
{
    try
    {
        string fee;
        ostringstream ost;
        ost << "select Security_Fees from seller where Sid='" << sid << "'";
        string strqry = ost.str();
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(strqry.c_str()));
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {
            string fee= (string)cmd[1].asString();
        }
        int i = atoi(fee.c_str());
        return i;
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return 0;

}

int CSql::fetchSalePrice(int sid)
{
    try
    {
        string fee;
        ostringstream ost;
        ost << "select offer_price from seller where Sid=" << sid;
        string strqry = ost.str();
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(strqry.c_str()));
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        while (cmd.FetchNext())
        {
            string fee = (string)cmd[1].asString();
        }
        int i = atoi(fee.c_str());
        return i;
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return 0;
}

int CSql::insertData(const string& sql, int msg )
{
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA(sql.c_str()));

        // this instructs the library to allocate a buffer for 100 rows
        // and, using respective native API, request data from server in pages of 100 rows
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        if (msg== 0)
        {
            cout << "Record inserted successfully.\n";
        }
        return 1;
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
    return 0;
}

void CSql::bidFinalisingData()
{
    try
    {
        SACommand cmd(&gGetCon());
        cmd.setCommandText(_TSA("select seller.Sid, bidding.Uid, Pid, Bid, Expiry_Date, Offer_Price, Bidding_Price, Bid_Finalise\
            from seller, bidding \
        where seller.sid = bidding.sid \
            and bidding.Bid_Finalise = 0"));

        // this instructs the library to allocate a buffer for 100 rows
        // and, using respective native API, request data from server in pages of 100 rows
        cmd.setOption(SACMD_PREFETCH_ROWS) = "100";

        cmd.Execute();
        cout << "\n------------------------------------------------------------------------------------------";
        cout << "\nSeller id\tUser id\tProduct id\tid id\tExpiry Date\tOffer Price\tBidding Price\tBid Finalise";
        cout << "\n-------------------------------------------------------------------------------------------";
        while (cmd.FetchNext())
        {
            // printf("Name: %s, age: %d \n",
            cout << "\n";
            cout << (string)cmd.Field(_TSA("Sid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Uid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Pid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Bid")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Expiry_Date")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Offer_Price")).asString() << '\t';
            //cout << "\n";
            cout << (string)cmd.Field(_TSA("Bidding_Price")).asString() << '\t';
            cout << (string)cmd.Field(_TSA("Bid_Finalise")).asString();
            cout << "\n";
            

            // process result< set row by row as usual
        }
        cout << "---------------------------------------------------------------------------------------";
    }
    catch (SAException e)
    {
        cout << (string)e.ErrText();
    }
}

