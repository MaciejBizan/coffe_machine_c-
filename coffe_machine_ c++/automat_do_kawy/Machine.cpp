#pragma once
#include "Machine.h"
using namespace std;

//PRZECIAZANE OPERATORY
inline void operator +=(vector<double>&a, vector <double>b)
{

	for (int i = 0; i < b.size(); i++)
	{
		a.push_back(b[i]);
	}


}

inline void operator +=(vector<double>&a, double b)
{
	a.push_back(b);
}



CMachine::CMachine()
{
	waterTank = new CTank(20,0.100);
	coffeTank = new CTank(20,0.100);
	drinkInChamberStatus = 0;
	for (int i = 0; i < 100; i++)
	{
		cups.push(1);
	}
	for (int i = 0; i < 100; i++)
	{
		coins += 1;
		coins += 2;
		coins += 5;
		coins += 0.5;
		coins += 0.2;
		coins += 0.01;
		coins += 0.05;
		
		/*coins.push_back(1);
		coins.push_back(2);
		coins.push_back(5);
		coins.push_back(0.5);
		coins.push_back(0.2);
		coins.push_back(0.1);
		coins.push_back(0.05);
		coins.push_back(0.01);
		*/
	}
	loadMenu("menu.txt");
	
	
}

CMachine::~CMachine()
{
	delete waterTank;
	delete coffeTank;
}

void CMachine::loadMenu(string filePath)
{
	filePath = "menu.txt";

	ifstream file;
	stringstream object;
	string line,buffor;
	
	int i = 0;
	file.open(filePath);
	try {
		if (file.fail())
			throw "wrong file path";
		while (file.eof() != 1)
		{
			getline(file, line);
			object << line;
			line.clear();
			do {
				menu.push_back(Coffe());
				object >> buffor;
				object >> line;
				menu[i].cost = stof(line);
				menu[i].type = buffor;
				i++;
				//coffeType.push_back(buffor);
				//fcost.push_back(stof(line));

			} while (!object.eof());
			buffor.clear();
			object.clear();
		}
		file.close();
	}
	catch (string a)
	{
		cout << a;
	}
	
	
}
void CMachine::showMenu()const
{
	
	for (int i = 0; i<menu.size(); i++)
	{
		//cout << setw(20);
		cout << left<< i+1 << left << "." << left << menu[i].type << left;
		
		cout <<internal<<"\t"<< menu[i].cost << endl;
		
	}

}
void CMachine::showCoins()const
{
	int one=0, two=0, five=0, half=0, otwenty=0, oten=0, ofive=0;
	for (int i = 0; i < coins.size(); i++)
	{
		if (coins[i] == 0.05)
			ofive++;
		if (coins[i] == 0.1)
			oten++;
		if (coins[i] == 0.2)
			otwenty++;
		if (coins[i] == 0.5)
			half++;
		if (coins[i] == 1)
			one++;
		if (coins[i] == 2)
			two++;
		if (coins[i] == 5)
			five++;
	}
	cout << "0.05: " << ofive << "\t" << "0.1: " << oten << "\t" << "0.2: " << otwenty << "\t" << "0.5: " << half << "\t" << "1: " << one << "\t" << "2: " << two << "\t" << "5: " << five << endl;
}
double const CMachine::getSum()const
{
	int i = 0;
	double sum = 0;
	while (i < coins.size())
	{
		sum += coins[i];
	}
	return sum;
}


void CMachine::showInsertedCoins()const
{
	int one = 0, two = 0, five = 0, half = 0, otwenty = 0, oten = 0, ofive = 0;
	for (int i = 0; i < insertedCoins.size(); i++)
	{
		
		if (insertedCoins[i] == 0.05)
			ofive++;
		if (insertedCoins[i] == 0.1)
			oten++;
		if (insertedCoins[i] == 0.2)
			otwenty++;
		if (insertedCoins[i] == 0.5)
			half++;
		if (insertedCoins[i] == 1)
			one++;
		if (insertedCoins[i] == 2)
			two++;
		if (insertedCoins[i] == 5)
			five++;
	}
	cout << "0.05: " << ofive << "\t" << "0.1: " << oten << "\t" << "0.2: " << otwenty << "\t" << "0.5: " << half << "\t" << "1: " << one << "\t" << "2: " << two << "\t" << "5: " << five << endl;
}
double const CMachine::getInsertedCoins()const
{
	int i = 0;
	double sum = 0;
	while (i < insertedCoins.size())
	{
		sum += insertedCoins[i];
		i++;
	}
	return sum;
}

