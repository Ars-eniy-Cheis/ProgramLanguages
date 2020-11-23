#pragma once
#include "string"
#include <string.h>

using namespace std;

class Table
{
private:

	int size;
	string color;

public:
	Table();
	Table(int new_size, string new_color);
	Table(int new_size);
	Table(const Table& copy);
	void Show();
	void Enter();
	int CalcVolume();

};

