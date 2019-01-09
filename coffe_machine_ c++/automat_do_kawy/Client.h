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
#include "Human.h"
class Client:
	public CHuman
{

public:

	Client();
	~Client();
	friend void CMachine::giveChange(int choice, CHuman* client);
	

};

