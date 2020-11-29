#include "Table.h"

#include <iostream>
#include "string"
#include <string.h>

using namespace std;

Table::Table()
{
	size = 0;
	color = "NONE";
}

Table::Table(int new_size, string new_color)
{
	size = new_size;
	color = new_color;
}

Table::Table(int new_size)
{
	size = new_size;
	color = "NONE";
}

Table::Table(const Table& copy)
{
	size = copy.size;
	color = copy.color;
}

void Table::Show()
{
	cout << "Size: " << size << endl;
	cout << "Color: " << color << endl;
}

void Table::Enter()
{
	cout << "Enter size" << endl;
	cin >> size;
	cout << "Enter color" << endl;
	cin >> color;
}

int Table::CalcVolume()
{
	int V;
	V = size * size * size;
	return V;
}