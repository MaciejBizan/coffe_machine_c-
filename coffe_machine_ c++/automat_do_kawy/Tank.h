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

class CTank
{
private:
	double temperature;
	double volume;
public:
	friend class CMachine;	//deklaracja przyjazni do latwej modyfikacji volume
	friend class COperator;
	CTank(double temp, double vol);
	~CTank();


	inline double const giveTemperature() { return temperature; };
	inline double const giveVolume() { return volume; };
	inline double const showTemperature() { cout << temperature << endl; };
	inline double const showVolume() { cout << volume << endl; };

};

