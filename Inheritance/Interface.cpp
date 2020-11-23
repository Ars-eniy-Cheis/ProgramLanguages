#include "Interface.h"
#include "Table.h"
#include "CompTable.h"

#include <iostream>
#include "string"
#include <stack>
#include <queue>
#include <string.h>

using namespace std;

int Interface::Run()
{
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
			Table T;
			T.Enter();
			T.Show();
			cout << "Volume = " << T.CalcVolume() << endl;
			MENU();
			break;
		}
		case 2:
		{
			cout << "Enter Comptable" << endl;
			CompTable CT;
			CT.EnterCT();
			CT.ShowCT();
			cout << "CompTAble Volume = " << CT.CalVolumeCT() << endl << endl;
			MENU();
			break;
		}
		case 3:
		{
			CompTableWithPC CTWP;
			Enter_CompTableWithPC(CTWP);
			Show_CompTableWithPC(CTWP);
			cout << "CompTAble with PC Volume = " << CTWP.CalcVolumeCompTableWithPC() << endl << endl;
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

void Interface::MENU()
{
	cout << "MENU: " << endl << endl << "1. Table" << endl << "2. CompTable" << endl << "3. CompTable with PC" << endl << "0. EXIT" << endl;
}

void Interface::Show_CompTableWithPC(CompTableWithPC CTWP)
{
	cout << "CompTAble with PC:" << endl;
	CTWP.ShowCT();
	cout << "Power: " << CTWP.power << endl;
	cout << "PC size: " << CTWP.PCsize << endl;
	cout << "PC color: " << CTWP.PCcolor << endl;
}

void Interface::Enter_CompTableWithPC(CompTableWithPC &CTWP)
{
	CTWP.EnterCT();
	cout << endl << "Enter PC power: " << endl;
	cin >> CTWP.power;
	cout << endl << "Enter PC size: " << endl;
	cin >> CTWP.PCsize;
	cout << endl << "Enter PC color: " << endl;
	cin >> CTWP.PCcolor;
}
