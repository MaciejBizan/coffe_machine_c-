#pragma once
#include "Coffe.h"
#include "Scheduler.h"
#include "Libraries.h"

using namespace std;
void insertCoin(CMachine &automat,CHuman &client, double coin);

//lista f-cji zaprzyjaznionych, ktore nalezy zwrocic do ich klas, jesli sie nie powiedzie
//chcê uzyskaæ: funckja jest setterm dla dwóch klas

void insertCoin(CMachine &automat, CHuman &client, double coin)
{
	for (int i = 0; i < client.cash.size(); i++)
	{
		if (coin == client.cash.at(i))
		{
			
			automat.insertedCoins.push_back(coin);
			
			client.cash.erase(client.cash.begin() + i);
			return;
			
		}
	}
	cout << "No such coin in the pocket\n";
	
}

int main()
{
	CScheduler scheduler;
	scheduler.run();
	
	return 0;
}