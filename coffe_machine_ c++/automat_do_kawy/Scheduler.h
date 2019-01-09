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

#include "Machine.h"
#include "Operator.h"
#include "Client.h"
#include "Error.h"
using namespace std;

class CScheduler
{
private:
	CMachine* automat;
	Client* client;
	COperator* technican;
	
	
public:
	CScheduler();
	~CScheduler();
	void run();

	
};

