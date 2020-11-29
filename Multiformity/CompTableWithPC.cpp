#include "CompTableWithPC.h"

CompTableWithPC::CompTableWithPC() :CompTable()
{
	power = 0;
	PCsize = 0;
	PCcolor = "NONE";
}

CompTableWithPC::CompTableWithPC(int new_size, string new_color, int new_h, string new_material, float new_power, int new_PCsize, string new_PCcolor) : CompTable(new_size, new_color, new_h, new_material)
{
	power = new_power;
	PCsize = new_PCsize;
	PCcolor = new_PCcolor;
}

void CompTableWithPC::Show()
{
	cout << "CompTAble with PC:" << endl;
	CompTable::Show();
	cout << "Power: " << power << endl;
	cout << "PC size: " << PCsize << endl;
	cout << "PC color: " << PCcolor << endl;
}

void CompTableWithPC::Enter()
{
	CompTable::Enter();
	cout << endl << "Enter PC power: " << endl;
	cin >> power;
	cout << endl << "Enter PC size: " << endl;
	cin >> PCsize;
	cout << endl << "Enter PC color: " << endl;
	cin >> PCcolor;
}

int CompTableWithPC::CalcVolume()
{
	return PCsize * PCsize * PCsize + CompTable::CalcVolume();
}