void CMachine::showCups()const
{
	int i = 0;
	while (i < cups.size())
	{
		i++;
	}
	cout << "Number of cups: " << i;
	
}

bool const CMachine::checkTanks()const
{
	if (waterTank->giveVolume() >= 0.5&&coffeTank->giveVolume() >= 0.1)
		return 1;
	return 0;
}

bool const CMachine::checkCups()const
{
	if (cups.empty()==1)
		return 0;
	return 1;
}

void CMachine::prepareDrink()
{
	cups.pop();
	waterTank->temperature = 100;
	waterTank->volume -= 0.5;
	coffeTank->volume -= 0.1;
	drinkInChamberStatus = 1;
}
void CMachine::giveChange(int choice, CHuman* client)
{
	double difference = 0;
	
			if (choice==0 || getInsertedCoins() >= getMenu().at(choice - 1).cost)
			{
				if (choice == 0)
					difference = getInsertedCoins();
				else
					difference = getInsertedCoins() - getMenu().at(choice - 1).cost;

				while (difference > 0.01)
				{

					if (difference >= 5)
					{
						for (int i = 0; i < getCoins().size(); i++)
						{
							if (coins.at(i) == 5)
							{

								client->cash.push_back(coins.at(i));
								coins.erase(coins.begin() + i);
								difference -= 5;
								break;

							}
						}
					}
					else if (difference < 5 && difference >= 2)
					{
						for (int i = 0; i < getCoins().size(); i++)
						{
							if (coins.at(i) == 2)
							{

								client->cash.push_back(coins.at(i));
								coins.erase(coins.begin() + i);
								difference -= 2;
								break;

							}
						}
					}
					else if (difference < 2 && difference >= 1)
					{
						for (int i = 0; i < getCoins().size(); i++)
						{
							if (coins.at(i) == 1)
							{

								client->cash.push_back(coins.at(i));
								coins.erase(coins.begin() + i);
								difference -= 1;
								break;

							}
						}
					}
					else if (difference < 1 && difference >= 0.5)
					{
						for (int i = 0; i < getCoins().size(); i++)
						{
							if (coins.at(i) == 0.5)
							{

								client->cash.push_back(coins.at(i));
								coins.erase(coins.begin() + i);
								difference -= 0.5;
								break;

							}
						}
					}
					else if (difference < 0.5 && difference >= 0.2)
					{
						for (int i = 0; i < getCoins().size(); i++)
						{
							if (coins.at(i) == 0.2)
							{

								client->cash.push_back(coins.at(i));
								coins.erase(coins.begin() + i);
								difference -= 0.2;
								break;

							}
						}
					}
					else if (difference < 0.2 && difference >= 0.1)
					{
						for (int i = 0; i < getCoins().size(); i++)
						{
							if (coins.at(i) == 0.1)
							{

								client->cash.push_back(coins.at(i));
								coins.erase(coins.begin() + i);
								difference -= 0.1;
								break;

							}
						}
					}
					else if (difference < 0.1 && difference >= 0.05)
					{
						for (int i = 0; i < getCoins().size(); i++)
						{
							if (coins.at(i) == 0.05)
							{

								client->cash.push_back(coins.at(i));
								coins.erase(coins.begin() + i);
								difference -= 0.05;
								break;

							}
						}
					}
					else if (difference < 0.05 && difference >= 0.01)
					{
						for (int i = 0; i < getCoins().size(); i++)
						{
							if (coins.at(i) == 0.05)
							{

								client->cash.push_back(coins.at(i));
								coins.erase(coins.begin() + i);
								difference -= 0.05;
								break;

							}
						}
					}



					/*if (difference != 0)
					{
					cout << "can not give change; please contact the operator\n";
					}*/

				}
			}
			coins += insertedCoins;
			insertedCoins.clear();
		
		

	
	

}
void CMachine::giveCup()
{

	drinkInChamberStatus = 0;

}

bool CMachine:: isSuchPositionInMenu (int choice) const
{
	
	if ((choice ) <=menu.size())
		return 1;
	
	cout << "exceeding menu size\n";
	return 0;
}

/*void CMachine::takeInsertedCash()
{
	for (int i = 0; i < insertedCoins.size(); i++)
	{
		coins.push_back(insertedCoins[i]);
	}
	for (int i = 0; i < insertedCoins.size(); i++)
	{
		insertedCoins.pop_back();
	}
	coins = coins + insertedCoins;
}*/

