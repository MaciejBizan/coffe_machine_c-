#pragma once
#include <string>
#include<iostream>
using namespace std;
class CError
{
private:
	string communicate;

public:
	CError(string communi);
	~CError();
	inline void showCommunicate()const {  cout << communicate << endl; };

};

