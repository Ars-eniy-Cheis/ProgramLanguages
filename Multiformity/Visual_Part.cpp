#include "Visual_Part.h"
#include "Table.h"
#include "CompTable.h"
#include "CompTableWithPC.h"

#include <iostream>
#include "string"
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

int Visual_Part::Run()
{
	Table* T;
	MENU();
	int n = 1;
	while (n != 0)
	{
		cin >> n;
		switch (n)
		{
		case 1:
		{
			cout << "Enter table" << endl;
			T = new Table;
			T->Enter();
			T->Show();
			cout << "Volume = " << T->CalcVolume() << endl << endl << "Cost of Production: " << endl << Production(T) << "$" << endl;

			MENU();
			break;
		}
		case 2:
		{
			cout << "Enter Comptable" << endl;
			T = new CompTable;
			T->Enter();
			T->Show();
			cout << "CompTAble Volume = " << T->CalcVolume() << endl << endl << "Cost of Production: " << endl << Production(T) << "$" << endl;
			MENU();
			break;
		}
		case 3:
		{
			T = new CompTableWithPC;
			T->Enter();
			T->Show();
			cout << "CompTAble with PC Volume = " << T->CalcVolume() << endl << endl << "Cost of Production: " << endl << Production(T) << "$" << endl;
			MENU();
			break;
		}
		case 0:
		{
			return 0;
		}
		}
	}

}

void Visual_Part::MENU()
{
	cout << "MENU: " << endl << endl << "1. Table" << endl << "2. CompTable" << endl << "3. CompTable with PC" << endl << "0. EXIT" << endl;
}

int Visual_Part::Production(Table* T)
{
	cout << "Enter Sum of production of one cubic meter of table: " << endl << endl;
	float cost;
	cin >> cost;
	return T->CalcVolume() * cost;
}
