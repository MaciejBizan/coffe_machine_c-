#pragma once
#include <stdio.h>
#include<iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>
#include <fstream>
#include <math.h>

#include "Human.h"
#include "Machine.h"

using namespace std;

class COperator :
	public CHuman
{
	CMachine *automat;
	vector<double> income;

public:
	
	COperator(CMachine *automat);
	~COperator();
	friend void CMachine::giveChange(int choice, CHuman* client);
	//inline void const showCash() { cout << "Operator's credit: " << cash << endl; };

	void fillCoins();
	void fillTanks();
	void fillCups();
	void takeCoins();
};

