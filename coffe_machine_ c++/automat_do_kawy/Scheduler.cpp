#pragma once
#include "Scheduler.h"

using namespace std;

CScheduler::CScheduler()
{
	
	automat = new CMachine;
	client = new Client;
	technican = new COperator(automat);

}

CScheduler::~CScheduler()
{
	delete automat;
	delete client;
	delete technican;

}

void CScheduler::run()
{
	double coin=0;
	int c = 0;
	bool goodRead = 0;
	double choice = -1;
	bool isOrderingFinished = 0;
	while (!isOrderingFinished)
	{
		automat->showMenu();
		client->showCash();
		cout << "insert coins:\n(-1 when done, 0 to go away)" << endl;

		do {
			cin >> coin;
			while (cin.fail())
			{
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << "insert coins:\n" << endl;
				cin >> coin;
			}
			c = (int)100 * coin;
			try {
				switch (c)
				{
				case 100:
					insertCoin(*automat, *client, 1);
					
					break;
				case 200:
					insertCoin(*automat, *client, 2);
					
					break;
				case 500:
					insertCoin(*automat, *client, 5);
					break;
				case 50:
					insertCoin(*automat, *client, 0.5);
					break;
				case 20:
					insertCoin(*automat, *client, 0.2);
					break;
				case 10:
					insertCoin(*automat, *client, 0.1);
					break;
				case 5:
					insertCoin(*automat, *client, 0.05);
					break;
				case -100:
					break;
				case 0:
					choice = 0;
					break;
				default:
					throw CError("No such Coin");
					break;
				}
				cout << "Inserted: "<<automat->getInsertedCoins()<<endl;
				cout << "insert coins:\n(-1 when done, 0 to go away)" << endl;

			}
			catch (CError error)
			{
				error.showCommunicate();
			}

		} while (coin != -1&&coin!=0);
		if (coin != 0)
		{
			if (automat->checkTanks() == 1 && automat->checkCups() == 1)
			{
				do {
					cout << "what would you like to order?\n" << endl;
					cin >> choice;
					while (cin.fail())
					{
						cin.clear();
						cin.ignore(numeric_limits<streamsize>::max(), '\n');
						cout << "what would you like to order?\n" << endl;
						cin >> choice;
						
					}
					if (choice == 0)
						break;
					//cout << automat->getMenu().at(choice-1).cost;
				} while (!automat->isSuchPositionInMenu(choice) ||((automat->isSuchPositionInMenu(choice))&& (automat->getInsertedCoins()<automat->getMenu().at(choice-1).cost)));
				//sprawdzic gdy wrzuce zlocisza
				if (choice != 0)
				{
					automat->prepareDrink();
				}
				
				automat->giveChange(choice, client);	
				//automat->showInsertedCoins();
			}
			else
			{
				cout << "Not enough supplies\nplease contact the operator\n";
				technican->fillTanks();
				technican->fillCups();
			}
			automat->giveCup();
			cout << "thank you\nhave a nice day\n\n\n\n\ ";
		}
		if (choice == 0)
		{
			automat->giveChange(choice, client);
			
			client->showCash();
			/*automat->showInsertedCoins();*/
			isOrderingFinished = 1;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

		}
		
		
		
		
		
	}
	

}
