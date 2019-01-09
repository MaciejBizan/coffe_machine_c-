#pragma once
#include "Human.h"


inline void operator +=(vector<double>&a, double b)
{
	a.push_back(b);
}



CHuman::CHuman()
{
	for (int i = 0; i < 2; i++)
	{
		cash += 1;
		cash += 2;
		cash += 0.5;
		cash += 0.2;
		cash += 0.1;
		cash += 0.05;
		
		
	}
}


CHuman::~CHuman()
{
}
void CHuman::showCash()const
{
	int one = 0, two = 0, five = 0, half = 0, otwenty = 0, oten = 0, ofive = 0;
	for (int i = 0; i < cash.size(); i++)
	{

		if (cash[i] == 0.05)
			ofive++;
		if (cash[i] == 0.1)
			oten++;
		if (cash[i] == 0.2)
			otwenty++;
		if (cash[i] == 0.5)
			half++;
		if (cash[i] == 1)
			one++;
		if (cash[i] == 2)
			two++;
		if (cash[i] == 5)
			five++;
	}
	cout << "\nYour credit:" << endl;
	cout << "0.05:" << ofive << endl;
	cout << "0.1: " << oten << endl;
	cout << "0.2: " << otwenty << endl;
	cout << "0.5: " << half << endl;
	cout << "1: " << one << endl;
	cout << "2: " << two << endl;
	cout << "5: " << five << endl<<endl;
}
double const CHuman::getCash()const
{
	int i = 0;
	double sum = 0;
	while (i < cash.size())
	{
		sum += cash[i];
	}
	return sum;
}

