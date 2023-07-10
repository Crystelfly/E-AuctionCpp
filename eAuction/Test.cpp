#include "Test.h"

Test::Test()
{
}

Test::~Test()
{
}

void Test::MKPrint()
{
	cout << "I am Gandhi";
}

IndiaPrint::IndiaPrint()
{
}

IndiaPrint::~IndiaPrint()
{
}

void IndiaPrint::MKPrint()
{
	cout << "Mai Gandhi hu";
}

cChinaPrint::cChinaPrint()
{
}

cChinaPrint::~cChinaPrint()
{
}

void cChinaPrint::MKPrint()
{
	cout << "I am CHINESE Gandhi";
}

cKoreaPrint::cKoreaPrint()
{
}

cKoreaPrint::~cKoreaPrint()
{
}

void cKoreaPrint::MKPrint()
{
	cout << "I am KOREAN Gandhi";
}

Test* TestFactory(eTest nClassType)
{
	switch (nClassType)
	{
	case eIndiaPrint:
		return new IndiaPrint;
	case eChinaPrint:
		return new cChinaPrint;
	case eKoreaPrint:
		return new cKoreaPrint;
	default:
		return new IndiaPrint;
	}
}
