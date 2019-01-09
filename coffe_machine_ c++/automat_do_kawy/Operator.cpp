#pragma once
#include "Operator.h"

inline void operator +=(vector<double>&a, double b)
{
	a.push_back(b);
}



COperator::COperator(CMachine *automata)
{
	automat = automata;
}


COperator::~COperator()
{
	
}

void COperator::fillCoins()
{
	
	for (int i = 0; i < 100; i++)
	{
		automat->coins += 1;
		automat->coins += 2;
		automat->coins += 0.5;
		automat->coins += 0.2;
		automat->coins += 0.01;
		automat->coins += 0.05;
		automat->coins += 5;
		
	}
}
void COperator::fillCups()
{
	for (int i = 0; i < 100; i++)
	{
		automat->cups.push(1);
	}
	
}
void COperator::fillTanks()
{
	automat->coffeTank->volume = 100;
	automat->waterTank->volume = 100;

}
void COperator::takeCoins()
{
	fillCoins();
	cash.swap(automat->coins);
}
