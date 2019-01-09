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

using namespace std;
class CMachine;

class CHuman
{
protected:
	vector<double> cash;
public:
	friend class CMachine;
	CHuman();
	~CHuman();

	void showCash()const;
	double const getCash()const;
	friend void insertCoin(CMachine &automat, CHuman &client, double coin);
	
};

