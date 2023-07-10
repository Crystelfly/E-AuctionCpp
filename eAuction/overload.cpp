#include "overload.h"
Coverload::Coverload()
{
}
Coverload::~Coverload()
{
}
void Coverload::fruit(string name)
{
	cout << "Fruit name: "<<name;
}
void Coverload::fruit(int price)
{
	cout << "Fruit name: " << price ;
}

template <typename T,typename t2> 
int myMax(T x, t2 y)
{
	return (x > y) ? x : y;
}
void Coverload::template1()
{
		// Call myMax for int
		cout << myMax<int>(3, 7) << endl;
		// call myMax for double
		cout << myMax<double>(3.0, 7.0) << endl;
		// call myMax for char
		cout << myMax<char>('g', 'e') << endl;

		
}

/////////////////////////////////////
Coverload2::Coverload2()
{
}
Coverload2::~Coverload2()
{
}
void Coverload2::fruit(string name)
{
	cout << "Fruit name2: " << name;
}
void Coverload2::fruit(int price)
{
	cout << "Fruit name2: " << price;
}


