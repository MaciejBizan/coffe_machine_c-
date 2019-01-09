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

#include "Tank.h"
#include "Coffe.h"
#include "Human.h"

using namespace std;


class CMachine
{
private:
	CTank *waterTank;
	CTank *coffeTank;

	bool drinkInChamberStatus;
	queue<bool> cups;
	vector<double> coins;
	vector<double> insertedCoins;

	vector<Coffe> menu;


	
public:
	CMachine();
	~CMachine();
	friend class COperator;
	//friend class Client;
	//friend class CHuman;
	//friend class CScheduler;
	
	//void operator->(CHuman &client);
	friend void insertCoin(CMachine &automat, CHuman &client, double coin);
	

	
	void loadMenu(string filePath);
	void showMenu() const;
	vector<Coffe>const getMenu() {return menu;};

	void showCoins() const;
	double const getSum()const;
	inline vector<double>const getCoins()const { return coins; };
	void  showInsertedCoins() const;
	double const getInsertedCoins ()const;
	void  showCups()const;
	bool const checkTanks()const;
	bool const checkCups()const;
	
	void prepareDrink();
	
	inline bool const isDrinkInChamber() { return drinkInChamberStatus; };
	void giveChange(int choice, CHuman* client);
	void giveCup();
	bool  isSuchPositionInMenu (int choice) const;
	void takeInsertedCash();
	
	
	
};

