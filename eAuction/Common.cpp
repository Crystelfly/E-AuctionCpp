#include "Common.h"
CSql gConnection;
SAConnection& gGetCon()
{
	return gConnection.GetConn();
}
void Open_Connection()
{
	gConnection.Open_Connection();
}
void DisConnection()
{
	gConnection.DisConnection();
}