#pragma once
#include <iostream>

using namespace std;

class Exceptions
{
private:
	int value;
	string msg;
public:
	Exceptions(int new_value, string new_msg);
	int GetValue();
	const string GetMessage();
};

