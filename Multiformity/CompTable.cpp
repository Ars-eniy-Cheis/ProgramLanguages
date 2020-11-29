#include "CompTable.h"

#include <iostream>
#include "string"
#include <string.h>

using namespace std;

CompTable::CompTable() :Table()
{
	h = 0;
	material = "NONE";
}

CompTable::CompTable(int new_size, string new_color, int new_h, string new_material) : Table(new_size, new_color)
{
	h = new_h;
	material = new_material;
}

void CompTable::Show()
{
	Table::Show();
	cout << "Height: " << h << endl;
	cout << "Material: " << material << endl;
}

void CompTable::Enter()
{
	Table::Enter();
	cout << "Enter height of stand" << endl;
	cin >> h;
	cout << "Enter material" << endl;
	cin >> material;
}

int CompTable::CalcVolume()
{
	return h * h * h + Table::CalcVolume();
}
